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

#include "twl_stdlib.h"
#include "twl_xunistd.h"

#include "edit.h"
#include "terminal.h"

#define DISABLE_FLAG(flag_storage, flag) (flag_storage &= ~(flag))
#define ENABLE_FLAG(flag_storage, flag) (flag_storage |= flag)


char				*edit_loop(t_edit *this)
{
	int				key;
	char			*cmd;

	cmd = NULL;

	terminal_enable();
	// TODO Error handling
	while (!cmd)
	{
		key = twl_getch();
		cmd = edit_handle_one_input(this, key);
		if (key == 27)
			break;
	}
	// real assignement
	cmd = twl_strdup("coucou");
	terminal_disable();
	//remove exit
	exit(0);
	return cmd;
	(void)this;
}
