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

#ifndef ANODE_STRING_LITERAL_H
# define ANODE_STRING_LITERAL_H

# include "basics.h"
# include "anode_type.h"

typedef struct				s_anode_string_literal
{
	t_anode_type			type;
	char					*text;
}							t_anode_string_literal;

t_anode_string_literal		*anode_string_literal_new(char *text);
void						anode_string_literal_del(
												t_anode_string_literal *this);

#endif
