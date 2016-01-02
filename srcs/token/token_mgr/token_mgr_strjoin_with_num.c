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

static void			print_token_fn(void *token_, void *segs)
{
	t_token	*token;
	char			*str;

	token = token_;
	twl_asprintf(&str, "%s(%d:%d)", token->text, token->line, token->col);
	twl_lst_push(segs, str);
}

char				*token_mgr_strjoin_with_num(t_lst *tokens)
{
	t_lst			*segs;
	char			*final_str;

	segs = twl_lst_new();
	twl_lst_iter(tokens, print_token_fn, segs);
	final_str = twl_lst_strjoin(segs, "_");
	twl_lst_del(segs, free);
	return (final_str);
}
