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

static void	iter_fn(void *str, void *new_list, void *orig_token)
{
	t_token		*new_token;

	new_token = token_copy(orig_token);
	token_set_text(new_token, str);
	twl_lst_push_back(new_list, new_token);
}

t_lst		*token_mgr_new_from_string_list(t_token *orig_token, t_lst *str_lst)
{
	t_lst		*new_list;

	new_list = twl_lst_new();
	twl_lst_iter2(str_lst, iter_fn, new_list, orig_token);
	return (new_list);
}
