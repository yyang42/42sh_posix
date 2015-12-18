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

#include "edit.h"

void				edit_handle_printable(t_edit *edit, int key)
{
	if (!twl_isprint(key))
		return ;
	letter_mgr_add(edit->letters, letter_new(key), edit->index);
	edit->index++;
	// twl_printf("key :%d\n", key);
	(void)edit;
}
