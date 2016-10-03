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

static int			puts_fn(char *s)
{
	return (write(2, s, twl_strlen(s)));
}

static int			putc_fn(int c)
{
	return (write(2, &c, 1));
}

t_edit				*edit_new(void)
{
	t_edit			*this;

	this = twl_malloc_x0(sizeof(t_edit));
	edit_terminal_init(this);
	edit_get_winsize(this);
	this->history = history_new();
	this->putc = putc_fn;
	this->puts = puts_fn;
	return (this);
}
