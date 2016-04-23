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

#include "file.h"
#include "shenv/shenv.h"

int					file_open_and_hand_error(t_token *token, int flags, int mod)
{
	int fd;

	fd = open(token->text, flags, mod);
	LOGGER_INFO("open: fd (%d) for file (%s)", fd, token->text);
	if (fd == -1)
	{
		shenv_singl_error(EXIT_FAILURE,
			"%s: %s", token->text,  strerror(errno));
		return (-1);
	}
	return (fd);
}
