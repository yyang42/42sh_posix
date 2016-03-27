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

#include <fcntl.h>

#include "twl_get_next_line.h"
#include "twl_xstdlib.h"

#include "edit/edit.h"

#include "edit/cursor.h"

t_edit				*edit_new(void)
{
	t_edit			*this;

	this = twl_malloc_x0(sizeof(t_edit));
	this->index = 0;
	this->letters = letter_mgr_new();
	this->edit_keys = edit_key_mgr_new();
	this->return_cmd = false;
	this->history = history_new();
	this->copast = NULL;
	this->state = NORMAL;
	cursor_reset_pos();

	signal_handle_ctrl_c();
	signal_handle_sigwinch();
	return (this);
}
