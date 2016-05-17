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

static bool			should_follow_symlinks(t_lst *tokens)
{
	t_lst			*tokens_copy;
	bool			follow_symlinks;
	t_token			*token;
	char			*arg;

	follow_symlinks = true;
	tokens_copy = twl_lst_copy(tokens, NULL);
	twl_lst_pop_front(tokens_copy);
	while ((token = twl_lst_pop_front(tokens_copy)))
	{
		if (*token->text != '-' || twl_strequ(token->text, "--"))
			break ;
		arg = token->text;
		arg++;
		while (*arg)
		{
			if (*arg == 'P')
				follow_symlinks = false;
			else if (*arg == 'L')
				follow_symlinks = true;
			arg++;
		}
	}
	twl_lst_del(tokens_copy, NULL);
	return (follow_symlinks);
}

void				builtin_cd_exec(t_lst *tokens, t_shenv *env)
{
	t_argparser_result	*result;

	result = argparser_parse_tokens(builtin_cd_argparser(), tokens);
	if (result->err_msg)
	{
		argparser_result_print_error_with_help(result);
		env->last_exit_code = EXIT_FAILURE;
	}
	else if (should_follow_symlinks(tokens))
	{
		builtin_cd_follow_symlinks(twl_lst_first(result->remainders));
	}
	else
	{
		builtin_cd_unfollow_symlinks(twl_lst_first(result->remainders));
	}
	argparser_result_del(result);
}
