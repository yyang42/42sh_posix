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

#include "edit/research.h"

/*
** "(reverse-i-search)`': ": length == 22
** "(failed reverse-i-search)`': ": length == 29
*/

void			research_print_prompt(t_edit *this)
{
	char		*prompt;

	if (this->research->found)
	{
		prompt = twl_strjoin("(reverse-i-search)`", this->research->search);
	}
	else
	{
		prompt = twl_strjoin("(failed reverse-i-search)`",
				this->research->search);
	}
	prompt = twl_strjoinfree(prompt, "': ", 'l');
	edit_prompt_print_string(this, prompt);
	free(prompt);
}
