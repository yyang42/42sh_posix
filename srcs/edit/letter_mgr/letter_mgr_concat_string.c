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

#include "twl_xstdlib.h"

#include "edit/letter_mgr.h"

void				concat_fn(void *_letter, int index, void *_cmd)
{
	t_letter		*letter;
	char			*cmd;

	letter = _letter;
	cmd = _cmd;
	cmd[index] = letter->letter[0];

}

char				*letter_mgr_concat_string(t_lst *letters)
{
	char			*cmd;

	cmd = twl_malloc_x0(sizeof(char) * twl_lst_len(letters) + 1);
	twl_lst_iteri(letters, concat_fn, cmd);
	return (cmd);
}
