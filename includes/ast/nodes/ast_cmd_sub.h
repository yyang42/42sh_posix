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

#ifndef AST_CMD_SUB_H
# define AST_CMD_SUB_H

# include "basics.h"

# include "ast/nodes/ast_node.h"
# include "ast/nodes/ast_string.h"

typedef struct		s_ast_cmd_sub
{
	t_ast_type		type;
	void			*items;
}					t_ast_cmd_sub;

t_ast_cmd_sub		*ast_cmd_sub_new(void);
void				ast_cmd_sub_del(t_ast_cmd_sub *this);

t_ast_cmd_sub		*ast_cmd_sub_build(char *str, int *len_ptr);

#endif
