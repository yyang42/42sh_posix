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

#include "edit/completion.h"

static void		iter_fn_(void *data, void *ctx)
{
	((t_edit *)ctx)->puts(data);
	((t_edit *)ctx)->puts("\n");
}

static bool		sort_fn(void *ctx1, void *ctx2)
{
	return (twl_strcmp(ctx1, ctx2) < 0);
}

void			completion_utils_print_lst(t_completion *this, t_lst *all)
{
	size_t		last_pos;

	last_pos = this->edit->pos_cursor;
	edit_move_end(this->edit);
	twl_lst_qsort(all, sort_fn);
	edit_terminal_disable(this->edit);
	this->edit->putc('\n');
	twl_lst_iter(all, iter_fn_, this->edit);
	this->edit->puts(PS1);
	this->edit->puts(this->edit->current->line);
	edit_terminal_enable(this->edit);
	edit_move_goto_pos_cursor(this->edit, last_pos);
}
