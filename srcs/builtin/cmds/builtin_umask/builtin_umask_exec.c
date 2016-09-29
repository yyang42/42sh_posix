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

#include "builtin/cmds/builtin_umask.h"

int					read_octal(char *string)
{
	int result;
	int digits;

	result = 0;
	digits = 0;
	while (*string && ISOCTAL(*string))
	{
		digits++;
		result = (result * 8) + (*string++ - '0');
		if (result > 0777)
			return (-1);
	}
	if (digits == 0 || *string)
		result = -1;
	return (result);
}

static int			symbolic_umask(char *arg)
{
	int	um;
	int	bits;

	um = umask(022);
	umask(um);
	bits = builtin_umask_parse_symbolic_mode(arg, ~um & 0777);
	if (bits == -1)
		return (-1);
	um = ~bits & 0777;
	return (um);
}

static int			modify_umask(
		t_argparser_result *argparser_result, char *arg)
{
	int		umask_value;
	mode_t	umask_arg;

	if (twl_isdigit(*arg))
	{
		umask_value = read_octal(arg);
		if (umask_value == -1)
		{
			shenv_singl_error(EXIT_FAILURE,
					"umask: %s: octal number out of range", arg);
			return (EXIT_FAILURE);
		}
	}
	else
	{
		umask_value = symbolic_umask(arg);
		if (umask_value == -1)
			return (EXIT_FAILURE);
	}
	umask_arg = (mode_t)umask_value;
	umask(umask_arg);
	if (argparser_result_opt_is_set(argparser_result, "S"))
		builtin_umask_print_symbolic(umask_arg);
	return (EXIT_SUCCESS);
}

static void			builtin_umask_2(t_argparser_result *argparser_result)
{
	int				umask_arg;

	umask_arg = umask(022);
	umask(umask_arg);
	if (argparser_result_opt_is_set(argparser_result, "S"))
	{
		builtin_umask_print_symbolic(umask_arg);
	}
	else
	{
		twl_printf("%04lo\n", (unsigned long)umask_arg);
	}
}

void				builtin_umask_exec(t_lst *tokens, t_shenv *env)
{
	t_argparser_result	*argparser_result;
	int					flag;

	argparser_result = argparser_parse_tokens(
			builtin_umask_argparser(), tokens);
	flag = EXIT_SUCCESS;
	if (argparser_result->err_msg)
	{
		argparser_result_print_usage_exit_status(argparser_result, 2);
		argparser_result_del(argparser_result);
		return ;
	}
	else
	{
		if (twl_lst_len(argparser_result->remainders) == 0)
			builtin_umask_2(argparser_result);
		else
			flag = modify_umask(argparser_result,
					(char *)twl_lst_first(argparser_result->remainders));
	}
	env->last_exit_code = flag;
	argparser_result_del(argparser_result);
}
