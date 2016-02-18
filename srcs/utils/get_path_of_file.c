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

#include "twl_xsys/stat.h"

#include "utils.h"
#include "data.h"

char				*get_path_of_file(char *str)
{
	t_lst			*path_lst;
	char			*path;

	if (twl_isdir(str))
	{
		return (twl_strdup(str));
	}
	else
	{
		path_lst = twl_str_split_to_lst(str, "/");
		if (twl_lst_len(path_lst) > 0)
		{
			free(twl_lst_pop(path_lst));
			path = twl_strjoinlst(path_lst, "/");
			twl_lst_del(path_lst, NULL);
			return (path);
		}
		else
		{
			return (NULL);
		}
	}
}
