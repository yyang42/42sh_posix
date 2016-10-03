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
#include "edit/event.h"
#include "utils.h"

bool			edit_is_eof_set(t_edit *this)
{
	research_end(this);
	if (!shenv_shflag_enabled(shenv_singleton(), "ignoreeof"))
		return (true);
	this->puts("Use \"exit\" to leave the shell.");
	this->puts("\n\r");
	edit_prompt_print(this);
	return (false);
}
