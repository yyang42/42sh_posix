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

#include "edit/history.h"
#include "twl_stdlib.h"

static bool			is_shvar_number(char *shvar)
{
	while (*shvar == ' ' || *shvar == '\t' || *shvar == '\n')
		shvar += 1;
	if (!*shvar)
		return (false);
	while (*shvar >= '0' && *shvar <= '9')
		shvar += 1;
	while (*shvar == ' ' || *shvar == '\t' || *shvar == '\n')
		shvar += 1;
	return (*shvar == '\0');
}

size_t				history_get_histfilesize(t_history *this)
{
	char			*shvar;

	shvar = shenv_shvars_get_value(shenv_singleton(), "HISTFILESIZE");
	if (!shvar)
		return (DFL_HISTFILESIZE);
	else if (!*shvar || is_shvar_number(shvar))
		return (DFL_HISTFILESIZE);
	else
		return ((size_t)twl_atoi(shvar));
	(void)this;
}
