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

#ifndef AST_SIMPLE_COMMAND_EXPAN_H
# define AST_SIMPLE_COMMAND_EXPAN_H

void		ast_simple_command_expan_tilde(t_token *token);
void		ast_simple_command_expan_parameter(t_token *token);
bool		is_double_quoted(char *str);
bool		isSingleQuoted(char *str);

void		ast_simple_command_expan_parameter(t_token *token);
void		ast_simple_command_expan_unenclose_parameter(t_token *token, int i);
void		ast_simple_command_expan_enclose_parameter(t_token *token, int i);
void		ast_simple_command_expan_star(t_token *token, int i);
void		ast_simple_command_expan_sharp(t_token *token, int i);
void		ast_simple_command_expan_hyphen(t_token *token, int i);
void		ast_simple_command_expan_zero(t_token *token, int i);
void		ast_simple_command_expan_question(t_token *token, int i);
void		ast_simple_command_expan_at(t_token *token, int i);
void		ast_simple_command_expan_exclamation(t_token *token, int i);
void		ast_simple_command_expan_dollar(t_token *token, int i);

#endif
