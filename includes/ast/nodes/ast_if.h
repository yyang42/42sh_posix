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

#ifndef AST_IF_H
# define AST_IF_H

# include "basics.h"

# include "ast/ast_defines.h"
# include "ast/nodes/ast_node.h"
# include "ast/nodes/ast_list.h"

typedef struct		s_ast_if
{
	t_ast_type		type;
	t_ast_list		*cond;
	t_ast_list		*body;
	t_ast_list		*elze;
}					t_ast_if;

t_ast_if			*ast_if_new(void);
void				ast_if_del(t_ast_if *this);

#endif
