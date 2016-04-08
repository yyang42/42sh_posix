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

#include "argparser_extension.h"
#include "token/token_mgr.h"
#include "shenv/shenv.h"

void				argparser_result_print_usage_exit_status(t_argparser_result *argparser_result, int exit_status)
{
	argparser_result_print_error_with_help(argparser_result);
	shenv_singleton()->last_exit_code = exit_status;
}
