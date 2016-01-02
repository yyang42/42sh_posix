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

#ifndef TOKEN_TYPE_ITEM_H
# define TOKEN_TYPE_ITEM_H

# include "basics.h"

# include "token/token_type.h"

typedef struct		s_token_type_item
{
	char			*text;
	t_token_type	type;
}					t_token_type_item;

t_token_type_item	*token_type_item_new(char *text, t_token_type type);
void				token_type_item_del(t_token_type_item *token_type_item);

#endif
