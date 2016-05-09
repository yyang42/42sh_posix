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

static char			*prog_run_get_input(t_prog *prog)
{
	char			*input;
	t_lst			*remainders;

	input = NULL;
	remainders = prog->argparser_result->remainders;
	if (prog_is_opt_set(prog, "c"))
	{
		LOG_INFO("exec opt -c");
		input = twl_strdup(argparser_result_opt_get_arg(prog->argparser_result, "c"));
	}
	else if (twl_lst_len(remainders) > 0)
	{
		input = prog_run_file_to_str(prog, twl_lst_first(remainders));
	}
	return (input);
}

int					prog_run(t_prog *prog)
{
	char			*input;

	input = prog_run_get_input(prog);
	if (input)
	{
		prog_run_input(prog, input);
	}
	else if (twl_lst_len(prog->argparser_result->remainders) == 0)
	{
		shenv_singleton()->shenv_is_interactive = isatty(0);
		if (shenv_singleton()->shenv_is_interactive)
			prog_run_interactive(prog);
		else
			prog_run_input_from_stdin(prog);
	}
	free(input);
	return (shenv_singleton()->last_exit_code);
}
