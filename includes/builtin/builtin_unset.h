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

#ifndef BUILTIN_UNSET_H
# define BUILTIN_UNSET_H

# include "basics.h"
# include "twl_opt.h"
# include "environment.h"
# include "builtin/builtin.h"

# define UNSET_OPT_VALID_OPTS "fv"

int					builtin_unset(t_lst *tokens, t_environment *env);
int					unset_variable(t_environment *env, t_opt *opt);
int					unset_function(t_environment *env, t_opt *opt);
int					builtin_unsetenv(t_lst *tokens, t_environment *env);

#endif
