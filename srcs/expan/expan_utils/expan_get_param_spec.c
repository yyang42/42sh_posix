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

#include "expan/expan_utils.h"
#include "shenv/shenv.h"

static void		iter_fn(void *data, void *context)
{
	twl_lst_push_back(context, data);
}

t_lst			*expan_get_param_spec(char param)
{
	t_lst		*lsparam;
	t_shenv		*shenv;

	lsparam = twl_lst_new();
	shenv = shenv_singleton();
	if (param == '*' || param == '@')
		twl_lst_iter(shenv->pos_params, iter_fn, lsparam);
	else if (param == '#')
		twl_lst_push_back(lsparam, twl_itoa(twl_lst_len(shenv->pos_params)));
	else if (param == '?')
		twl_lst_push_back(lsparam, twl_itoa(shenv->info.saved_last_exit));
	else if (param == '-')
		twl_lst_push_back(lsparam, shenv_concat_flags(shenv));
	else if (param == '$')
		twl_lst_push_back(lsparam, twl_itoa(getpid()));
	else if (param == '!' &&
			shenv->info.most_recent_background_command_pid != -1)
		twl_lst_push_back(lsparam,
				twl_itoa(shenv->info.most_recent_background_command_pid));
	else if (param == '0')
		twl_lst_push_back(lsparam, twl_strdup(shenv->shenv_name));
	return (lsparam);
}
