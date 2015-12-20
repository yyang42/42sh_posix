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

#ifndef AST_CMD_SIMPLE_H
# define AST_CMD_SIMPLE_H

# include "twl_lst.h"

# include "basics.h"

# include "ast/ast_defines.h"
# include "ast/nodes/ast_node.h"
# include "ast/nodes/ast_list.h"

typedef struct		s_ast_cmd_simple
{
	t_ast_type		type;
	int				index;
}					t_ast_cmd_simple;

t_ast_cmd_simple	*ast_cmd_simple_new(void);
void				ast_cmd_simple_del(t_ast_cmd_simple *this);

#endif
