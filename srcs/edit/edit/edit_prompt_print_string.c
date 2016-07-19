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

void					edit_prompt_print_string(t_edit *this, char *prompt)
{
	if (!prompt)
		prompt = "";
	this->puts(prompt);
	this->prompt_size = twl_strlen(prompt);
	this->base_x = this->prompt_size % this->winsize_x;
	if (this->base_x == 0 && this->prompt_size)
		this->puts("\n\r");
}
