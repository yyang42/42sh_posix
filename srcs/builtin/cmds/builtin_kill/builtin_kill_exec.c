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
	(void)sig;
	return (-1);
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
	t_lst			*token_copy;
	t_token			*cmd_name_token;
	t_token			*first_arg_token;
	char			*signame;
	int				signum;

	token_copy = twl_lst_copy(tokens, NULL);
	cmd_name_token = twl_lst_pop_front(token_copy);
	if (twl_lst_len(token_copy) == 0)
	{
		print_usage();
	}
	else
	{
		if (twl_str_starts_with(token_mgr_first(token_copy)->text, "-"))
		{
			first_arg_token = twl_lst_pop_front(token_copy);
			signame = first_arg_token->text + 1;
			signum = conv_to_signal_num(signame);
			if (signum == -1)
			{
				shenv_print_error_printf(env, token_mgr_first(tokens)->line,
					"kill", "%s: invalid signal specification", signame);
			}
		}
	}
}
