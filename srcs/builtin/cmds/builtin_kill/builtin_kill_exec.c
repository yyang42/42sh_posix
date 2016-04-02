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
#include "logger.h"
#include "data.h"
#include "shsignal/shsignal_mgr.h"
#include "job_control/job_mgr.h"

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

static t_job		*get_job_by_id(char *job_id_str)
{
	if (*job_id_str != '%')
		return (NULL);
	job_id_str++;
	return (job_mgr_find_by_job_id(shenv_singleton()->jobs, job_id_str));
}


static void			iter_pids_fn(void *token_, void *signum_ptr)
{
	int				signum;
	t_token			*token;
	int				pid;
	t_job			*job;

	signum = *(int *)signum_ptr;
	token = token_;
	if ((job = get_job_by_id(token->text)))
	{
		pid = -1 * job->pid;
		builtin_kill_update_job(job, signum);
	}
	else if (twl_str_is_num(token->text))
	{
		pid = twl_atoi(token->text);
		if (kill(pid, 0) == -1)
		{
			shenv_print_error_printf(shenv_singleton(), token->line,
				"kill: (%s) - No such process", token->text);
			shenv_singleton()->last_exit_code = EXIT_FAILURE;
			return ;
		}
	}
	else
	{
		shenv_print_error_printf(shenv_singleton(), token->line,
			"kill: %s: arguments must be process or job IDs", token->text);
		shenv_singleton()->last_exit_code = EXIT_FAILURE;
		return ;
	}
	if (job_mgr_find_by_pid(shenv_singleton()->jobs, pid))
		pid = - pid;
	LOGGER_INFO("kill: %s(%d), pid=%d",
		shsignal_mgr_get_signame(data_signals(), signum), signum, pid);
	if (kill(pid, signum) == -1)
		perror("kill");
}

static void			builtin_kill_exec_sigstr(char *sigstr, t_lst *tokens_copy,
	t_token *first_token, t_shenv *env)
{
	int				signum;

	signum = job_utils_get_signum(sigstr);
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
		else if (!twl_strequ(token_mgr_first(tokens_copy)->text, "--")
			&& twl_str_starts_with(token_mgr_first(tokens_copy)->text, "-"))
		{
			sigstr = token_mgr_first(tokens_copy)->text + 1;
			twl_lst_pop_front(tokens_copy);
		}
		else
		{
			sigstr = "TERM";
		}
		if (token_mgr_first(tokens_copy)
			&& twl_strequ(token_mgr_first(tokens_copy)->text, "--"))
			twl_lst_pop_front(tokens_copy);
		if (sigstr)
		{
			builtin_kill_exec_sigstr(sigstr, tokens_copy, twl_lst_first(tokens), env);
		}
	}
}
