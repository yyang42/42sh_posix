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

#ifndef EDIT_MOVE_H
# define EDIT_MOVE_H

# include "basics.h"
# include "edit/edit_move_func.h"

# define ARROW_LEFT 4479771
# define ARROW_RIGHT 4414235
# define CTRL_A 1
# define CTRL_E 5

typedef void		(*move_fn)(void *edit);

typedef struct		s_edit_move
{
	int				key;
	move_fn			func;
}					t_edit_move;

t_edit_move			*edit_move_new(int key, move_fn fn);
void				edit_move_del(t_edit_move *this);

#endif
