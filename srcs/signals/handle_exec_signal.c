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

#include "shsignal/shsignal.h"
#include "shenv/shenv.h"
#include "utils.h"
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>

#define SIG_EXIT_CODE_MIN 128

static const char	*g_strsignal_list[] =
{
	"Unknown signal",
	"Hangup",
	"Interrupt",
	"Quit",
	"Illegal instruction",
	"Trace/BPT trap",
	"Abort trap",
	"EMT trap",
	"Floating point exception",
	"Killed",
	"Bus error",
	"Segmentation fault",
	"Bad system call",
	"Broken pipe",
	"Alarm clock",
	"Terminated",
	"Urgent I/O condition",
	"Suspended (signal)",
	"Suspended",
	"Continued",
	"Child exited",
	"Stopped (tty input)",
	"Stopped (tty output)",
	"I/O possible",
	"Cputime limit exceeded",
	"Filesize limit exceeded",
	"Virtual timer expired",
	"Profiling timer expired",
	"Window size changes",
	"Information request",
	"User defined signal 1",
	"User defined signal 2",
	NULL
};
static char			g_strsignal_ret[1024];

static char			*get_signal(int sig)
{
	if (sig < 0 || sig > 32 || g_strsignal_list[sig] == NULL)
		twl_sprintf(g_strsignal_ret, "Unknown signal: %i%c", sig, 0);
	else
		twl_sprintf(g_strsignal_ret, "%s: %i%c", g_strsignal_list[sig], sig, 0);
	return (g_strsignal_ret);
}

static int			get_exit_code(int sig)
{
	return (SIG_EXIT_CODE_MIN + sig);
}

static void			print_error_msg(int sig)
{
	char		*msg;

	msg = get_signal(sig);
	if (!msg)
	{
		LOG_ERROR("strsignal: %s", twl_strerror(errno));
	}
	else
	{
		if (shenv_is_interactive(shenv_singleton()))
			twl_dprintf(2, "%s\n", msg);
		else
			shenv_singl_error(get_exit_code(sig), "%s", msg);
	}
}

void				handle_exec_signal(int sig)
{
	shenv_singleton()->last_exit_code = get_exit_code(sig);
	if (sig == SIGINT)
	{
		LOG_INFO("SIGINT received");
		shenv_singleton()->shenv_shall_quit_curr_ast = true;
		shenv_singleton()->last_exit_code = get_exit_code(sig);
		if (shenv_is_interactive(shenv_singleton()))
		{
			twl_putchar_fd('\n', 2);
		}
		else
		{
			shenv_utils_exit(get_exit_code(sig));
		}
	}
	else
	{
		print_error_msg(sig);
	}
}
