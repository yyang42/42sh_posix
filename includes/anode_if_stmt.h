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
# include "anode_type.h"

typedef struct				s_anode_if_stmt
{
	t_anode_type			type;
	void					*body_part;
	void					*else_part;
}							t_anode_if_stmt;

t_anode_if_stmt				*anode_if_stmt_new(void);
void						anode_if_stmt_del(t_anode_if_stmt *this);

#endif
