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
#include "ast/anode/pipeline.h"
#include "ast/anode/cmd_stmt.h"
#include "ast/anode/string_literal.h"

void				pipeline_build_rec(t_pipeline *pipeline, t_lst *segs)
{
	char			*last_seg;

	if (twl_lst_len(segs) == 2)
	{
		pipeline->left = cmd_stmt_build(twl_lst_get(segs, 0), NULL);;
		pipeline->right = cmd_stmt_build(twl_lst_get(segs, 1), NULL);;
	}
	else
	{
		last_seg = twl_lst_pop(segs);
		pipeline->left = pipeline_new();
		pipeline_build_rec(pipeline->left, segs);
		pipeline->right = cmd_stmt_build(last_seg, NULL);;
		free(last_seg);
	}
	(void)pipeline;
}

t_pipeline			*pipeline_build(char *str, int *len_ptr)
{
	t_lst			*segs;
	t_pipeline		*pipeline;

	pipeline = pipeline_new();
	segs = twl_str_split_to_lst(str, "|");
	pipeline_build_rec(pipeline, segs);
	twl_lst_del(segs, free);
	increment_len(len_ptr, twl_strlen(str));
	return (pipeline);
}
