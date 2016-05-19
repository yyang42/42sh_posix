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
#include "shenv/shenv.h"
#include "twl_xstring.h"
#include "openclose/openclose_matcher.h"

void				tokenizer_remove_line_continuation(t_tokenizer *t)
{
	tokenizer_utils_remove_line_continuation(t->curtoken);
	tokenizer_utils_remove_line_continuation(t->curtokenplus);
}
