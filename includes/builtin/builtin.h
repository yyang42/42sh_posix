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

#ifndef BUILTIN_H
# define BUILTIN_H

# include "twl_arr.h"
# include "twl_opt.h"
# include "twl_stdio.h"
# include "environment.h"
# include "builtin/cd.h"
# include "builtin/echo.h"
# include "builtin/env.h"
# include "builtin/export.h"
# include "builtin/set.h"
# include "builtin/unset.h"
# include "builtin/alias.h"
# include "builtin/umask.h"
# include "builtin/times.h"
# include "builtin/eval.h"
# include "builtin/dot.h"
# include "builtin/readonly.h"
# include "builtin/shift.h"
# include "builtin/exit.h"
# include "ast/nodes/ast_simple_command.h"

# define BUILTIN_EXEC_SUCCESS 0
# define BUILTIN_EXEC_FAILURE 1

int				check_invalid_opts(t_opt *opt, char *exe_name, char *flags);
bool			builtin_true(char *str, t_environment *env);
bool			builtin_false(char *str, t_environment *env);

#endif
