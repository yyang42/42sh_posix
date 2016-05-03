/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_norris_loves_the_norminette.h                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuck <chuck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2042/02/30 42:00:00 by chuck             #+#    #+#             */
/*   Updated: 2042/02/30 41:59:59 by chuck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRACE_TOKEN_H
# define BRACE_TOKEN_H

# include "basics.h"

typedef struct			s_brace_token
{
	char				*input;
	bool				to_expand;
}						t_brace_token;

t_brace_token			*brace_token_new(char *input, bool to_expand);
void					brace_token_del(t_brace_token *this);

#endif
