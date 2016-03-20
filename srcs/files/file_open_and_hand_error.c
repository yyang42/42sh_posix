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

int		file_open_and_hand_error(t_token *token, int flags, int mod)
{
	int fd;
	fd = open(token->text, flags, mod);
	if (fd == -1)
	{
		shenv_print_error_printf(shenv_singleton(),
			token->line,
			"%s: %s", token->text, SHENV_ERROR_FILE_NOT_FOUND);
	}
	return (fd);
}
