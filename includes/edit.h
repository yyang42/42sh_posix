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

#ifndef EDIT_H
# define EDIT_H

# include "twl_lst.h"

# include "letter_mgr.h"
# include "basics.h"

typedef struct		s_edit
{
	t_lst			*letters;
}					t_edit;

t_edit				*edit_new(void);
void				edit_del(t_edit *this);

#endif
