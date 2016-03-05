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

#ifndef BUILTIN_MGR_H
# define BUILTIN_MGR_H

# include "basics.h"
# include "builtin/builtin.h"

t_lst				*builtin_mgr_new(void);
void				builtin_mgr_del(t_lst *builtins);
void				builtin_mgr_add(t_lst *builtins, t_builtin *builtin);
void				builtin_mgr_remove(t_lst *builtins, t_builtin *builtin);
void				builtin_mgr_print(t_lst *builtins);

t_builtin			*builtin_mgr_find_by_name(t_lst *builtins, char *name);

#endif
