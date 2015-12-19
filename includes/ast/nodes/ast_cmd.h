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

#ifndef AST_CMD_H
# define AST_CMD_H

# include "twl_lst.h"

# include "basics.h"

# include "ast/ast_defines.h"
# include "ast/nodes/ast_node.h"

typedef struct		s_ast_cmd
{
	t_ast_type		type;
	t_lst			*strings;
	t_lst			*redir_in;
	t_lst			*redir_out;
	t_lst			*redir_append;
	t_lst			*redir_heredoc;
	t_lst			*cmds;
	int				index;
}					t_ast_cmd;

t_ast_cmd			*ast_cmd_new(void);
void				ast_cmd_del(t_ast_cmd *this);

t_ast_cmd			*ast_cmd_build(char *str, int *len_ptr);

void				ast_cmd_append_str(t_ast_cmd *this,
													int lvl, t_lst *out_list);

#endif
