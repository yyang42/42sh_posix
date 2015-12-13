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

#ifndef COMPOUND_STMT_H
# define COMPOUND_STMT_H

# include "twl_lst.h"

# include "basics.h"

# include "ast/nodes/ast_node.h"

typedef struct		s_ast_compound
{
	t_ast_type		type;
	t_lst			*items;
}					t_ast_compound;

t_ast_compound		*ast_compound_new(void);
void				ast_compound_del(t_ast_compound *this);

t_ast_compound		*ast_compound_build(char *str, int *len_ptr);

#endif
