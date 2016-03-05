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

#ifndef EXECUTE_H
# define EXECUTE_H
# include "basics.h"

# include "basics.h"
# include <errno.h>
# include "environment.h"
# include "builtin/cmds/builtin_env.h"
# include "utils.h"
# include "twl_arr.h"
# include "twl_opt.h"
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "twl_stdio.h"
# include <stdio.h>
# include <string.h>

int				execute(char *path, char **args, char **env);

#endif
