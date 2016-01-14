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
	AT,
	DOLLAR,
	QUESTION,
	EXCLAMATION,
	HYPHEN,
	ZERO,
	SHARP,
	STAR
}						t_expan_param_type;

typedef struct			s_expan_param
{
	t_expan_param_type	type;
	bool				isDoubleQuoted;
	char				*token;
	char				*result;
}						t_expan_param;

t_expan_param			*expan_param_new(void);
void					expan_param_del(t_expan_param *expan_param);

#endif
