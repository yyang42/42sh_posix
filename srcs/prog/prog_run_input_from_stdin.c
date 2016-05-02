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

void				prog_run_input_from_stdin(t_prog *prog)
{
	char			*input;

	input = twl_fd_to_str(STDIN_FILENO);
	if (!input)
	{
		shenv_singl_error_simple(1, "Can't read from stdin");
		exit(1);
	}
	prog_run_input(prog, input);
	free(input);
}
