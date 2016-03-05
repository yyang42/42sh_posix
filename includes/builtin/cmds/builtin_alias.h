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

# include "twl_arr.h"
# include "twl_opt.h"
# include "twl_stdio.h"
# include "environment.h"
# include "twl_dict.h"
# include "twl_arr.h"
# include "builtin/builtin.h"
# include <stdbool.h>

char				*builtin_alias_get(char *key, t_shenv *this);
void				builtin_alias_set(char *str, t_shenv *this);
void				builtin_alias_print(t_shenv *this);
int					builtin_alias_exec(t_lst *tokens, t_shenv *this);

#endif
