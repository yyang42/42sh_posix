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

#ifndef STRING_LITERAL_H
# define STRING_LITERAL_H

# include "basics.h"

# include "ast/anode/anode.h"

typedef struct		s_string_literal
{
	t_atype			type;
	char			*text;
}					t_string_literal;

t_string_literal	*string_literal_new(char *text);
void				string_literal_del(t_string_literal *this);

#endif
