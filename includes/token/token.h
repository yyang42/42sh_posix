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

#ifndef TOKEN_H
# define TOKEN_H

# include "basics.h"

# include "token/token_type.h"

typedef struct		s_token
{
	t_token_type	type;
	char			*text;
	int				line;
	int				col;
	char			*heredoc_text;
}					t_token;

t_token				*token_new(char *text, int line, int col);
void				token_del(t_token *this);

t_token				*token_arexp(char *text);

bool				token_is_control_operators_nl(t_token *this);
bool				token_is_reserved_word(t_token *this);

#endif
