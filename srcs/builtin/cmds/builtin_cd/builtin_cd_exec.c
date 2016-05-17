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

//static char	*get_dirname_from_arg(t_lst *remainders, t_shenv *this)
//{
//	static char	buf[MAX_SIZE];
//	char		*dirname;
//	char		*new_name;
//
//	dirname = NULL;
//	twl_bzero(buf, MAX_SIZE);
//	dirname = twl_strdup(twl_lst_get(remainders, 0));
//	if (!dirname || *dirname == '\0')
//		return (NULL);
//	if (dirname[0] != '/' && twl_strncmp(dirname, "..", 2) != 0)
//	{
//		new_name = builtin_cd_get_path(dirname, this);
//		free(dirname);
//		return (new_name);
//	}
//	return (dirname);
//}
//
//static int	get_dirname(char **dirname, t_lst *remainders, t_shenv *this)
//{
//	char	*tmp;
//
//	if (twl_lst_len(remainders) >= 1 && twl_strequ(twl_lst_first(remainders), "-"))
//	{
//		tmp = shenv_shvars_get_value(this, "OLDPWD");
//		if (tmp == NULL)
//		{
//			shenv_singl_error(EXIT_FAILURE, "cd: OLDPWD not set");
//			return (-1);
//		}
//		*dirname = twl_strdup(tmp);
//		twl_printf("%s\n", *dirname);
//		return (1);
//	}
//	else if (twl_lst_len(remainders) == 0)
//	{
//		tmp = shenv_shvars_get_value(this, "HOME");
//		if (tmp == NULL || *tmp == '\0')
//		{
//			shenv_singl_error(EXIT_FAILURE, "cd: HOME not set");
//			return (-1);
//		}
//		*dirname = twl_strdup(tmp);
//		return (1);
//	}
//	return (0);
//}
//
//static bool			should_follow_symlinks(t_lst *tokens)
//{
//	t_lst			*tokens_copy;
//	bool			follow_symlinks;
//	t_token			*token;
//	char			*arg;
//
//	follow_symlinks = true;
//	tokens_copy = twl_lst_copy(tokens, NULL);
//	twl_lst_pop_front(tokens_copy);
//	while ((token = twl_lst_pop_front(tokens_copy)))
//	{
//		if (*token->text != '-' || twl_strequ(token->text, "--"))
//		{
//			break ;
//		}
//		else
//		{
//			arg = token->text;
//			arg++;
//			while (*arg)
//			{
//				if (*arg == 'P')
//					follow_symlinks = false;
//				else if (*arg == 'L')
//					follow_symlinks = true;
//				arg++;
//			}
//		}
//	}
//	twl_lst_del(tokens_copy, NULL);
//	return (follow_symlinks);
//}
//
//static void			builtin_cd_exec_exec(t_argparser_result	*argparser_result, int follow_symlinks, t_shenv *this)
//{
//	char				*dirname;
//	char				*old_dirname;
//	char				*original_path;
//
//	dirname = NULL;
//	if (get_dirname(&dirname, argparser_result->remainders, this) < 0)
//	{
//		return ;
//	}
//	else if (!dirname)
//	{
//		if (!(dirname = get_dirname_from_arg(argparser_result->remainders, this)))
//		{
//			return ;
//		}
//	}
//	if (twl_lst_len(argparser_result->remainders) > 0)
//		original_path = twl_lst_first(argparser_result->remainders);
//	else
//		original_path = dirname;
//	if (dirname && dirname[0] != '/' && follow_symlinks && (old_dirname = dirname))
//	{
//		dirname = join_pwd_to_path(dirname);
//		free(old_dirname);
//	}
//	builtin_cd_exec_do(dirname, original_path, follow_symlinks, this);
//}

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
		twl_printf("%s\n", builtin_cd_make_path_from_dir(twl_lst_first(argparser_result->remainders)));
		//builtin_cd_exec_exec(argparser_result, should_follow_symlinks(tokens), env);
	}
}
