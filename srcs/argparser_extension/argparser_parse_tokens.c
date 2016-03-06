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

t_argparser_result	*argparser_parse_tokens(t_argparser *this, t_lst *ast_tokens)
{
	t_argparser_result	*result;
	t_lst				*str_tokens;

	str_tokens = token_mgr_to_lst(ast_tokens);
	result = argparser_parse(this, str_tokens);
	twl_lst_del(str_tokens, NULL);
	return (result);
}
