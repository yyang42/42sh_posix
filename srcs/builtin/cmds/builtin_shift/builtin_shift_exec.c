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

#include "builtin/cmds/builtin_shift.h"
#include "builtin/cmds/builtin_umask.h"
#include "twl_stdlib.h"

static int			get_shift_nb(char *shift_str)
{
	int		shift_nb;

	if (twl_str_is_pos_num(shift_str))
	{
		shift_nb = twl_atoi(shift_str);
	}
	else
	{
		shenv_singl_error(EXIT_FAILURE,
				"shift: %s: numeric argument required", shift_str);
		shift_nb = -1;
	}
	return (shift_nb);
}

static void			shift_action(t_shenv *env, char *shift_str)
{
	int				shift_nb;

	shift_nb = get_shift_nb(shift_str);
	if (shift_nb < 0)
		return ;
	if ((int)twl_lst_len(env->shenv_pos_params) < shift_nb)
	{
		env->last_exit_code = EXIT_FAILURE;
		return ;
	}
	if ((int)twl_lst_len(env->shenv_pos_params) < shift_nb)
	{
		twl_lst_clear(env->shenv_pos_params, &free);
	}
	else
	{
		while (shift_nb > 0)
		{
			free(twl_lst_pop_front(env->shenv_pos_params));
			shift_nb--;
		}
	}
}

void				builtin_shift_exec(t_lst *tokens, t_shenv *env)
{
	t_argparser_result	*argparser_result;

	argparser_result = argparser_parse_tokens(
			builtin_shift_argparser(), tokens);
	if (argparser_result->err_msg)
	{
		argparser_result_print_usage_exit_status(argparser_result, 2);
	}
	else
	{
		if (twl_lst_len(argparser_result->remainders) > 1)
		{
			shenv_singl_error(EXIT_FAILURE, "shift: too many arguments");
		}
		else if (twl_lst_len(argparser_result->remainders) == 0)
		{
			shift_action(env, "1");
		}
		else
		{
			shift_action(env, twl_lst_first(argparser_result->remainders));
		}
	}
	argparser_result_del(argparser_result);
}
