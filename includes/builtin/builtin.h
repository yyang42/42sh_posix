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
# include "builtin/builtin_cd.h"
# include "builtin/builtin_echo.h"
# include "builtin/builtin_env.h"
# include "builtin/builtin_export.h"
# include "builtin/builtin_set.h"
# include "builtin/builtin_unset.h"
# include "builtin/builtin_alias.h"
# include "builtin/builtin_umask.h"
# include "builtin/builtin_times.h"
# include "builtin/builtin_eval.h"
# include "builtin/builtin_dot.h"
# include "builtin/builtin_readonly.h"
# include "builtin/builtin_shift.h"
# include "builtin/builtin_exit.h"
# include "builtin/builtin_jobs.h"

# include "ast/nodes/ast_simple_command.h"

# define BUILTIN_EXEC_SUCCESS 0
# define BUILTIN_EXEC_FAILURE 1

typedef void (t_builtin_fn)(t_lst *tokens, t_environment *this);

int				check_invalid_opts(t_opt *opt, char *exe_name, char *flags);
bool			builtin_true(t_lst *tokens, t_environment *env);
bool			builtin_false(t_lst *tokens, t_environment *env);

#endif
