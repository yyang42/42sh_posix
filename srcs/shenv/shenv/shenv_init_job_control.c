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

      job_utils_sigs_ignore_on_interactive();

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
