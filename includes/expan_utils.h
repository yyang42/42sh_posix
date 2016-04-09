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

#ifndef EXPAN_UTILS_H
# define EXPAN_UTILS_H

# include "basics.h"

bool				expan_is_special_parameter(char c);
bool				expan_is_begin_of_brace_type(char c);

t_lst				*expan_get_param_spec(char param);
char				*expan_get_param_pos(char *param);
char				*expan_get_param_normal(char *param);

char				*expan_quote(char *param);

char				*expan_get_asterisk_quoted(t_lst *lsast);

#endif
