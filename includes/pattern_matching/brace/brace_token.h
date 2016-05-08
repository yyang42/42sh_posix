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
# include "pattern_matching/brace/brace_token_type.h"

typedef struct			s_brace_token
{
	t_brace_token_type	type;
	char				*text;
	t_lst				*brace_list;
}						t_brace_token;

t_brace_token			*brace_token_new(t_brace_token_type type, void *data);
void					brace_token_del(t_brace_token *this);

#endif
