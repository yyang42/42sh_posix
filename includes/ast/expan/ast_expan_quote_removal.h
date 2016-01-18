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

#ifndef AST_EXPAN_QUOTE_REMOVAL_H
# define AST_EXPAN_QUOTE_REMOVAL_H

#include "basics.h"

typedef struct			s_expan_quote_removal
{
	char				*str;
	int					i;
	bool				is_single_quoted;
	bool				is_double_quoted;
	bool				is_backslashed;
}						t_expan_quote_removal;

#endif
