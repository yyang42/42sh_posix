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

#include <stdlib.h>

#include "utils.h"
#include "ast/nodes/ast_cmd_field.h"

t_ast_cmd_field	*ast_cmd_field_build(char *str, int *len_ptr)
{
	t_ast_cmd_field	*ast_cmd_field;
	t_lst			*segs;
	char			*new_str;

	new_str = twl_strtrim_chars(str, "\"");
	ast_cmd_field = ast_cmd_field_new();
	if (twl_strstr(new_str, "`"))
	{
		segs = twl_str_split_to_lst(new_str, "`");
		twl_lst_push(ast_cmd_field->items, ast_string_new(twl_lst_get(segs, 0)));
		twl_lst_push(ast_cmd_field->items, ast_cmd_sub_build(twl_lst_get(segs, 1), NULL));
		twl_lst_push(ast_cmd_field->items, ast_string_new(twl_lst_get(segs, 2)));
		twl_lst_del(segs, free);
	}
	else
	{
		twl_lst_push(ast_cmd_field->items, ast_string_new(str));
	}
	free(new_str);
	increment_len(len_ptr, twl_strlen(str));
	return (ast_cmd_field);
}
