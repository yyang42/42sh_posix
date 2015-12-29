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

#include "token_type_item.h"

t_token_type_item			*token_type_item_new(char *text, t_token_type type)
{
	t_token_type_item		*token_type_item;

	token_type_item = twl_malloc_x0(sizeof(t_token_type_item));
	token_type_item->text = twl_strdup(text);
	token_type_item->type = type;
	return (token_type_item);
}
