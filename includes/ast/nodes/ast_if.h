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

#ifndef IF_STMT_H
# define IF_STMT_H

# include "basics.h"

# include "ast/ast_defines.h"
# include "ast/nodes/ast_node.h"
# include "ast/nodes/ast_compound.h"

typedef struct		s_t_ast_if
{
	t_atype			type;
	t_ast_compound	*cond;
	t_ast_compound	*body;
	t_ast_compound	*elze;
}					t_ast_if;

t_ast_if			*ast_if_new(void);
void				ast_if_del(t_ast_if *this);

t_ast_if			*ast_if_build(char *str, int *len_ptr);

#endif
