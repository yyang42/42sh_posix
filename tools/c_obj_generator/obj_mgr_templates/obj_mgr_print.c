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

static void			print_<OBJ_NAME>_fn(void *<OBJ_NAME>_)
{
	t_<OBJ_NAME>	*<OBJ_NAME>;

	<OBJ_NAME> = <OBJ_NAME>_;
	twl_printf("<Object #%p>\n", <OBJ_NAME>);
}

void				<MGR_NAME>_print(t_lst *<OBJ_PLURAL_NAME>)
{
	twl_printf("%s>>>>>>>>>> <OBJ_NAME> list%s\n", C_CYAN, C_CLEAR);
	twl_lst_iter0(<OBJ_PLURAL_NAME>, print_<OBJ_NAME>_fn);
	twl_printf("%s-------------------------------------%s\n", C_CYAN, C_CLEAR);
}
