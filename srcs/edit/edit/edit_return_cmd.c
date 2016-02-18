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

char				*edit_return_cmd(t_edit *this)
{
	char			*cmd;

	cmd = NULL;
	if (!this->return_cmd)
		return cmd;
	if (this->state == NORMAL)
		cmd = letter_mgr_concat_string(this->letters);
	else if (this->state == SEARCH)
		cmd = twl_strdup(history_get_search_at_index(this->history));
	return (cmd);
}
