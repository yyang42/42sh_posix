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

#ifndef HISTORY_H
# define HISTORY_H

# include "basics.h"

# include "edit/history_mgr.h"

typedef struct		s_history
{
	t_lst			*history;
	t_lst			*match;
	int				search_index;
	int				history_index;
}					t_history;

t_history			*history_new(void);
void				history_del(t_history *history);
char				*history_get_search_at_index(t_history *history);

#endif
