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

void				shvar_del(t_shvar *shvar)
{
	if (twl_strequ(shvar->shvar_key, "PATH"))
		shenv_build_binary_db(shenv_singleton());
	free(shvar->shvar_key);
	free(shvar->shvar_value);
	free(shvar->shvar_assign_value);
	free(shvar);
}
