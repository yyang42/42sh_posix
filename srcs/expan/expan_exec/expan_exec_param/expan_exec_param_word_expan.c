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
#include "expan/expan_exec.h"
#include "expan/expan_mgr.h"

char			*expan_exec_param_word_expan(t_expan_token *expan_token, char *word)
{
	char *tmp;

	if (word)
	{
		tmp = twl_strdup(word);
		expan_init(expan_token->src_token, &tmp, tmp, TOKEN_ORIGIN_PARAM_SUBSTITUTION);
	}
	else
		tmp = twl_strdup("");
	return (tmp);
}