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

#ifndef COPAST_H
# define COPAST_H

# include "basics.h"

# include "edit/letter_mgr.h"

typedef struct		s_copast
{
	int				start_index;
	int				stop_index;
	t_lst			*clipboard_letters;
	bool			has_copy;
}					t_copast;

t_copast			*copast_new(int index);
void				copast_del(t_copast *copast);

void				copast_stop_copy(t_copast *this, int index, t_lst *letters);

#endif
