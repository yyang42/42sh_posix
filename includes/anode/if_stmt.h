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

#ifndef ANODE_IF_STMT_H
# define ANODE_IF_STMT_H

# include "basics.h"

# include "anode/anode.h"
# include "anode/compound_stmt.h"

typedef struct				s_anode_if_stmt
{
	t_anode_type			type;
	void					*cond;
	t_compound_stmt	*body;
	t_compound_stmt	*elze;
}							t_anode_if_stmt;

t_anode_if_stmt				*anode_if_stmt_new(void);
void						anode_if_stmt_del(t_anode_if_stmt *this);

#endif
