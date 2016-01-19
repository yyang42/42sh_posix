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

#ifndef AST_EXPAN_COMMAND_H
# define AST_EXPAN_COMMAND_H

#include "basics.h"
# define CMD_MAX_LEN 2048

typedef struct			s_expan_command
{
	char				*command;
}						t_expan_command;

t_expan_command			*expan_command_new(void);
void					expan_command_del(t_expan_command *expan_command);
void					expan_command_print(t_expan_command *expan_command);
#endif
