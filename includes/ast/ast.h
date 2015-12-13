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

#ifndef AST_H
# define AST_H

# include "basics.h"

# include "ast/ast_defines.h"
# include "ast/anode/compound_stmt.h"
# include "ast/anode/ast_if.h"
# include "ast/anode/ast_cmd.h"
# include "ast/anode/string_literal.h"
# include "ast/anode/anode.h"

typedef struct		s_ast
{
	char			*raw;
	t_compound_stmt	*root;
}					t_ast;

t_ast				*ast_new(char *input);
void				ast_del(t_ast *this);

char				*ast_to_str(t_ast *this);
void				ast_build(t_ast *this);

#endif
