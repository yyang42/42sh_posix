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
# include "shenv/shenv.h"
# include "builtin/builtin.h"
# include "argparser_extension.h"

void				builtin_unset_exec(t_lst *tokens, t_shenv *env);
int					builtin_unset_variable(t_shenv *env, t_lst *remainders);
int					builtin_unset_function(t_shenv *env, t_lst *remainders);
void				builtin_unsetenv_exec(t_lst *tokens, t_shenv *env);
t_argparser			*builtin_unset_argparser(void);
t_argparser			*builtin_unsetenv_argparser(void);

#endif
