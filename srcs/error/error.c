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

#include "error.h"
#include "shenv/shenv.h"

void	error_permission_denied(char *file)
{
	shenv_singl_error(EXIT_FAILURE, "permission denied: %s\n", file);
}

void	error_not_directory(char *file)
{
	shenv_singl_error(EXIT_FAILURE, "Not a directory: %s\n", file);
}

void	error_command_not_found(char *file)
{
	shenv_singl_error(EXIT_FAILURE, "command not found: %s\n", file);
}
