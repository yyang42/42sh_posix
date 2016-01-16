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

#ifndef AST_EXPAN_MGR_H
# define AST_EXPAN_MGR_H

# include "ast/expan/ast_expan_token.h"

void				expan_token_mgr_del(t_lst *tokens);
t_lst				*expan_token_mgr_new(void);
void				expan_token_mgr_add(t_lst *tokens, t_expan_token *token);
void				expan_token_mgr_print(t_lst *tokens);
#endif
