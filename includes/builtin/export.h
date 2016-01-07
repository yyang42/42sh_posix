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

#ifndef EXPORT_H
# define EXPORT_H

# include "basics.h"
# include "twl_opt.h"
# include "builtin.h"

# define EXPORT_OPT_VALID_OPTS "p"

int					export(char *str, t_environment *env);
void				export_verbose(t_environment *env);
void				export_add(t_environment *env, t_opt *opt);
int					setenv_builtin(char *str, t_environment *env);

#endif
