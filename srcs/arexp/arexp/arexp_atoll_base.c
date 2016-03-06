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
#include "twl_ctype.h"

static long long	get_value(t_arexp *this, char c, t_token *token)
{
	if (twl_isdigit(c))
		return (c - '0');
	else if (twl_islower(c))
		return (c - 'a' + 10);
	else if (twl_isupper(c))
		return (c - 'A' + 36);
	else if (c == '@')
		return (62);
	else if (c == '_')
		return (63);
	else
	{
		arexp_set_error_msg(this, "invalid number: ", token);
		return (0);
	}
}

long long			arexp_atoll_base(t_arexp *this, char *input, int base,
																t_token *token)
{
	long long	ret;
	long long	tmp;
	size_t		index;
	char		c;

	index = 0;
	ret = 0;
	while ((c = input[index]))
	{
		tmp = get_value(this, c, token);
		if (this->error_msg)
			return (0);
		if (tmp >= base)
		{
			arexp_set_error_msg(this, "value too great for base: ", token);
			return (0);
		}
		ret *= base;
		ret += tmp;
		index += 1;
	}
	return (ret);
}
