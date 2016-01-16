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

#ifndef AST_EXPAN_PARAM_H
# define AST_EXPAN_PARAM_H

#include "basics.h"

typedef enum			e_expan_param_type
{
	UNDEFINED_PARAM,
	COLON_HYPHEN,
	HYPHEN,
	COLON_EQUAL,
	EQUAL,
	COLON_QUESTION,
	QUESTION,
	COLON_PLUS,
	PLUS,
	SHARP_PREFIX,
	PERCENT,
	PERCENT_PERCENT,
	SHARP,
	SHARP_SHARP,
	S_AT,
	S_DOLLAR,
	S_QUESTION,
	S_EXCLAMATION,
	S_HYPHEN,
	S_ZERO,
	S_SHARP,
	S_STAR,
	EXPAN_VAR
}						t_expan_param_type;

typedef struct			s_expan_param
{
	t_expan_param_type	type;
	char				*parameter;
	char				*word;
}						t_expan_param;

t_expan_param			*expan_param_new(void);
void					expan_param_del(t_expan_param *expan_param);
void					expan_param_print(t_expan_param *expan_param);

#endif
