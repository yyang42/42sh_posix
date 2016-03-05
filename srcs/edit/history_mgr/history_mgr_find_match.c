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

#include <fcntl.h>

#include "twl_xsys/stat.h"

#include "edit/history_mgr.h"

#include "shenv/shenv.h"

#include "twl_get_next_line.h"

static bool			find_fn(void *data, void *ctx)
{
	return twl_strstr(data, ctx);
}

t_lst				*history_mgr_find_match(t_lst *history, char *str)
{
	t_lst			*match_lst;

	match_lst = twl_lst_findall(history, find_fn, str);
	twl_lprintf("len: %zu", twl_lst_len(match_lst));
	return (match_lst);
}

