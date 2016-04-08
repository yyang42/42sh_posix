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

#include "shenv/shvar.h"
#include "shenv/shenv.h"

void				shvar_check_print_readonly_error(t_shvar *this)
{
	if (this->shvar_read_only)
	{
		shenv_singl_error(EXIT_FAILURE, "%s: readonly variable", this->shvar_key);
		if (!shenv_singleton()->is_interactive_shell)
		{
			exit(EXIT_FAILURE);
		}
	}
}
