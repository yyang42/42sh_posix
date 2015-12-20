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

#ifndef AST_PIPE_H
# define AST_PIPE_H

# include "basics.h"

# include "parser.h"
# include "utils.h"

# include "ast/ast_defines.h"
# include "ast/nodes/ast_node.h"

typedef struct		s_ast_pipe_seq
{
	t_ast_type		type;
	void			*left;
	void			*right;
	t_lst			*pipes;
	int				index;
}					t_ast_pipe_seq;

t_ast_pipe_seq			*ast_pipe_seq_new(void);
void				ast_pipe_seq_del(t_ast_pipe_seq *this);

#endif
