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

#ifndef ARGPARSER_EXTENSION_H
# define ARGPARSER_EXTENSION_H

# include "basics.h"
# include "twl_argparser/argparser.h"

t_argparser_result	*argparser_parse_tokens(t_argparser *this, t_lst *ast_tokens);
void				argparser_result_print_usage_exit_status(t_argparser_result *argparser_result, int exit_status);

#endif
