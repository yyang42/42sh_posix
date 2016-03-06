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

#ifndef TOKEN_TYPE_ITEM_MGR_H
# define TOKEN_TYPE_ITEM_MGR_H

# include "basics.h"
# include "token/token_type_item.h"

t_lst				*token_type_item_mgr_new(void);
void				token_type_item_mgr_del(t_lst *token_type_items);
void				token_type_item_mgr_add(t_lst *token_type_items,
											char *text, t_token_type type);
void				token_type_item_mgr_remove(t_lst *token_type_items,
											t_token_type_item *token_type_item);
void				token_type_item_mgr_print(t_lst *token_type_items);

t_token_type_item	*token_type_item_mgr_get_by_text(t_lst *token_type_items,
																	char *text);
t_token_type_item	*token_type_item_mgr_get_by_type(t_lst *token_type_items,
															t_token_type type);

#endif
