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

#include "builtin/cmds/builtin_bg.h"

void				builtin_bg_invalid_opt_print_usage(char *opt, t_token *token)
{
	shenv_print_error_printf(shenv_singleton(), token->line,
		"bg: -%c: invalid option", *opt);
	twl_dprintf(2, "bg: usage: bg [job_spec]");
}
