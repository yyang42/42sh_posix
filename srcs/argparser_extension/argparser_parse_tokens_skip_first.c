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

#include "argparser_extension.h"
#include "token/token_mgr.h"

t_argparser_result	*argparser_parse_tokens_skip_first(t_argparser *this, t_lst *ast_tokens)
{
	t_argparser_result	*result;
	t_lst				*tokens_copy;

	tokens_copy = twl_lst_copy(ast_tokens, NULL);
	twl_lst_pop_front(tokens_copy);
	result = argparser_parse_tokens(this, tokens_copy);
	twl_lst_del(tokens_copy, NULL);
	return (result);
}
