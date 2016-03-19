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
#include "builtin/cmds/builtin_kill.h"

static int			conv_to_signal_num(char *sig)
{
	// twl_printf("sig %s\n", sig);
	(void)sig;
	return (-1);
}

static int			get_signal_num(t_token *token, char *signame, t_shenv *env)
{
	int				signum;

	signum = conv_to_signal_num(signame);
	if (signum == -1)
	{
		shenv_print_error_printf(env, token->line,
			"kill", "%s: invalid signal specification", signame);
		env->last_exit_code = EXIT_FAILURE;
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
	char			*signame;

	tokens_copy = twl_lst_copy(tokens, NULL);
	twl_lst_pop_front(tokens_copy);
	signame = NULL;
	if (twl_lst_len(tokens_copy) == 0)
	{
		print_usage();
		env->last_exit_code = EXIT_FAILURE;
	}
	else
	{
		if (token_mgr_first_equ(tokens_copy, "-l"))
		{
			builtin_kill_print_signals();
			env->last_exit_code = EXIT_SUCCESS;
			return ;
		}
		if (token_mgr_first_equ(tokens_copy, "-s"))
		{
			twl_lst_pop_front(tokens_copy);
			if (twl_lst_len(tokens_copy) == 0)
			{
				shenv_print_error_printf(env, token_mgr_first(tokens)->line,
					"kill", "-s: option requires an argument");
				env->last_exit_code = EXIT_FAILURE;
				return ;
			}
			else
			{
				signame = token_mgr_first(tokens_copy)->text;
				twl_lst_pop_front(tokens_copy);
			}
		}
		else if (twl_str_starts_with(token_mgr_first(tokens_copy)->text, "-"))
		{
			signame = token_mgr_first(tokens_copy)->text + 1;
			twl_lst_pop_front(tokens_copy);
		}
		if (signame)
		{
			get_signal_num(token_mgr_first(tokens), signame, env);
		}
	}
}
