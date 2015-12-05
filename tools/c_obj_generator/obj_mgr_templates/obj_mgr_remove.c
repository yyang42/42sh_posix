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

#include "<MGR_NAME>.h"

void				<MGR_NAME>_remove(t_lst *<OBJ_PLURAL_NAME>, t_<OBJ_NAME> *<OBJ_NAME>)
{
	int				index;

	index = twl_lst_indexof(<OBJ_PLURAL_NAME>, <OBJ_NAME>);
	if (index == -1)
	{
		assert(!"[ERROR] Object not found!");
	}
	twl_lst_popi(<OBJ_PLURAL_NAME>, index);
	<OBJ_NAME>_del(<OBJ_NAME>);
}
