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

#include "arexp/arexp.h"

void			arexp_print_indent(int depth)
{
	static char	*indent = NULL;

	if (!indent)
	{
		indent = twl_strnew(1023);
		twl_memset(indent, ' ', 1023);
	}
	if (!write(1, indent, depth < 1023 ? depth : 1023))
		return ;
}
