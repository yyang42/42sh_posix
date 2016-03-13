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

#include "builtin/builtin.h"

static int			conv_to_signal_num(char *sig)
{
	// twl_printf("sig %s\n", sig);
	(void)sig;
	return (-1);
}

static int			get_signal_num(t_lst *tokens, t_shenv *env)
{
	t_token			*first_arg_token;
	char			*signame;
	int				signum;

	first_arg_token = twl_lst_pop_front(tokens);
	signame = first_arg_token->text + 1;
	signum = conv_to_signal_num(signame);
	if (signum == -1)
	{
		shenv_print_error_printf(env, first_arg_token->line,
			"kill", "%s: invalid signal specification", signame);
	}
	return (signum);
}

static void			print_usage(void)
{
	twl_dprintf(2,
		"kill: usage: kill [-s sigspec | -n signum | -sigspec] "
		"pid | jobspec ... or kill -l [sigspec]\n"
	);
}

void				builtin_kill_exec(t_lst *tokens, t_shenv *env)
{
	t_lst			*tokens_copy;
	int				signum;

	tokens_copy = twl_lst_copy(tokens, NULL);
	twl_lst_pop_front(tokens_copy);
	if (twl_lst_len(tokens_copy) == 0)
	{
		print_usage();
	}
	else
	{
		if (twl_str_starts_with(token_mgr_first(tokens_copy)->text, "-"))
		{
			signum = get_signal_num(tokens_copy, env);
			(void)signum;
		}
	}
}
