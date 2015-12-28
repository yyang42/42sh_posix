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

#include "twl_dict.h"

#include "token.h"
#include "data.h"

t_token_type		token_type_get_type(char *str)
{
	t_token_type	*type_ptr;

	type_ptr = twl_dict_get(data_token_type_dict(), str);
	if (!type_ptr)
		return (TOKEN_UNKNOWN);
	return (*type_ptr);
}
