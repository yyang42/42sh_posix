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

void			shenv_set_current_directory(t_shenv *this, char *from_whom)
{
	char		*cwd;

	cwd = getcwd(NULL, 0);
	if (cwd == NULL)
	{
		twl_dprintf(2, "%s: error retrieving current directory: getcwd: %s\n",
				from_whom, strerror(errno));
		this->shenv_current_directory = NULL;
	}
	else
	{
		this->shenv_current_directory = cwd;
	}
}
