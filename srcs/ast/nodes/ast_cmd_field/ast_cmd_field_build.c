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

	ast_cmd_field = ast_cmd_field_new();
	twl_lst_push(ast_cmd_field->items, ast_string_new(str));
	increment_len(len_ptr, twl_strlen(str));
	return (ast_cmd_field);
}
