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
#include "twl_logger.h"
#include "data.h"
#include "shsignal/shsignal_mgr.h"
#include "job_control/job_mgr.h"

static char			*get_sigstr_from_minus_s_opt(t_lst *tokens)
{
	char			*sigstr;
	t_token			*first;

	sigstr = NULL;
	first = twl_lst_pop_front(tokens);
	(void)first;
	if (twl_lst_len(tokens) == 0)
	{
		shenv_singl_error(EXIT_FAILURE,
			"kill: -s: option requires an argument");
		return (NULL);
	}
	else
	{
		sigstr = token_mgr_first(tokens)->text;
		twl_lst_pop_front(tokens);
	}
	return (sigstr);
}

static void			builtin_kill_exec_sigstr(char *sigstr,
					t_lst *tokens_copy, t_shenv *env)
{
	int				signum;

	if (!sigstr)
	{
		twl_lst_del(tokens_copy, NULL);
		return ;
	}
	signum = job_utils_get_signum(sigstr);
	if (signum == -1)
	{
		shenv_singl_error(EXIT_FAILURE,
			"kill: %s: invalid signal specification", sigstr);
	}
	else
	{
		if (twl_lst_len(tokens_copy) == 0)
		{
			builtin_kill_print_usage();
			env->last_exit_code = EXIT_FAILURE;
		}
		else
			twl_lst_iter(tokens_copy, builtin_kill_iter_pids_fn, &signum);
	}
	twl_lst_del(tokens_copy, NULL);
}

t_lst				*builtin_kill_exec_init(t_lst *tokens, t_shenv *env)
{
	t_lst			*tokens_copy;

	tokens_copy = twl_lst_copy(tokens, NULL);
	twl_lst_pop_front(tokens_copy);
	if (twl_lst_len(tokens_copy) == 0)
	{
		builtin_kill_print_usage();
		env->last_exit_code = EXIT_FAILURE;
		twl_lst_del(tokens_copy, NULL);
		return (NULL);
	}
	return (tokens_copy);
}

void				builtin_kill_exec(t_lst *tokens, t_shenv *env)
{
	t_lst			*tokens_copy;
	char			*sigstr;

	if (!(tokens_copy = builtin_kill_exec_init(tokens, env)))
		return ;
	if (token_mgr_first_equ(tokens_copy, "-l"))
	{
		builtin_kill_print_signals();
		twl_lst_del(tokens_copy, NULL);
		return ;
	}
	if (token_mgr_first_equ(tokens_copy, "-s"))
		sigstr = get_sigstr_from_minus_s_opt(tokens_copy);
	else if (!twl_strequ(token_mgr_first(tokens_copy)->text, "--")
			&& twl_str_starts_with(token_mgr_first(tokens_copy)->text, "-"))
	{
		sigstr = token_mgr_first(tokens_copy)->text + 1;
		twl_lst_pop_front(tokens_copy);
	}
	else
		sigstr = "TERM";
	if (token_mgr_first(tokens_copy)
			&& twl_strequ(token_mgr_first(tokens_copy)->text, "--"))
		twl_lst_pop_front(tokens_copy);
	builtin_kill_exec_sigstr(sigstr, tokens_copy, env);
}
