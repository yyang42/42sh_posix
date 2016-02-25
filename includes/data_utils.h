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

#ifndef DATA_UTILS_H
# define DATA_UTILS_H

# include "basics.h"
# include "data.h"

bool				data_utils_is_control_operators(char *str);
bool				data_utils_is_control_operators_nl(char *str);
bool				data_utils_is_reserved_word(char *str);
bool				data_utils_is_reserved_word_middle_end(char *str);

bool				data_utils_arexp_is_assign(char *str);

#endif
