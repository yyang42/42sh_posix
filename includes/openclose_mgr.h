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

#ifndef OPENCLOSE_MGR_H
# define OPENCLOSE_MGR_H

# include "basics.h"
# include "openclose.h"

t_lst				*openclose_mgr_new(void);
void				openclose_mgr_del(t_lst *opencloses);
void				openclose_mgr_add(t_lst *opencloses, t_openclose *openclose);
void				openclose_mgr_remove(t_lst *opencloses, t_openclose *openclose);
void				openclose_mgr_print(t_lst *opencloses);

#endif
