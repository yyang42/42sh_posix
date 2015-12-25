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

#include "twl_xstdlib.h"

#include "<OBJ_NAME>.h"

t_<OBJ_NAME>			<PADDING>*<OBJ_NAME>_new(void)
{
	t_<OBJ_NAME>		<PADDING>*<OBJ_NAME>;

	<OBJ_NAME> = twl_malloc_x0(sizeof(t_<OBJ_NAME>));
	return (<OBJ_NAME>);
}
