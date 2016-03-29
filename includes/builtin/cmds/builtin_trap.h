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

#ifndef BUILTIN_TRAP_H
# define BUILTIN_TRAP_H

# include "basics.h"
# include "twl_opt.h"
# include "argparser_extension.h"
# include "builtin/builtin.h"


void				builtin_trap_exec(t_lst *tokens, t_shenv *env);
void				builtin_trap_print(t_shenv *env);

t_argparser			*builtin_trap_argparser(void);

#endif
