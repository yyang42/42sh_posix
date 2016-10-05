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

#include "twl_gnl.h"
#include "prog.h"
#include "ast/ast.h"
#include "edit/edit.h"
#include "trap/trap.h"
#include "trap/trap_mgr.h"
#include "job_control/job_mgr.h"
#include <setjmp.h>

char				*prog_get_next_line(t_prog *prog)
{
	char			*remainders;
	char			*line;
	int				has_open;

	remainders = NULL;
	line = edit_get_line_without_termcap(edit_singleton(),
			&remainders, edit_type_ps1);
	has_open = ast_utils_check_has_open(line);
	while (has_open)
	{
		free(line);
		line = edit_get_line_without_termcap(edit_singleton(),
				&remainders, edit_type_ps2);
		has_open = ast_utils_check_has_open(line);
	}
	free(remainders);
	return (line);
	(void)prog;
}
