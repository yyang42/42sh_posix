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

#include "builtin/builtin_cd.h"

static char	*get_dirname_from_arg(t_opt *opt, t_shenv *this)
{
	static char	buf[MAX_SIZE];
	char		*dirname;
	char		*new_name;

	dirname = NULL;
	twl_bzero(buf, MAX_SIZE);
	dirname = twl_strdup(twl_opt_args_get(opt, 0));
	if (!dirname || *dirname == '\0')
		return (NULL);
	if (dirname[0] != '/' && twl_strncmp(dirname, "..", 2) != 0)
	{
		new_name = builtin_cd_get_path(dirname, this);
		free(dirname);
		return (new_name);
	}
	return (dirname);
}

static int	get_dirname(char **dirname, t_opt *opt, t_lst *tokens,
	t_shenv *this)
{
	char	*tmp;

	if (twl_lst_len(tokens) >= 2
		&& twl_strequ(token_mgr_get(tokens, 1)->text, "-"))
	{
		tmp = environment_getenv_value(this, "OLDPWD");
		if (tmp == NULL)
		{
			twl_dprintf(2, "cd: OLDPWD not set\n");
			return (-1);
		}
		*dirname = twl_strdup(tmp);
		twl_printf("%s\n", *dirname);
		return (1);
	}
	else if (twl_opt_args_len(opt) == 0)
	{
		tmp = twl_strdup(environment_getenv_value(this, "HOME"));
		if (tmp == NULL || *tmp == '\0')
		{
			twl_dprintf(2, "cd: HOME not set\n");
			return (-1);
		}
		*dirname = twl_strdup(tmp);
		twl_strdel(&tmp);
		return (1);
	}
	return (0);
}

int					builtin_cd_exec(t_lst *tokens, t_shenv *this)
{
	int					no_symlinks;
	t_opt				*opt;
	char				**args;
	char				*dirname;
	char				*old_dirname;

	dirname = NULL;
	no_symlinks = 0;
	args = token_mgr_to_str_arr(tokens);
	opt = twl_opt_new(args, "LP");
	if (builtin_utils_check_invalid_opts(opt, "cd", "LP"))
		return (builtin_cd_utils_free_all(dirname, args, opt));
	builtin_cd_utils_get_flags(opt, &no_symlinks);
	if (get_dirname(&dirname, opt, tokens, this) < 0)
		return (builtin_cd_utils_free_all(dirname, args, opt));
	else if (!dirname)
		if (!(dirname = get_dirname_from_arg(opt, this)))
			return (builtin_cd_utils_free_all(dirname, args, opt));
	if (dirname && dirname[0] != '/' && !no_symlinks && (old_dirname = dirname))
	{
		dirname = join_pwd_to_path(dirname);
		free(old_dirname);
	}
	builtin_cd_exec_do(dirname, no_symlinks, this);
	return (builtin_cd_utils_free_all(dirname, args, opt));
}
