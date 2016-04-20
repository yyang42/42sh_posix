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

bool				shvar_check_is_readonly_and_print(t_shvar *this)
{
	if (this->shvar_read_only)
	{
		shenv_singl_error(EXIT_FAILURE, "%s: readonly variable", this->shvar_key);
		shenv_singleton()->last_exit_code = EXIT_FAILURE;
	}
	return (this->shvar_read_only);
}
