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

#ifndef TRAP_H
# define TRAP_H

# include "basics.h"

# define TRAP_ACTION_SEPARATOR " "
# define TRAP_SIGEXIT 0

typedef struct		s_trap
{
	char			*trap_action;
	int				trap_cond;
}					t_trap;

t_trap				*trap_new(char *trap_action, int trap_cond);
void				trap_del(t_trap *trap);

#endif
