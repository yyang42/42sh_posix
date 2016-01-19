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

#ifndef AST_LAP_H
# define AST_LAP_H

# include "basics.h"

# include "token/token_mgr.h"
# include "ast/ast_defines.h"
# include "ast/ast_utils.h"
# include "ast/ast.h"

t_lst				*ast_lap_build_items(t_lst *tokens, t_ast_type type, struct s_ast *ast);

typedef void *(*t_ast_lap_new_from_tokens_fn)(t_lst *tokens, struct s_ast *ast);
typedef void (*t_ast_lap_set_separator_fn)(void *item, t_token *token);

#endif
