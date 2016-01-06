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

int		append_to_file(char *str)
{
	int fd;

	fd = open(str, O_CREAT | O_RDWR | O_APPEND, 0666);
	if (fd == -1)
		perror(str);
	return (fd);
}

int 	read_file(char *str)
{
	int fd;

	fd = open(str, O_RDONLY, 0666);
	if (fd == -1)
		perror(str);
	return (fd);
}

int		create_file(char *str)
{
	int fd;

	fd = open(str, O_CREAT | O_RDWR | O_TRUNC, 0666);
	if (fd == -1)
		perror(str);
	return (fd);
}
