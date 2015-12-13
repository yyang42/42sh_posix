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

#ifndef SPECIAL_PARAMS_H
# define SPECIAL_PARAMS_H

char				*test_params_at(t_environment *env);
char				*params_at();
char				*test_params_star(t_environment *env, bool between_quotes);
char				*params_star(bool between_quotes);
char				*test_params_sharp(t_environment *env);
char				*params_sharp();
char				*test_params_question(t_environment *env);
char				*params_question();
char				*test_params_hyphen(t_environment *env);
char				*params_hyphen(t_environment *env);

#endif
