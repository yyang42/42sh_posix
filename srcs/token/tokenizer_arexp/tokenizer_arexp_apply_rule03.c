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

#include "token/tokenizer.h"
#include "token/token_mgr.h"

t_rule_status		tokenizer_arexp_apply_rule03(t_tokenizer *t)
{
	if (tokenizer_arexp_utils_can_form_operator(t, t->curtoken)
		&& !tokenizer_arexp_utils_can_form_operator(t, t->curtokenplus))
	{
		tokenizer_arexp_delimit(t);
		return (RULE_STATUS_APPLIED);
	}
	return (RULE_STATUS_NOT_APPLIED);
}
