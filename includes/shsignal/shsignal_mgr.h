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

#ifndef SHSIGNAL_MGR_H
# define SHSIGNAL_MGR_H

# include "basics.h"
# include "shsignal/shsignal.h"

t_lst				*shsignal_mgr_new(void);
void				shsignal_mgr_del(t_lst *shsignals);
void				shsignal_mgr_add(t_lst *shsignals, t_shsignal *shsignal);
void				shsignal_mgr_remove(t_lst *shsignals, t_shsignal *shsignal);
void				shsignal_mgr_print(t_lst *shsignals);

#endif
