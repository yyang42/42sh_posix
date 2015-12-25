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

#ifndef AST2_COMPLETE_COMMAND_H
# define AST2_COMPLETE_COMMAND_H

# include "basics.h"

# include "ast/nodes2/ast2_list.h"
# include "ast/nodes2/ast2_separator.h"

typedef struct		s_ast2_complete_command
{
	t_ast2_list		 	*list;
	t_ast2_separator 	*separator;
}					t_ast2_complete_command;

t_ast2_complete_command		*ast2_complete_command_new(void);
void						ast2_complete_command_del(t_ast2_complete_command *ast2_complete_command);

#endif
