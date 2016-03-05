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

#ifndef EXPAN_EXEC_H
# define EXPAN_EXEC_H

# include "expan/expan_token.h"
# include "basics.h"
# include "environment.h"
# define CMD_SUB_FILE ".42sh_subcmd"

void			expan_exec(t_lst *expan_tokens, bool *should_exec);
bool			expan_exec_param_star(t_expan_token *expan_token);
bool			expan_exec_param_zero(t_expan_token *expan_token);
bool			expan_exec_param_at(t_expan_token *expan_token);
bool			expan_exec_param_dollar(t_expan_token *expan_token);
bool			expan_exec_param_hyphen(t_expan_token *expan_token);
bool			expan_exec_param_sharp(t_expan_token *expan_token);
bool			expan_exec_param_exclamation(t_expan_token *expan_token);
bool			expan_exec_param_question(t_expan_token *expan_token);
bool			expan_exec_param_var(t_expan_token *expan_token);
bool			expan_exec_tilde(t_expan_token *expan_token);
bool			expan_exec_command(t_expan_token *expan_token);
bool			expan_exec_params_colon_hyphen(t_expan_token *expan_token);
bool			expan_exec_params_colon_equal(t_expan_token *expan_token);
bool			expan_exec_pattern_matching(t_expan_token *token);
bool			expan_exec_params_colon_question(t_expan_token *expan_token);
bool			expan_exec_params_question2(t_expan_token *expan_token);
bool			expan_exec_params_hyphen2(t_expan_token *expan_token);
bool			expan_exec_params_equal(t_expan_token *expan_token);
bool			expan_exec_params_colon_plus(t_expan_token *expan_token);
bool			expan_exec_params_plus(t_expan_token *expan_token);
bool			expan_exec_params_percent(t_expan_token *expan_token);
bool			expan_exec_params_percent_percent(t_expan_token *expan_token);
bool			expan_exec_params_sharp_sharp(t_expan_token *expan_token);
bool			expan_exec_params_sharp2(t_expan_token *expan_token);
char			*expan_exec_param_word_expan(char *word);

char			*test_params_zero(t_shenv *env);
char			*params_zero();
char			*test_params_at(t_shenv *env);
char			*params_at();
char			*test_params_star(t_shenv *env, bool between_quotes);
char			*params_star(bool between_quotes);
char			*test_params_sharp(t_shenv *env);
char			*params_sharp();
char			*test_params_question(t_shenv *env);
char			*params_question();
char			*test_params_hyphen(t_shenv *env);
char			*params_hyphen();
char			*test_params_dollar(t_shenv *env);
char			*params_dollar();
char			*test_params_hyphen(t_shenv *env);
char			*params_hyphen();
char			*test_params_exclamation(t_shenv *env);
char			*params_exclamation();

#endif
