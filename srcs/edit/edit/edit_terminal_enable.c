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

#include "edit/edit.h"

void				edit_terminal_enable(t_edit *this)
{
	if (this->echoing)
		return ;
	if (tcsetattr(0, TCSADRAIN, &this->term) == -1)
	{
		twl_dprintf(2, "tcsetattr: %s\n", twl_strerror(errno));
		exit(-1);
	}
}
