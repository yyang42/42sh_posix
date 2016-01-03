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

#include "twl_ctype.h"

#include "edit/edit.h"
#include "edit/letter_mgr.h"

static bool			on_word_begin(char *cmd, int count)
{
	if (!twl_isspace(cmd[count]))
		if (twl_isspace(cmd[count - 1]))
			return (true);
	return (false);
}

void				letter_mgr_move_prev_word(t_lst *letters, void *edit_)
{
	char			*cmd;
	int				count;
	t_edit			*edit;

	edit = edit_;
	cmd = letter_mgr_concat_string(letters);
	count = edit->index;
	if (on_word_begin(cmd, count))
		count -= 2;
	while (twl_isspace(cmd[count]))
		count--;
	while (!twl_isspace(cmd[count]) && !twl_isspace(cmd[count - 1]))
		count--;
	if (count >= 0)
		edit->index = count;
	else
		edit->index = 0;
	free(cmd);
}
