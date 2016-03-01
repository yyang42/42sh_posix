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

#ifndef READONLY_H
# define READONLY_H

# include "basics.h"
# include "twl_opt.h"
# include "builtin/builtin.h"

# define READONLY_OPT_VALID_OPTS "p"

int					builtin_readonly(t_lst *tokens, t_environment *env);
void				readonly_verbose(t_environment *env);
void				readonly_add(t_environment *env, t_opt *opt);

#endif
