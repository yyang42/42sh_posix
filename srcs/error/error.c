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

void 	error_permission_denied(char *file)
{
	twl_dprintf(2, "42sh: permission denied: %s\n", file);
}

void 	error_not_directory(char *file)
{
	twl_dprintf(2, "42sh: Not a directory: %s\n", file);
}

void 	error_command_not_found(char *file)
{
	twl_dprintf(2, "42sh: command not found: %s\n", file);
}
