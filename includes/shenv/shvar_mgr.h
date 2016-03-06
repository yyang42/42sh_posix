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

#ifndef SHVAR_MGR_H
# define SHVAR_MGR_H

# include "basics.h"
# include "shenv/shvar.h"

t_lst				*shvar_mgr_new(void);
void				shvar_mgr_del(t_lst *shvars);
void				shvar_mgr_add(t_lst *shvars, t_shvar *shvar);
void				shvar_mgr_remove(t_lst *shvars, t_shvar *shvar);
void				shvar_mgr_print(t_lst *shvars);

t_shvar				*shvar_mgr_find_by_key(t_lst *shvars, char *key);
t_shvar				*shvar_mgr_find_or_create(t_lst *shvars, char *key);

#endif
