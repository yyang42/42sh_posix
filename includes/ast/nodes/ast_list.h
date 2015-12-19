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

#ifndef AST_LIST_H
# define AST_LIST_H

# include "twl_lst.h"

# include "basics.h"

# include "parser.h"
# include "utils.h"

# include "ast/ast_defines.h"
# include "ast/nodes/ast_node.h"

typedef struct		s_ast_list
{
	t_ast_type		type;
	t_lst			*andors;
	t_parser		*parser;
	int				index;
}					t_ast_list;

t_ast_list			*ast_list_new(void);
void				ast_list_del(t_ast_list *this);

t_ast_list			*ast_list_build(char *str, int *len_ptr);
t_ast_list			*ast_list_build2(t_parser *parser);
void				ast_list_str_append(t_ast_list *this, t_lst *lines,
																int *depth);

#endif
