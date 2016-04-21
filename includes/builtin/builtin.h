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
# include "shenv/shenv.h"
# include "ast/nodes/ast_simple_command.h"

# define BUILTIN_FLAG_SPECIAL_BUILTIN (1 << 1)

typedef void (t_builtin_fn)(t_lst *tokens, t_shenv *this);

typedef struct		s_builtin
{
	char			*builtin_name;
	t_builtin_fn	*builtin_fn;
	int				builtin_flags;
}					t_builtin;

t_builtin			*builtin_new(char *name, t_builtin_fn *builtin_fn, int flags);
void				builtin_del(t_builtin *builtin);

#endif
