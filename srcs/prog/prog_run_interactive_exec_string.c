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

#include "prog.h"
#include "ast/ast.h"

void				prog_run_interactive_exec_string(t_prog *prog, char *input)
{
	struct sigaction	sa_new;
	struct sigaction	sa_old;

	twl_memset(&sa_new, 0, sizeof(sa_new));
	sigemptyset(&sa_new.sa_mask);
	sa_new.sa_handler = SIG_DFL;
	if (sigaction(SIGTSTP, &sa_new, &sa_old) != 0)
		LOG_ERROR("sigaction: %s", strerror(errno));
	ast_utils_exec_string(input, 1);
	if (sigaction(SIGTSTP, &sa_old, NULL) != 0)
		LOG_ERROR("sigaction: %s", strerror(errno));
	(void)prog;
}
