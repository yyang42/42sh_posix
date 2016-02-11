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
# include "expan/expan_type.h"
# include "expan/expan_param.h"

void				*expan_param_type_to_func_dict(t_expan_param_type type);
void				*expan_param_type_to_print_func(t_expan_type type);
t_expan_param_type	string_1_to_expan_parameter_type(char *str);
t_expan_param_type	string_2_to_expan_parameter_type(char *str);
int					expan_tokenizer_get_word_len(char **res, char *str,
	char *delimiter);
t_expan_param_type	char_to_special_param_type(char c);
#endif
