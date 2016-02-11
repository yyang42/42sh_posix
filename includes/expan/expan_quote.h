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

#ifndef EXPAN_QUOTE_H
# define EXPAN_QUOTE_H

#include "basics.h"

typedef struct			s_expan_quote
{
	char				*str;
	bool				is_single_quoted;
	bool				is_double_quoted;
	bool				is_backslashed;
	bool				is_back_quoted;
}						t_expan_quote;

t_expan_quote			*expan_quote_new();
void					expan_quote_del(void *expan_quote);
#endif
