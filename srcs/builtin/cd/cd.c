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

#include "cd.h"

static void	get_flags(t_opt *opt, int *no_symlinks, int *xattrflag)
{
	if (twl_opt_exist(opt, "P"))
		*no_symlinks = 1;
	if (twl_opt_exist(opt, "L"))
		*no_symlinks = 0;
	if (twl_opt_exist(opt, "@"))
		*xattrflag = 1;
}

static int	get_dirname(char **dirname, t_opt *opt, char *str)
{
	t_environment		*this;

	this = environment_singleton();
	if (twl_opt_args_len(opt) == 0)
	{
		*dirname = environment_getenv_value(this, "HOME");
		if (*dirname == NULL)
		{
			twl_dprintf(2, "%s: HOME not set\n", str);
			return (-1);
		}
		return (1);
	}
	else if (twl_strcmp(twl_opt_args_get(opt, 0), "-") == 0)
	{
		*dirname = environment_getenv_value(this, "OLDPWD");
		if (*dirname == NULL)
		{
			twl_dprintf(2, "%s: OLDPWD not set\n", str);
			return (-1);
		}
		return (1);
	}
	return (0);
}

static void	execute_cd(char *dirname, int no_symlinks, int xattrflag)
{
	(void)dirname;
	(void)no_symlinks;
	(void)xattrflag;
}

void 		cd(char *str)
{
	int					no_symlinks;
	t_opt				*opt;
	char				**args;
	int					xattrflag;
	char				*dirname;

	if (!str || *str == '\0')
		return ;
	dirname = NULL;
	xattrflag = 0;
	no_symlinks = 0;
	args = twl_strsplit_mul(str, " \t");
	opt = twl_opt_new(args, "LP@");
	if (!check_invalid_opts(opt, "cd", "LP@"))
		return ;
	get_flags(opt, &no_symlinks, &xattrflag);
	if (get_dirname(&dirname, opt, str) < 0)
		return ;
	else if (!dirname)
		dirname = twl_opt_args_get(opt, 0);
	execute_cd(dirname, no_symlinks, xattrflag);
}
