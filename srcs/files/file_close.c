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

int					file_close(int fd)
{
	int				ret;

	LOGGER_INFO("Close file: %d", fd);
	ret = close(fd);
	if (ret == -1)
	{
		shenv_singl_error(1, "close: %s", strerror(errno));
		LOGGER_ERROR("Fail to close file: %d", fd);
	}
	return (ret);
}
