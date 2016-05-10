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

#ifndef BUILTIN_PUSHD_H
# define BUILTIN_PUSHD_H

# include "basics.h"
# include "twl_opt.h"
# include "argparser_extension.h"
# include "shenv/shenv.h"
# include "builtin/builtin.h"
# include "builtin/cmds/builtin_dirs.h"

t_argparser				*builtin_pushd_argparser(void);

void					builtin_pushd_exec(t_lst *tokens, t_shenv *shenv);
void					builtin_pushd(t_builtin_dirs *this);
void					builtin_pushd_without_cd(t_builtin_dirs *this);

#endif
