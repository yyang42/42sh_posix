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

#include "twl_ctype.h"

#include "edit/edit.h"

static bool			str_is_print(char *str)
{
	while (*str)
	{
		if (!twl_isprint(*str))
			return (false);
		str++;
	}
	return (true);
}

int					edit_advance_getch(t_edit *this)
{
	char			buffer[4];
	char			*str;
	int				ret;
	int				ret2;
	int				ret_val;

	ret_val = 0;
	str = twl_strdup("");
	twl_bzero(buffer, 4);
	ret = read(0, buffer, 3);
	ret2 = read(0, buffer, 3);
	if (str_is_print(buffer))
	{
		str = twl_strjoinfree(str, buffer, 'l');
	}
	else
	{
		ret_val = buffer[0];
		ret_val += buffer[1] << 8;
		ret_val += buffer[2] << 16;
	}
	if (twl_strlen(str) > 0)
	{
		edit_handle_string(this, str);
		ret_val = 0;
	}
	free(str);
	return (ret_val);
}
