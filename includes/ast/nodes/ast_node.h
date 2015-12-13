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

#ifndef ANODE_H
# define ANODE_H

# include "basics.h"

# include "ast/atype.h"

typedef struct		s_ast_node
{
	t_atype	type;
}					t_ast_node;

t_atype				ast_node_get_type(void *ast_node_);
char				*ast_node_get_type_str(void *ast_node_);

#endif
