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
#include "twl_printf.h"

void				shenv_clear_stdin_read_buffer(t_shenv *env)
{
	if (env->shenv_read_remainder_ptr
		&& env->shenv_read_remainder_ptr[STDIN_FILENO])
	{
		*(env->shenv_read_remainder_ptr[STDIN_FILENO]) = '\0';
	}
}
