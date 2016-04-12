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

#ifndef BUILTIN_ALIAS_H
# define BUILTIN_ALIAS_H

# include "twl_stdio.h"
# include "shenv/shenv.h"
# include "alias/alias.h"
# include "builtin/builtin.h"
# include "argparser_extension.h"
# include <stdbool.h>

char				*builtin_alias_get(char *key, t_shenv *this);
void				builtin_alias_set(char *str, t_shenv *this);
void				builtin_alias_print(t_shenv *this);
void				builtin_alias_exec(t_lst *tokens, t_shenv *this);
t_argparser			*builtin_alias_argparser(void);

#endif
