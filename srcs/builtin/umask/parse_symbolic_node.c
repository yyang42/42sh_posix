/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_norris_loves_the_norminette.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuck <chuck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2042/02/30 42:00:00 by chuck             #+#    #+#             */
/*   Updated: 2042/02/30 41:59:59 by chuck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin/umask.h"

void		agou_loop(t_parse_mask *pm)
{
	while (twl_strpos("agou", *pm->s) > -1 && (pm->c = *pm->s++))
	{
		if (pm->c == 'u')
		{
			pm->who |= S_IRWXU;
			continue ;
		}
		else if (pm->c == 'g')
		{
			pm->who |= S_IRWXG;
			continue ;
		}
		else if (pm->c == 'o')
		{
			pm->who |= S_IRWXO;
			continue ;
		}
		else if (pm->c == 'a')
		{
			pm->who |= S_IRWXU | S_IRWXG | S_IRWXO;
			continue ;
		}
		else
			break ;
	}
}

static void	rwx_loop(t_parse_mask *pm)
{
	while (twl_strpos("rwx", *pm->s) > -1)
	{
		pm->c = *pm->s++;
		if (pm->c == 'r')
		{
			pm->perm |= S_IRUGO;
			break ;
		}
		else if (pm->c == 'w')
		{
			pm->perm |= S_IWUGO;
			break ;
		}
		else if (pm->c == 'x')
		{
			pm->perm |= S_IXUGO;
			break ;
		}
	}
}

static void	parse_symbolic_mode_3(t_parse_mask *pm)
{
	if (pm->who)
		pm->perm &= pm->who;
	if (pm->op == '+')
		pm->bits |= pm->perm;
	else if (pm->op == '-')
		pm->bits &= ~pm->perm;
	else if (pm->op == '=')
	{
		if (pm->who == 0)
		{
			pm->who = S_IRWXU | S_IRWXG | S_IRWXO;
			pm->bits &= ~pm->who;
			pm->bits |= pm->perm;
		}
	}
}

static int	parse_symbolic_mode_2(t_parse_mask *pm)
{
	if (!*pm->s || *pm->s == ',')
	{
		parse_symbolic_mode_3(pm);
		if (*pm->s == 0)
			return (3);
		else
			pm->s++;
	}
	else
	{
		twl_dprintf(2, "%c: invalid symbolic mode character", *pm->s);
		return (false);
	}
	return (2);
}

int			parse_symbolic_mode(char *mode, int initial_bits)
{
	t_parse_mask	pm;
	int				flag;

	pm.s = mode;
	while (true)
	{
		pm.bits = initial_bits;
		pm.who = 0;
		pm.op = 0;
		pm.perm = 0;
		agou_loop(&pm);
		pm.op = *pm.s++;
		if (pm.op != '+' && pm.op != '-' && pm.op != '=')
		{
			twl_dprintf(2, "%c: invalid symbolic mode operator", pm.op);
			return (-1);
		}
		rwx_loop(&pm);
		flag = parse_symbolic_mode_2(&pm);
		if (flag == false)
			return (-1);
		else if (flag == 3)
			break ;
	}
	return (pm.bits);
}
