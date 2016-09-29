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

static void			push_data01(t_lst *data)
{
	twl_lst_push_back(data, shsignal_new(1, "HUP"));
	twl_lst_push_back(data, shsignal_new(2, "INT"));
	twl_lst_push_back(data, shsignal_new(3, "QUIT"));
	twl_lst_push_back(data, shsignal_new(4, "ILL"));
	twl_lst_push_back(data, shsignal_new(5, "TRAP"));
	twl_lst_push_back(data, shsignal_new(6, "ABRT"));
	twl_lst_push_back(data, shsignal_new(7, "EMT"));
	twl_lst_push_back(data, shsignal_new(8, "FPE"));
	twl_lst_push_back(data, shsignal_new(9, "KILL"));
	twl_lst_push_back(data, shsignal_new(10, "BUS"));
	twl_lst_push_back(data, shsignal_new(11, "SEGV"));
	twl_lst_push_back(data, shsignal_new(12, "SYS"));
	twl_lst_push_back(data, shsignal_new(13, "PIPE"));
	twl_lst_push_back(data, shsignal_new(14, "ALRM"));
	twl_lst_push_back(data, shsignal_new(15, "TERM"));
}

static void			push_data02(t_lst *data)
{
	twl_lst_push_back(data, shsignal_new(16, "URG"));
	twl_lst_push_back(data, shsignal_new(17, "STOP"));
	twl_lst_push_back(data, shsignal_new(18, "TSTP"));
	twl_lst_push_back(data, shsignal_new(19, "CONT"));
	twl_lst_push_back(data, shsignal_new(20, "CHLD"));
	twl_lst_push_back(data, shsignal_new(21, "TTIN"));
	twl_lst_push_back(data, shsignal_new(22, "TTOU"));
	twl_lst_push_back(data, shsignal_new(23, "IO"));
	twl_lst_push_back(data, shsignal_new(24, "XCPU"));
	twl_lst_push_back(data, shsignal_new(25, "XFSZ"));
	twl_lst_push_back(data, shsignal_new(26, "VTALRM"));
	twl_lst_push_back(data, shsignal_new(27, "PROF"));
	twl_lst_push_back(data, shsignal_new(28, "WINCH"));
	twl_lst_push_back(data, shsignal_new(29, "INFO"));
	twl_lst_push_back(data, shsignal_new(30, "USR1"));
	twl_lst_push_back(data, shsignal_new(31, "USR2"));
}

t_lst				*data_signals(void)
{
	static t_lst	*data = NULL;

	if (data == NULL)
	{
		data = twl_lst_new();
		push_data01(data);
		push_data02(data);
	}
	return (data);
}
