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

char				*prog_run_file_to_str(t_prog *prog, char *file)
{
	char			*input;

	shenv_set_name(shenv_singleton(), file);
	input = twl_file_to_str(file);
	if (!input)
	{
		shenv_singl_error_simple(1, "%s: No such file or directory", file);
		exit(1);
	}
	return (input);
	(void)prog;
}
