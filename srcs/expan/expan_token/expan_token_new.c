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

#include "expan/expan_token.h"

t_expan_token *expan_token_new(t_expan_type type, t_token *src_token)
{
	t_expan_token *token;

	token = twl_malloc_x0(sizeof(t_expan_token));
	token->src_token = src_token;
	token->type = type;
	token->res = NULL;
	token->exec_expan = NULL;
	token->free_expan = NULL;
	token->is_double_quoted = false;
	token->expan_data = NULL;
	return (token);
}
