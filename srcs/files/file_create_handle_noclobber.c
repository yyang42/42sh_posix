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

int					file_create_handle_noclobber(t_token *param_token)
{
	int				fd;

	if (shenv_flag_exist(shenv_singleton(), "C") && file_exists(param_token->text))
	{
		shenv_singl_error(EXIT_FAILURE, "%s: cannot overwrite existing file", param_token->text);
		fd = -1;
	}
	else
	{
		fd = file_open_write_trunc(param_token);
	}
	return (fd);
}
