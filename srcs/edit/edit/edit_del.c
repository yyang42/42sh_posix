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
#include "edit/research.h"

void				edit_del(t_edit *this)
{
	if (!this)
		return ;
	if (this->history)
		history_del(this->history);
	if (this->last)
		line_del(this->last);
	if (this->last_ps1)
		free(this->last_ps1);
	if (this->research)
		research_del(this->research);
	if (this->copy_buffer)
		free(this->copy_buffer);
	free(this);
}
