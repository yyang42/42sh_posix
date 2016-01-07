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

#ifndef UNSET_H
# define UNSET_H

# include "basics.h"
# include "twl_opt.h"
# include "environment.h"
# include "builtin.h"

# define UNSET_OPT_VALID_OPTS "fv"

int					unset(char *str, t_environment *env);
int					unset_variable(t_environment *env, t_opt *opt);
int					unset_function(t_environment *env, t_opt *opt);

#endif
