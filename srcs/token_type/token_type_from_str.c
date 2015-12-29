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

#include "data.h"

#include "token_type_item_mgr.h"

t_token_type		token_type_from_str(char *str)
{
	t_token_type_item	*item;

	item = token_type_item_mgr_get_by_text(data_token_item_list(), str);
	if (!item)
		return (TOKEN_TOKEN);
	return (item->type);
}
