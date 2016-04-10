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

#include "shenv/shenv.h"

bool				shenv_loop_should_exec(t_shenv *this)
{
	if (shenv_singleton()->shenv_return_triggered)
		return (false);
	if (shenv_singleton()->shenv_shall_quit_curr_ast)
		return (false);
	return (this->shenv_break_counter == 0
		&& this->shenv_continue_counter == 0);
}
