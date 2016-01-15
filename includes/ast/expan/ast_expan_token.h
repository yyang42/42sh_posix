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

#ifndef AST_EXPAN_TOKEN_H
# define AST_EXPAN_TOKEN_H

# include "basics.h"
# include "token/token.h"
# include "ast/expan/ast_expan_type.h"
# include "ast/expan/ast_expan_token_origin.h"

typedef struct	s_expan_token
{
	t_expan_type	type;
	char			*res;
	void			(*exec_expan)(struct s_expan_token *);
	void			(*free_expan)(void *);
	bool			isDoubleQuoted;
	void			*expan_data;
	t_token_origin	origin;
}				t_expan_token;

t_expan_token					*expan_token_new(t_expan_type type);
void							expan_token_del(t_expan_token *token);
#endif
