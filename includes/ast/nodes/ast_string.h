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

#ifndef AST_STRING_H
# define AST_STRING_H

# include "basics.h"

# include "ast/ast_defines.h"
# include "ast/nodes/ast_node.h"

typedef struct		s_ast_string
{
	t_ast_type		type;
	char			*text;
}					t_ast_string;

t_ast_string		*ast_string_new(char *text);
void				ast_string_del(t_ast_string *this);

#endif
