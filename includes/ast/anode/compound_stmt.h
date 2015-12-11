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

#ifndef ANODE_COMPOUND_STMT_H
# define ANODE_COMPOUND_STMT_H

# include "twl_lst.h"

# include "basics.h"

# include "ast/anode/anode.h"

typedef struct		s_compound_stmt
{
	t_atype			type;
	t_lst			*items;
}					t_compound_stmt;

t_compound_stmt		*compound_stmt_new(void);
void				compound_stmt_del(t_compound_stmt *this);

#endif
