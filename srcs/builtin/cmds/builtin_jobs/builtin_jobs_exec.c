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

#include "builtin/cmds/builtin_jobs.h"
#include "shenv/shenv.h"
#include "builtin/builtin.h"
#include "async/job_mgr.h"

static void			builtin_jobs_exec_do(t_argparser_result *argparser_result)
{
	int				flags;

	flags = 0;
	if (argparser_result_opt_is_set(argparser_result, "l"))
		flags |= BUILTIN_JOBS_FLAG_OPT_L;
	else if (argparser_result_opt_is_set(argparser_result, "p"))
		flags |= BUILTIN_JOBS_FLAG_OPT_P;
	builtin_jobs_exec_print(shenv_singleton()->jobs, flags);
	(void)argparser_result;
}

void				builtin_jobs_exec(t_lst *tokens, t_shenv *shenv)
{
	t_argparser_result *argparser_result;

	argparser_result = argparser_parse_tokens(builtin_jobs_argparser(), tokens);
	if (argparser_result->err_msg)
	{
		argparser_result_print_error_with_help(argparser_result);
		shenv->last_exit_code = BUILTIN_EXEC_FAILURE;
	}
	else
	{
		builtin_jobs_exec_do(argparser_result);
	}
	shenv->last_exit_code = BUILTIN_EXEC_SUCCESS;
}
