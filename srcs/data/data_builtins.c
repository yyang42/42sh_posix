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
#include "builtin/cmds/builtin_alias.h"
#include "builtin/cmds/builtin_bg.h"
#include "builtin/cmds/builtin_break.h"
#include "builtin/cmds/builtin_cd.h"
#include "builtin/cmds/builtin_colon.h"
#include "builtin/cmds/builtin_command.h"
#include "builtin/cmds/builtin_continue.h"
#include "builtin/cmds/builtin_dirs.h"
#include "builtin/cmds/builtin_dot.h"
#include "builtin/cmds/builtin_echo.h"
#include "builtin/cmds/builtin_env.h"
#include "builtin/cmds/builtin_eval.h"
#include "builtin/cmds/builtin_exec.h"
#include "builtin/cmds/builtin_exit.h"
#include "builtin/cmds/builtin_export.h"
#include "builtin/cmds/builtin_false.h"
#include "builtin/cmds/builtin_fg.h"
#include "builtin/cmds/builtin_getopts.h"
#include "builtin/cmds/builtin_history.h"
#include "builtin/cmds/builtin_jobs.h"
#include "builtin/cmds/builtin_kill.h"
#include "builtin/cmds/builtin_popd.h"
#include "builtin/cmds/builtin_pushd.h"
#include "builtin/cmds/builtin_pwd.h"
#include "builtin/cmds/builtin_read.h"
#include "builtin/cmds/builtin_readonly.h"
#include "builtin/cmds/builtin_return.h"
#include "builtin/cmds/builtin_set.h"
#include "builtin/cmds/builtin_setenv.h"
#include "builtin/cmds/builtin_shift.h"
#include "builtin/cmds/builtin_times.h"
#include "builtin/cmds/builtin_trap.h"
#include "builtin/cmds/builtin_true.h"
#include "builtin/cmds/builtin_umask.h"
#include "builtin/cmds/builtin_unset.h"
#include "builtin/cmds/builtin_wait.h"

#include "data.h"

static void			push_data01(t_lst *b)
{
	twl_lst_push_front(b, builtin_new(".",
				builtin_dot_exec, BUILTIN_FLAG_SPECIAL_BUILTIN));
	twl_lst_push_front(b, builtin_new(":",
				builtin_colon_exec, BUILTIN_FLAG_SPECIAL_BUILTIN));
	twl_lst_push_front(b, builtin_new("alias", builtin_alias_exec, 0));
	twl_lst_push_front(b, builtin_new("bg", builtin_bg_exec, 0));
	twl_lst_push_front(b, builtin_new("break",
				builtin_break_exec, BUILTIN_FLAG_SPECIAL_BUILTIN));
	twl_lst_push_front(b, builtin_new("cd", builtin_cd_exec, 0));
	twl_lst_push_front(b, builtin_new("command", builtin_command_exec, 0));
	twl_lst_push_front(b, builtin_new("continue",
				builtin_continue_exec, BUILTIN_FLAG_SPECIAL_BUILTIN));
	twl_lst_push_front(b, builtin_new("dirs", builtin_dirs_exec, 0));
	twl_lst_push_front(b, builtin_new("echo", builtin_echo_exec, 0));
	twl_lst_push_front(b, builtin_new("env", builtin_env_exec, 0));
	twl_lst_push_front(b, builtin_new("eval",
				builtin_eval_exec, BUILTIN_FLAG_SPECIAL_BUILTIN));
	twl_lst_push_front(b, builtin_new("exec",
				builtin_exec_exec, BUILTIN_FLAG_SPECIAL_BUILTIN));
	twl_lst_push_front(b, builtin_new("exit",
				builtin_exit_exec, BUILTIN_FLAG_SPECIAL_BUILTIN));
	twl_lst_push_front(b, builtin_new("export",
				builtin_export_exec, BUILTIN_FLAG_SPECIAL_BUILTIN));
	twl_lst_push_front(b, builtin_new("false", builtin_false_exec, 0));
	twl_lst_push_front(b, builtin_new("fg", builtin_fg_exec, 0));
}

static void			push_data02(t_lst *b)
{
	twl_lst_push_front(b, builtin_new("getopts", builtin_getopts_exec, 0));
	twl_lst_push_front(b, builtin_new("history", builtin_history_exec, 0));
	twl_lst_push_front(b, builtin_new("jobs", builtin_jobs_exec, 0));
	twl_lst_push_front(b, builtin_new("kill", builtin_kill_exec, 0));
	twl_lst_push_front(b, builtin_new("popd", builtin_popd_exec, 0));
	twl_lst_push_front(b, builtin_new("pushd", builtin_pushd_exec, 0));
	twl_lst_push_front(b, builtin_new("pwd", builtin_pwd_exec, 0));
	twl_lst_push_front(b, builtin_new("read", builtin_read_exec, 0));
	twl_lst_push_front(b, builtin_new("readonly",
				builtin_readonly_exec, BUILTIN_FLAG_SPECIAL_BUILTIN));
	twl_lst_push_front(b, builtin_new("return",
				builtin_return_exec, BUILTIN_FLAG_SPECIAL_BUILTIN));
	twl_lst_push_front(b, builtin_new("set",
				builtin_set_exec, BUILTIN_FLAG_SPECIAL_BUILTIN));
	twl_lst_push_front(b, builtin_new("setenv", builtin_setenv_exec, 0));
	twl_lst_push_front(b, builtin_new("shift",
				builtin_shift_exec, BUILTIN_FLAG_SPECIAL_BUILTIN));
	twl_lst_push_front(b, builtin_new("times",
				builtin_times_exec, BUILTIN_FLAG_SPECIAL_BUILTIN));
	twl_lst_push_front(b, builtin_new("trap",
				builtin_trap_exec, BUILTIN_FLAG_SPECIAL_BUILTIN));
	twl_lst_push_front(b, builtin_new("true", builtin_true_exec, 0));
	twl_lst_push_front(b, builtin_new("umask", builtin_umask_exec, 0));
	twl_lst_push_front(b, builtin_new("unset",
				builtin_unset_exec, BUILTIN_FLAG_SPECIAL_BUILTIN));
}

static void			push_data03(t_lst *b)
{
	twl_lst_push_front(b, builtin_new("unsetenv", builtin_unsetenv_exec, 0));
	twl_lst_push_front(b, builtin_new("wait", builtin_wait_exec, 0));
}

t_lst				*data_builtins(void)
{
	static t_lst *builtins;

	if (builtins == NULL)
	{
		builtins = twl_lst_new();
		push_data01(builtins);
		push_data02(builtins);
		push_data03(builtins);
	}
	return (builtins);
}
