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

#ifndef HISTORY_MGR_H
# define HISTORY_MGR_H

# include "basics.h"

# define HISTORY_FILENAME ".42sh_history"

t_lst				*history_mgr_new(void);
void				history_mgr_del(t_lst *history);
void				history_mgr_add(t_lst *history, char *line);
void				history_mgr_remove(t_lst *historys, char *str);
void				history_mgr_print(t_lst *history);
void				history_mgr_export(t_lst *history);

#endif
