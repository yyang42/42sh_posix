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

#include "utils.h"
#include <errno.h>

void				utils_log_errno(char *name, int error_code)
{
	int				errno_save;
	char			*msg;

	errno_save = errno;
	if (error_code < 0)
	{
		twl_asprintf(&msg, "%s: %s", name, twl_strerror(errno_save));
		LOG_ERROR(msg);
		twl_dprintf(2, msg);
		exit(1);
	}
}
