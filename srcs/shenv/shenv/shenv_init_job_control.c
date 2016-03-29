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

#include "data.h"
#include "job_control/job.h"
#include "logger.h"
#include "shenv/shenv.h"
#include "shsignal/shsignal_mgr.h"
#include "utils.h"

void                shenv_init_job_control(t_shenv *this)
{
    this->jc_terminal = STDIN_FILENO;
    if (this->is_interactive_shell)
    {
        LOGGER_INFO("Init job control");
        while (tcgetpgrp (this->jc_terminal) != (this->jc_pgid = getpgrp ()))
        {
            kill (- this->jc_pgid, SIGTTIN);
        }
        job_utils_sigs_ignore_on_interactive();
        this->jc_pgid = getpid ();
        if (setpgid (this->jc_pgid, this->jc_pgid) < 0)
        {
            twl_dprintf(2, "error: Couldn't put the shell in its own process group");
            exit (1);
        }
        tcsetpgrp (this->jc_terminal, this->jc_pgid);
        tcgetattr (this->jc_terminal, &this->jc_tmodes);
    }
}
