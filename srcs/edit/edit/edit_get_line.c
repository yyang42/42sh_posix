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

char				*edit_get_line(t_edit *this)
{
	char			*ret;

	edit_terminal_enable(this);
	this->current = line_new();
	ret = line_get(this->current);
	line_del(this->current);
	edit_terminal_disable(this);
	return (ret ? twl_strdup(ret) : twl_strdup("echo lel"));
	(void)this;
}
