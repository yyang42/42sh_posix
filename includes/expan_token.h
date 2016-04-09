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

#ifndef EXPAN_TOKEN_H
# define EXPAN_TOKEN_H

# include "basics.h"
# include "expan/expan_token_type.h"

typedef struct			s_expan_token
{
	t_expan_token_type	type;
	char				*text;
}						t_expan_token;

t_expan_token			*expan_token_new(t_expan_token_type type, char *text);
void					expan_token_del(t_expan_token *this);

#endif
