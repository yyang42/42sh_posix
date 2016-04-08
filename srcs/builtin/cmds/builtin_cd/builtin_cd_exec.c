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

#include "builtin/cmds/builtin_cd.h"

static char	*get_dirname_from_arg(t_lst *remainders, t_shenv *this)
{
	static char	buf[MAX_SIZE];
	char		*dirname;
	char		*new_name;

	dirname = NULL;
	twl_bzero(buf, MAX_SIZE);
	dirname = twl_strdup(twl_lst_get(remainders, 0));
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

static int	get_dirname(char **dirname, t_lst *remainders, t_shenv *this)
{
	char	*tmp;

	if (twl_lst_len(remainders) >= 1 && twl_strequ(twl_lst_first(remainders), "-"))
	{
		tmp = shenv_shvars_get_value(this, "OLDPWD");
		if (tmp == NULL)
		{
			shenv_singl_error(EXIT_FAILURE, "cd: OLDPWD not set");
			return (-1);
		}
		*dirname = twl_strdup(tmp);
		twl_printf("%s\n", *dirname);
		return (1);
	}
	else if (twl_lst_len(remainders) == 0)
	{
		tmp = shenv_shvars_get_value(this, "HOME");
		if (tmp == NULL || *tmp == '\0')
		{
			shenv_singl_error(EXIT_FAILURE, "cd: HOME not set");
			return (-1);
		}
		*dirname = twl_strdup(tmp);
		return (1);
	}
	return (0);
}

void				builtin_cd_exec_old(t_argparser_result	*argparser_result, t_shenv *this)
{
	int					no_symlinks;
	char				*dirname;
	char				*old_dirname;

	dirname = NULL;
	no_symlinks = 0;
	if (argparser_result_opt_is_set(argparser_result, "P"))
		no_symlinks = 1;
	if (argparser_result_opt_is_set(argparser_result, "L"))
		no_symlinks = 0;
	if (get_dirname(&dirname, argparser_result->remainders, this) < 0)
	{
		return ;
	}
	else if (!dirname)
	{
		if (!(dirname = get_dirname_from_arg(argparser_result->remainders, this)))
		{
			return ;
		}
	}
	if (dirname && dirname[0] != '/' && !no_symlinks && (old_dirname = dirname))
	{
		dirname = join_pwd_to_path(dirname);
		free(old_dirname);
	}
	builtin_cd_exec_do(dirname, no_symlinks, this);
}

void				builtin_cd_exec(t_lst *tokens, t_shenv *env)
{
	t_argparser_result	*argparser_result;

	argparser_result = argparser_parse_tokens(builtin_cd_argparser(), tokens);
	if (argparser_result->err_msg)
	{
		argparser_result_print_error_with_help(argparser_result);
		env->last_exit_code = EXIT_FAILURE;
	}
	else
	{
		builtin_cd_exec_old(argparser_result, env);
	}
}
