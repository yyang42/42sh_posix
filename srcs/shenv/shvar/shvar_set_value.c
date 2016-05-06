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
#include "twl_unistd.h"

void				shvar_set_value(t_shvar *this, char *value)
{
	if (this->shvar_value)
		free(this->shvar_value);
	this->shvar_value = twl_strdup(value);
	if (twl_strequ(this->shvar_key, "PATH"))
		shenv_build_binary_db(shenv_singleton());
	if (twl_strequ(this->shvar_key, "OPTIND")
		&& (twl_strequ(value, "1") || twl_strequ(value, "0")))
	{
		LOG_DEBUG("SET VALUE OF OPTIND: %s", value);
		g_twl_optind = 1;
		g_twl_optpos = NULL;
		g_twl_optarg = NULL;
		g_twl_optopt = 0;
	}
}
