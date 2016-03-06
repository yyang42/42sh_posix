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

#ifndef BUILTIN_READONLY_H
# define BUILTIN_READONLY_H

# include "basics.h"
# include "twl_opt.h"
# include "builtin/builtin.h"

# define READONLY_OPT_VALID_OPTS "p"

void				builtin_readonly_exec(t_lst *tokens, t_shenv *env);
void				builtin_readonly_verbose(t_shenv *env);
void				builtin_readonly_add(t_shenv *env, t_opt *opt);

#endif
