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

static void		edit_del_previous_word_end_fn(t_edit *this, size_t begin_word)
{
	size_t		size_word;

	size_word = this->pos_cursor - begin_word;
	this->copy_buffer = twl_strndup(this->current->line + begin_word,
			size_word);
	twl_memmove(this->current->line + begin_word,
			this->current->line + this->pos_cursor,
			this->current->size - this->pos_cursor);
	twl_memset(this->current->line + this->current->size - size_word,
			' ', size_word);
	edit_move_goto_pos_cursor(this, begin_word);
	this->puts(this->current->line + begin_word);
	this->pos_cursor = this->current->size;
	edit_move_goto_pos_cursor(this, begin_word);
	twl_bzero(this->current->line + this->current->size - size_word, size_word);
	this->current->size -= size_word;
}

void			edit_del_previous_word(t_edit *this)
{
	size_t		begin_word;
	bool		not_space_only;

	if (this->pos_cursor == 0)
		return ;
	if (this->copy_buffer)
		twl_strdel(&this->copy_buffer);
	begin_word = this->pos_cursor - 1;
	not_space_only = false;
	while (begin_word && this->current->line[begin_word] == ' ')
		begin_word -= 1;
	while (begin_word && this->current->line[begin_word] != ' ')
	{
		not_space_only = true;
		begin_word -= 1;
	}
	if (this->current->line[begin_word] == ' ' && not_space_only)
		begin_word += 1;
	edit_del_previous_word_end_fn(this, begin_word);
}
