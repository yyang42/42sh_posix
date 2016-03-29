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

#ifndef TRAP_MGR_H
# define TRAP_MGR_H

# include "basics.h"
# include "trap/trap.h"

t_lst				*trap_mgr_new(void);
void				trap_mgr_del(t_lst *traps);
void				trap_mgr_add(t_lst *traps, t_trap *trap);
void				trap_mgr_remove(t_lst *traps, t_trap *trap);
void				trap_mgr_print(t_lst *traps);

#endif
