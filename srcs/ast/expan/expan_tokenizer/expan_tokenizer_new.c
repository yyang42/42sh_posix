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

#include "basics.h"
#include "ast/expan/ast_expan_tokenizer.h"

t_expan_tokenizer			*expan_tokenizer_new(void)
{
	t_expan_tokenizer	*tokenizer;

	tokenizer = twl_malloc_x0(sizeof(t_expan_tokenizer));
	tokenizer->i = 0;
	tokenizer->last = 0;
	tokenizer->type = NONE;
	tokenizer->is_between_dq = false;
	tokenizer->is_between_sq = false;
	return (tokenizer);
}
