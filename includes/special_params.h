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

#ifndef SPECIAL_PARAMS
# define SPECIAL_PARAMS

char				*test_params_at(t_environment *env);
char				*params_at(t_environment *env);
char				*test_params_star(t_environment *env, bool between_quotes);
char				*params_star(t_environment *env, bool between_quotes);

#endif
