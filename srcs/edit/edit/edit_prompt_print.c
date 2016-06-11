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
#include "expan/expansion.h"

static char		*get_prompt_fn(char *ps)
{
	t_expansion	*expansion;
	char		*prompt_tmp;

	expansion = expansion_new_from_text_prompt(ps);
	prompt_tmp = expansion_get_string_prompt(expansion);
	if (!prompt_tmp)
		prompt_tmp = twl_strdup(ps);
	expansion_del(expansion);
	return (prompt_tmp);
}

void			edit_prompt_print(t_edit *this, t_edit_type type)
{
	char		*ps;
	char		*prompt;

	ps = (type == edit_type_ps1) ?
		shenv_shvars_get_value(shenv_singleton(), "PS1") :
		shenv_shvars_get_value(shenv_singleton(), "PS2");
	if (!ps)
		ps = "";
	prompt = get_prompt_fn(ps);
	this->puts(prompt);
	this->base_x = twl_strlen(prompt) % this->winsize_x;
	free(prompt);
}
