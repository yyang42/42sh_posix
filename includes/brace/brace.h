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

#ifndef BRACE_H
# define BRACE_H

# include "basics.h"
# include "token/token.h"

typedef struct		s_brace
{
	
}					t_brace;

t_brace				*brace_new(void);
void				brace_del(t_brace *this);

t_lst				*brace_expand(char *input);
t_lst				*brace_expand_from_tokens(t_token *token);

#endif
