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

#include "builtin/builtin.h"
#include "builtin/cmds/builtin_kill.h"

static char			*get_sigstr_from_minus_s_opt(t_lst *tokens, t_shenv *env)
{
	char			*sigstr;
	t_token			*first;

	sigstr = NULL;
	first = twl_lst_pop_front(tokens);
	if (twl_lst_len(tokens) == 0)
	{
		shenv_print_error_printf(env, first->line,
			"kill: -s: option requires an argument");
		env->last_exit_code = EXIT_FAILURE;
		return (NULL);
	}
	else
	{
		sigstr = token_mgr_first(tokens)->text;
		twl_lst_pop_front(tokens);
	}
	return (sigstr);
}


static void			iter_pids_fn(void *token_, void *signum_ptr)
{
	int				signum;
	t_token			*token;
	int				pid;

	signum = *(int *)signum_ptr;
	token = token_;
	pid = twl_atoi(token->text);
	kill(pid, signum);
}

static void			builtin_kill_exec_sigstr(char *sigstr, t_lst *tokens_copy,
	t_token *first_token, t_shenv *env)
{
	int				signum;

	signum = builtin_kill_exec_get_signum(sigstr);
	if (signum == -1)
	{
		shenv_print_error_printf(env, first_token->line,
			"kill: %s: invalid signal specification", sigstr);
		env->last_exit_code = EXIT_FAILURE;
	}
	else
	{
		if (twl_lst_len(tokens_copy) == 0)
		{
			builtin_kill_print_usage();
			env->last_exit_code = EXIT_FAILURE;
		}
		else
		{
			twl_lst_iter(tokens_copy, iter_pids_fn, &signum);
		}
	}
}

void				builtin_kill_exec(t_lst *tokens, t_shenv *env)
{
	t_lst			*tokens_copy;
	char			*sigstr;

	tokens_copy = twl_lst_copy(tokens, NULL);
	twl_lst_pop_front(tokens_copy);
	sigstr = NULL;
	env->last_exit_code = EXIT_SUCCESS;
	if (twl_lst_len(tokens_copy) == 0)
	{
		builtin_kill_print_usage();
		env->last_exit_code = EXIT_FAILURE;
	}
	else
	{
		if (token_mgr_first_equ(tokens_copy, "-l"))
		{
			builtin_kill_print_signals();
			return ;
		}
		if (token_mgr_first_equ(tokens_copy, "-s"))
		{
			sigstr = get_sigstr_from_minus_s_opt(tokens_copy, env);
		}
		else if (twl_str_starts_with(token_mgr_first(tokens_copy)->text, "-"))
		{
			sigstr = token_mgr_first(tokens_copy)->text + 1;
			twl_lst_pop_front(tokens_copy);
		}
		if (sigstr)
		{
			builtin_kill_exec_sigstr(sigstr, tokens_copy, twl_lst_first(tokens), env);
		}
	}
}
