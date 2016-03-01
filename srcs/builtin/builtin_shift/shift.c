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

#include "builtin/builtin_shift.h"
#include "twl_stdlib.h"

static void		shift_action(t_environment *env, t_opt *opt)
{
	size_t	shift_nb;
	char	*shift_str;

	if (twl_lst_len(opt->args) > 0)
	{
		shift_str = (char*)twl_lst_first(opt->args);
		shift_nb = twl_atoi(shift_str);
	}
	else
		shift_nb = 1;
	if (twl_lst_len(env->pos_params) < shift_nb)
	{
		twl_printf("shift count must be <= $#");
		environment_set_last_exit_status_2(env, BUILTIN_EXEC_FAILURE);
	}
	if (twl_lst_len(env->pos_params) < shift_nb)
		twl_lst_clear(env->pos_params, &free);
	else
	{
		while (shift_nb > 0)
		{
			free(twl_lst_pop_front(env->pos_params));
			shift_nb--;
		}
	}
}

int				builtin_shift(t_lst *tokens, t_environment *env)
{
	t_opt			*opt;
	char			**arr;
	char			*str;

	str = token_mgr_strjoin(tokens, " "); // TODO: refactor
	arr = twl_strsplit_mul(str, " \n\t");
	opt = twl_opt_new(arr, UMASK_OPT_VALID_OPTS);
	environment_set_last_exit_status_2(env, BUILTIN_EXEC_SUCCESS);
	if (!check_invalid_opts(opt, "shift", SHIFT_OPT_VALID_OPTS))
	{
		if (twl_lst_len(opt->args) > 1)
		{
			twl_printf("shift: too many arguments");
			environment_set_last_exit_status_2(env, BUILTIN_EXEC_FAILURE);
		}
		else
			shift_action(env, opt);
	}
	twl_arr_del(arr, &free);
	twl_opt_del(opt);
	return (0);
}
