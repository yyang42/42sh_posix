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

#include "edit.h"

char				*edit_return_cmd(t_edit *this, int key)
{
	char			*cmd;

	cmd = NULL;
	if (key != 10)
		return cmd;
	write(1, "\n", 1);
	cmd = letter_mgr_concat_string(this->letters);
	return (cmd);
}
