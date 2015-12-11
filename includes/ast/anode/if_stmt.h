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

# include "ast/anode/anode.h"
# include "ast/anode/compound_stmt.h"

typedef struct		s_t_if_stmt
{
	t_atype			type;
	void			*cond;
	t_compound_stmt	*body;
	t_compound_stmt	*elze;
}					t_t_if_stmt;

t_t_if_stmt		*t_if_stmt_new(void);
void				t_if_stmt_del(t_t_if_stmt *this);

#endif
