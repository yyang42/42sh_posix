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

#include "edit/completion.h"

char			*completion_path_utils_join_path(char *begin, char *end)
{
	char		*ret;
	char		*tmp;

	ret = twl_strnew(twl_strlen(begin) + twl_strlen(end) + 1);
	tmp = ret;
	while (*begin)
	{
		*tmp = *begin;
		tmp += 1;
		begin += 1;
	}
	if (tmp != ret && tmp[-1] != '/')
	{
		*tmp = '/';
		tmp += 1;
	}
	while (*end)
	{
		*tmp = *end;
		tmp += 1;
		end += 1;
	}
	*tmp = '\0';
	return (ret);
}
