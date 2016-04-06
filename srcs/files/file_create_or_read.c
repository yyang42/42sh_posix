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

int		append_to_file(t_token *token)
{
	return (file_open_and_hand_error(token, O_CREAT | O_RDWR | O_APPEND, 0666));
}

int 	read_file(t_token *token)
{
	return (file_open_and_hand_error(token, O_RDONLY, 0666));
}

int		create_file(t_token *token)
{
	int fd;
	fd = file_open_and_hand_error(token, O_CREAT | O_RDWR | O_TRUNC, 0666);
	LOGGER_DEBUG("create fd: %d", fd);
	return (fd);
}

int		read_write_file(t_token *token)
{
	return (file_open_and_hand_error(token, O_CREAT | O_RDWR, 0666));
}
