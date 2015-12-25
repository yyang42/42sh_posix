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

#ifndef edit_key_mgr_H
# define edit_key_mgr_H

# include "basics.h"
# include "edit/edit_key.h"

t_lst				*edit_key_mgr_new(void);
void				edit_key_mgr_del(t_lst *edit_keys);
void				edit_key_mgr_add(t_lst *edit_keys, t_edit_key *edit_key);
void				edit_key_mgr_print(t_lst *edit_keys);
void				edit_key_mgr_do(t_lst *edit_keys, void *edit, int key);
#endif
