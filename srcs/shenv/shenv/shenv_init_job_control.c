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

#include "shenv/shenv.h"
#include "logger.h"
#include "utils.h"
#include "data.h"
#include "shsignal/shsignal_mgr.h"

static void     intercept_logger_handler(int sig)
{
  LOGGER("INTERACTIVE: Ignore signal %s(%d)", shsignal_mgr_get_signame(data_signals(), sig), sig);
  (void)sig;
}

void				shenv_init_job_control(t_shenv *this)
{
  /* See if we are running interactively.  */
  this->jc_terminal = STDIN_FILENO;
  // this->jc_is_interactive = isatty(this->jc_terminal);
  // twl_printf("this->jc_is_interactive %d\n", this->jc_is_interactive);
  if (this->is_interactive_shell)
    {
      LOGGER("Init job control");
      /* Loop until we are in the foreground.  */
      while (tcgetpgrp (this->jc_terminal) != (this->jc_pgid = getpgrp ()))
        kill (- this->jc_pgid, SIGTTIN);

      /* Ignore interactive and job-control signals.  */
      //// disable_all_signals();
      signal (SIGINT, intercept_logger_handler);
      signal (SIGQUIT, intercept_logger_handler);
      signal (SIGTSTP, intercept_logger_handler);
      signal (SIGTTIN, intercept_logger_handler);
      signal (SIGTTOU, intercept_logger_handler);
      signal (SIGCHLD, intercept_logger_handler);

      /* Put ourselves in our own process group.  */
      this->jc_pgid = getpid ();
      if (setpgid (this->jc_pgid, this->jc_pgid) < 0)
        {
          twl_dprintf(2, "error: Couldn't put the shell in its own process group");
          exit (1);
        }
      /* Grab control of the terminal.  */
      tcsetpgrp (this->jc_terminal, this->jc_pgid);

      /* Save default terminal attributes for shell.  */
      tcgetattr (this->jc_terminal, &this->jc_tmodes);
    }
}
