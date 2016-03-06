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

#ifndef BUILTIN_ENV_H
# define BUILTIN_ENV_H

# include <sys/stat.h>
# include <sys/types.h>
# include "builtin/builtin.h"
# include "shenv/shenv.h"
# include "builtin/cmds/builtin_env.h"
# include "utils.h"
# include "twl_arr.h"
# include "twl_opt.h"
# include "twl_arr2.h"
# include "ast/nodes/ast_simple_command.h"

# define ENV_OPT_VALID_OPTS "i"

typedef struct		s_env_args
{
	t_lst				*tokens;
	char				**env_arr;
	char				*utility;
	int					utility_index;
	bool				has_utility;
}					t_env_args;

void				builtin_env_exec(t_lst *tokens, t_shenv *this);
void				builtin_env_exec_do(t_env_args *env, t_shenv	*clone);
void				builtin_env_utils_add_shvar(void *data_, void *context_);

#endif
