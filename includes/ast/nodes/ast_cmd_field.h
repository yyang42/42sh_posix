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

#ifndef AST_CMD_FIELD_H
# define AST_CMD_FIELD_H

# include "basics.h"

# include "ast/nodes/ast_node.h"
# include "ast/nodes/ast_string.h"
# include "ast/nodes/ast_cmd_sub.h"

typedef struct		s_ast_cmd_field
{
	t_ast_type		type;
	void			*items;
}					t_ast_cmd_field;

t_ast_cmd_field		*ast_cmd_field_new(void);
void				ast_cmd_field_del(t_ast_cmd_field *this);

t_ast_cmd_field		*ast_cmd_field_build(char *str, int *len_ptr);

#endif
