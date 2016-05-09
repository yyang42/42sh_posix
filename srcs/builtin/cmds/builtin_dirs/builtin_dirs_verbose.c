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

#include "builtin/cmds/builtin_dirs.h"

static void		bd_error(t_builtin_dirs *this, t_lst *dirs, size_t len)
{
	if (len == 0)
		shenv_singl_error(1, "dirs: directory stack empty");
	else
		shenv_singl_error(1, "%i: dirs: directory stack index out of range",
				this->number);
	free(twl_lst_pop_front(dirs));
}

static void		iter_fn(void *data, int index, void *ctx)
{
	twl_printf("%2i  ", index);
	(((t_builtin_dirs *)ctx)->print_fn)(data, ((t_builtin_dirs *)ctx)->shenv);
	twl_putstr("\n");
}

static void		print_verbose(t_builtin_dirs *this, t_lst *dirs, size_t len)
{
	int			index;

	if (this->is_negative)
	{
		index = len - (int)this->number;
		twl_printf("%2i  ", index);
		this->print_fn(twl_lst_get(dirs, index), this->shenv);
	}
	else
	{
		twl_printf("%2i  ", this->number);
		this->print_fn(twl_lst_get(dirs, this->number), this->shenv);
	}
	twl_putstr("\n");
}

void			builtin_dirs_verbose(t_builtin_dirs *this)
{
	t_lst		*dirs;
	size_t		len;

	dirs = builtin_dirs_singleton();
	len = twl_lst_len(dirs);
	if (!builtin_dirs_init_cwd())
		return ;
	if (this->is_number_set)
	{
		if (this->number > len)
		{
			bd_error(this, dirs, len);
			return ;
		}
		print_verbose(this, dirs, len);
	}
	else
		twl_lst_iteri(dirs, iter_fn, this);
	free(twl_lst_pop_front(dirs));
}
