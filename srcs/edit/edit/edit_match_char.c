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
#include "twl_ctype.h"

void				edit_match_escaped(t_edit *this, unsigned char buf)
{
	size_t			index;
	void			(*edit_fn)(t_edit *);

	index = 0;
	while (this->buffer[index])
		index += 1;
	this->buffer[index] = buf;
	if (!edit_utils_can_buffer_form_sequence(this))
	{
		twl_bzero(this->buffer, sizeof(this->buffer));
		return ;
	}
	if ((edit_fn = edit_utils_buffer_match_sequence(this)))
	{
		edit_fn(this);
		twl_bzero(this->buffer, sizeof(this->buffer));
	}
}

void				edit_match_char(t_edit *this, unsigned char buf)
{
	if (this->buffer[0] ^ (buf == '\033'))
		edit_match_escaped(this, buf);
	else if (buf == '\t')
		;
	else if (twl_isprint(buf))
		edit_place_letter(this, buf);
}
