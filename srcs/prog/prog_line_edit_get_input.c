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
#include "job_control/job_mgr.h"
#include "edit/edit.h"
#include "ast/ast.h"

static bool		is_last_escaped(char *input)
{
	size_t		index;

	index = 0;
	while (input[index])
	{
		if (input[index] == '\\')
		{
			if (input[index + 1] == 0)
				return (true);
			index += 1;
		}
		index += 1;
	}
	return (false);
}

char			*prog_line_edit_get_input(t_prog *prog)
{
	char		*input;
	bool		has_open;

	input = edit_get_line(edit_singleton(), edit_type_ps1);
	has_open = ast_utils_check_has_open(input);
	while (is_last_escaped(input) || has_open)
	{
		free(input);
		input = edit_get_line(edit_singleton(), edit_type_ps2);
		has_open = ast_utils_check_has_open(input);
	}
	return (input);
	(void)prog;
}
