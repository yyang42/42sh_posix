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

t_lst				*token_mgr_split_by_one_sep(t_lst *tokens, char *sep)
{
	t_lst			*sep_list;
	t_lst			*result;

	sep_list = twl_lst_new();
	twl_lst_push(sep_list, twl_strdup(sep));
	result = token_mgr_split(tokens, sep_list);
	twl_lst_del(sep_list, free);
	return (result);
}
