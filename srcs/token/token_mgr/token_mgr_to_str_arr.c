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

char				**token_mgr_to_str_arr(t_lst *tokens)
{
	t_lst			*segs;
	char			**arr;

	segs = token_mgr_to_lst(tokens);
	arr = (char **)twl_lst_to_arr(segs);
	twl_lst_del(segs, NULL);
	return (arr);
}
