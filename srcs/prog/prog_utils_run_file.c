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

#include "prog.h"
#include <fcntl.h>

void				prog_utils_run_file(char *file)
{
	int				fd;

	fd = open(file, O_RDONLY);
	LOG_INFO("run file: %s", file);
	if (fd < 0)
	{
		shenv_singl_error_simple(127, "%s: No such file or directory", file);
		shenv_utils_exit(shenv_singleton()->last_exit_code);
	}
	prog_utils_set_command_pos_params();
	prog_utils_run_fd(fd);
}
