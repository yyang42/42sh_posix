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

#include "token/token_mgr.h"
#include "data_utils.h"

bool			token_mgr_arexp_is_assign(t_lst *tokens)
{
	if (twl_lst_len(tokens) < 2)
		return (false);
	return (((t_token *)twl_lst_first(tokens))->type == TOK_AREXP_ENV_VAR &&
			data_utils_arexp_is_assign(((t_token *)twl_lst_get(tokens, 1))->text));
}
