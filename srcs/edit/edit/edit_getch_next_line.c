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

static char			*get_or_set_rest_buffer(char *str, bool clear)
{
	static char		*buff = NULL;

	if (str != NULL)
		buff = str;
	else if (buff != NULL && str == NULL && clear)
	{
		free(buff);
		buff = NULL;
	}
	return buff;
}

static char			*read_standard_input(void)
{
	char			buffer[5000];


	twl_bzero(buffer, 5000);
	read(0, buffer, 4999);
	LOGGER_INFO("stdin");
	return (twl_strdup(buffer));
}


static char			*get_str_to_handle(void)
{
	char			*str_to_handle;

	if (get_or_set_rest_buffer(NULL, false) && twl_strlen(get_or_set_rest_buffer(NULL, false)) > 0)
		str_to_handle = get_or_set_rest_buffer(NULL, false);
	else
		str_to_handle = read_standard_input();
	return (str_to_handle);
}


static int			find_nl_in_str_to_handle(t_edit *edit, char *str_to_handle,
																char *find_nl)
{
	char 			*rest_to_save;
	char			*ret_str;

	ret_str = twl_strsub(str_to_handle, 0, find_nl - str_to_handle);

	rest_to_save = twl_strdup(str_to_handle + twl_strlen(ret_str) + 1);
	if (twl_strlen(rest_to_save) < 1)
		get_or_set_rest_buffer(NULL, true);
	else
		get_or_set_rest_buffer(twl_strdup(str_to_handle + twl_strlen(ret_str) + 1), false);
	edit_handle_string(edit, ret_str);
	return (RETURN_KEY);
}

static void			not_find_nl_in_str_to_handle(t_edit *edit)
{
	char			*ret_str;

	ret_str = get_or_set_rest_buffer(NULL, false);
	get_or_set_rest_buffer(NULL, true);
	edit_handle_string(edit, ret_str);
}

static int			str_is_a_special_command(char *str_to_handle)
{
	int 			ret_val;

	ret_val = 0;
	ret_val = str_to_handle[0];
	ret_val += str_to_handle[1] << 8;
	ret_val += str_to_handle[2] << 16;
	get_or_set_rest_buffer(NULL, true);
	return (ret_val);
}

int					edit_getch_next_line(t_edit *this)
{
	char			*str_to_handle;
	int				ret_val;
	char			*find_nl;
	char			*rest_value;

	ret_val = 0;
	str_to_handle = get_str_to_handle();
	find_nl = twl_strchr(str_to_handle, '\n');
	rest_value = get_or_set_rest_buffer(NULL, false);
	if (find_nl && twl_strlen(str_to_handle) > 1)
	{
		ret_val = find_nl_in_str_to_handle(this, str_to_handle, find_nl);
	}
	else if (find_nl == NULL
			&& rest_value
			&& twl_strlen(rest_value) > 0)
	{
		not_find_nl_in_str_to_handle(this);
	}
	else if (!str_is_print(str_to_handle))
	{
		ret_val = str_is_a_special_command(str_to_handle);
	}
	else if (find_nl == NULL
			&& rest_value == NULL
			&& twl_strlen(str_to_handle) > 0)
	{
		edit_handle_string(this, str_to_handle);
		get_or_set_rest_buffer(NULL, true);
	}
	free(str_to_handle);
	return (ret_val);
}

