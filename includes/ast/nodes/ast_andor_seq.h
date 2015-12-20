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

#ifndef AST_ANDOR_H
# define AST_ANDOR_H

# include "basics.h"

# include "utils.h"
# include "parser.h"

# include "ast/ast_defines.h"
# include "ast/nodes/ast_node.h"

typedef enum		e_andor_type
{
	ANDOR_TYPE_AND,
	ANDOR_TYPE_OR
}					t_andor_type;

typedef struct		s_ast_andor_seq
{
	t_ast_type		type;
	int				index;
	t_andor_type	andor_type;
	void			*left;
	void			*right;
	t_lst			*pipes;
}					t_ast_andor_seq;

t_ast_andor_seq			*ast_andor_seq_new(t_andor_type andor_type);
void				ast_andor_seq_del(t_ast_andor_seq *this);

#endif
