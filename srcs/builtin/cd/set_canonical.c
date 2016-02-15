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

#include "builtin/cd.h"

static bool		filter_fn(void *data, void *context_)
{
	char *str;
	char *value;

	str = data;
	value = context_;
	if (twl_strcmp(str, value) == 0)
		return (true);
	return (false);
}

static t_lst	*handle_dot_dot(t_lst *lst)
{
	t_lst_elem__ *tmp;

	tmp = lst->head;
	while (tmp)
	{
		if (tmp->next && tmp->next->data
			&& twl_strcmp(((char *)tmp->data), "..")
			&& !twl_strcmp(((char *)tmp->next->data), ".."))
		{
			twl_lst_del_elem__(lst, tmp->next, free);
			twl_lst_del_elem__(lst, tmp, free);
			return (handle_dot_dot(lst));
		}
		tmp = tmp->next;
	}
	return (lst);
}

static char		*remove_dots(char *path)
{
	t_lst	*list;
	char	*new_path;

	list = twl_str_split_to_lst(path, "/");
	twl_lst_remove_if(list, filter_fn, ".", free);
	list = handle_dot_dot(list);
	twl_lst_remove_if(list, filter_fn, "..", free);
	new_path = twl_strjoinlst(list, "/");
	twl_lst_del(list, free);
	return (twl_strjoinfree("/", new_path, 'r'));
}

char			*set_canonical_form(char *path)
{
	char *new_path;

	new_path = remove_dots(path);
	return (new_path);
}
