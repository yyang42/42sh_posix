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

int					file_open_write_trunc(t_token *token)
{
	LOGGER_INFO("file_open_write_trunc: %s", token->text);
	return (file_open_and_hand_error(token, O_CREAT | O_WRONLY | O_TRUNC, FILE_DEFAULT_PERM));
}
