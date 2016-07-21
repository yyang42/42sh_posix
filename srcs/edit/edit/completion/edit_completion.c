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
#include "edit/completion.h"

void			edit_completion(t_edit *this)
{
	t_completion	*completion;

	if (this->current->size == 0 || edit_is_quoted(this))
		return ;
	completion = completion_new(this);
	LOG_DEBUG("%i: '%s'", completion->type, completion->current_word);
	if (completion->type == COMPLETION_VARIABLE)
		completion_variable(completion);
	else if (completion->type == COMPLETION_BRACE_VARIABLE)
		completion_brace_variable(completion);
	else if (completion->type == COMPLETION_EXEC)
		completion_exec(completion);
	else
		completion_dirs(completion);
	completion_del(completion);
}
