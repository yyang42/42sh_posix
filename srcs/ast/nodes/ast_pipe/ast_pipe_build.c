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

#include "utils.h"

#include "twl_lst.h"
#include "ast/nodes/ast_pipe.h"
#include "ast/nodes/ast_cmd.h"
#include "ast/nodes/ast_string.h"

void				ast_pipe_build_rec(t_ast_pipe *ast_pipe, t_lst *segs)
{
	char			*last_seg;

	if (twl_lst_len(segs) == 2)
	{
		ast_pipe->left = ast_cmd_build(twl_lst_get(segs, 0), NULL);;
		ast_pipe->right = ast_cmd_build(twl_lst_get(segs, 1), NULL);;
	}
	else
	{
		last_seg = twl_lst_pop(segs);
		ast_pipe->left = ast_pipe_new();
		ast_pipe_build_rec(ast_pipe->left, segs);
		ast_pipe->right = ast_cmd_build(last_seg, NULL);;
		free(last_seg);
	}
	(void)ast_pipe;
}

t_ast_pipe			*ast_pipe_build(char *str, int *len_ptr)
{
	t_lst			*segs;
	t_ast_pipe		*ast_pipe;

	ast_pipe = ast_pipe_new();
	segs = twl_str_split_to_lst(str, "|");
	ast_pipe_build_rec(ast_pipe, segs);
	twl_lst_del(segs, free);
	increment_len(len_ptr, twl_strlen(str));
	return (ast_pipe);
}
