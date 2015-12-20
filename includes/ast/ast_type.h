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

#ifndef AST_TYPE_H
# define AST_TYPE_H

typedef enum		e_ast_type
{
	AST_ANDOR_SEQ,
	AST_CMD,
	AST_CMD_FIELD,
	AST_CMD_SUB,
	AST_CMD_SUBSHELL,
	AST_SIMPLE_CMD,
	AST_LIST,
	AST_IF,
	AST_PIPE,
	AST_STRING
}					t_ast_type;

#endif
