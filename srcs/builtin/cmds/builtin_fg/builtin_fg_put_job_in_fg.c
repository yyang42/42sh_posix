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

#include "builtin/cmds/builtin_fg.h"
#include "shsignal/shsignal_mgr.h"
#include "data.h"
#include <sys/wait.h>

char * strerror(int errnum);

static void         put_in_fg(t_job *job, t_token *cmd_token)
{
    t_shenv         *env;
    bool            cont;

    cont = true;

    env = shenv_singleton();
    /* Put the job into the foreground.  */
    tcsetpgrp (env->jc_terminal, job->pid);
    /* Send the job a continue signal, if necessary.  */

    twl_printf("%s\n", job->cmd_str);
    LOGGER("fg: continue pid=%d", job->pid);

    if (job->job_status == JOB_STOPPED)
    {

        // tcsetattr (env->jc_terminal, TCSADRAIN, &job->tmodes);
        if (kill (-job->pid, SIGCONT) < 0)
            twl_dprintf (2, "kill (SIGCONT)");
    }
    pid_t pid = waitpid (job->pid, NULL, WUNTRACED);
    if (pid == -1 && errno != ECHILD)
    {
        shenv_print_error_printf(shenv_singleton(), cmd_token->line,
            "fg: %s", strerror(errno));
    }
    /* Put the shell back in the foreground.  */
    tcsetpgrp (env->jc_terminal, env->jc_pgid);

    /* Restore the shell’s terminal modes.  */
    tcgetattr (env->jc_terminal, &job->tmodes);
    tcsetattr (env->jc_terminal, TCSADRAIN, &env->jc_tmodes);
}

void                builtin_fg_put_job_in_fg(t_job *job, t_token *cmd_token)
{
    if (job_has_terminated(job))
    {
        shenv_print_error_printf(shenv_singleton(), cmd_token->line,
            "fg: job has terminated");
    }
    else
    {
        put_in_fg(job, cmd_token);
    }
    job_mgr_remove(shenv_singleton()->jobs, job);
}
