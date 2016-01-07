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
# include "cd.h"
# include "echo.h"
# include "env.h"
# include "export.h"
# include "set.h"
# include "unset.h"
# include "alias.h"
# include "umask.h"
# include "ast/nodes/ast_simple_command.h"

#define BUILTIN_EXEC_SUCCESS 0
#define BUILTIN_EXEC_FAILURE 1

int				check_invalid_opts(t_opt *opt, char *exe_name, char *flags);
bool			builtin_true();
bool			builtin_false();

#endif
