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

#ifndef EXPANSION_H
# define EXPANSION_H

# include "basics.h"
# include "token/token.h"
# include "expan/expan_tokenizer.h"
//# include "expan/expan_execute.h"

typedef struct		s_expansion
{
	t_lst			*split;
	char			*error;
}					t_expansion;

t_expansion			*expansion_new(void);
void				expansion_del(t_expansion *this);

t_expansion			*expansion_new_from_token(t_token *to_expand);
//void				expansion_tilde(t_expansion *this);

#endif
