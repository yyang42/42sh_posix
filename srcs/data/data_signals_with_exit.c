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

#include "twl_lst.h"
#include "data.h"
#include "shsignal/shsignal.h"

static void			push_standard_signals_fn(void *shsignal_, void *data)
{
	t_shsignal		*shsignal;

	shsignal = shsignal_;
	twl_lst_push_back(data, shsignal_new(shsignal->signum, shsignal->signame));
}

t_lst				*data_signals_with_exit(void)
{
	static t_lst	*data = NULL;

	if (data == NULL)
	{
		data = twl_lst_new();
		twl_lst_push_back(data, shsignal_new(0, "EXIT"));
		twl_lst_iter(data_signals(), push_standard_signals_fn, data);
	}
	return (data);
}
