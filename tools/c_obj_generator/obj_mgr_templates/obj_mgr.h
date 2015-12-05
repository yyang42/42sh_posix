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

#ifndef <MGR_NAME_UPPER>_H
# define <MGR_NAME_UPPER>_H

# include "basics.h"
# include "<OBJ_NAME>.h"

t_lst				*<MGR_NAME>_new(void);
void				<MGR_NAME>_del(t_lst *<OBJ_PLURAL_NAME>);
void				<MGR_NAME>_add(t_lst *<OBJ_PLURAL_NAME>, t_<OBJ_NAME> *<OBJ_NAME>);
void				<MGR_NAME>_remove(t_lst *<OBJ_PLURAL_NAME>, t_<OBJ_NAME> *<OBJ_NAME>);
void				<MGR_NAME>_print(t_lst *<OBJ_PLURAL_NAME>);

#endif
