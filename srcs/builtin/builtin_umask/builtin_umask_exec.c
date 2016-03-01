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

#include "builtin/builtin_umask.h"

int				read_octal(char *string)
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

static int		symbolic_umask(char *arg)
{
	int	um;
	int	bits;

	um = umask(022);
	umask(um);
	bits = parse_symbolic_mode(arg, ~um & 0777);
	if (bits == -1)
		return (-1);
	um = ~bits & 0777;
	return (um);
}

static int		modify_umask(t_opt *opt, char *arg)
{
	int		umask_value;
	mode_t	umask_arg;

	if (twl_isdigit(*arg))
	{
		umask_value = read_octal(arg);
		if (umask_value == -1)
		{
			error_octal_out_of_range(arg);
			return (BUILTIN_EXEC_FAILURE);
		}
	}
	else
	{
		umask_value = symbolic_umask(arg);
		if (umask_value == -1)
			return (BUILTIN_EXEC_FAILURE);
	}
	umask_arg = (mode_t)umask_value;
	umask(umask_arg);
	if (twl_opt_exist(opt, "-S"))
		print_symbolic_umask(umask_arg);
	return (BUILTIN_EXEC_SUCCESS);
}

static void		builtin_umask_2(t_opt *opt, int *flag)
{
	int				umask_arg;

	umask_arg = umask(022);
	umask(umask_arg);
	if (twl_opt_exist(opt, "S"))
	{
		print_symbolic_umask(umask_arg);
		*flag = BUILTIN_EXEC_SUCCESS;
	}
	else
		twl_printf("%04lo\n", (unsigned long)umask_arg);
}

int				builtin_umask_exec(t_lst *tokens, t_environment *this)
{
	t_opt			*opt;
	char			**arr;
	int				flag;
	char			*str;

	str = token_mgr_strjoin(tokens, " "); // TODO: refactor
	arr = twl_strsplit_mul(str, " \n\t");
	opt = twl_opt_new(arr, UMASK_OPT_VALID_OPTS);
	flag = BUILTIN_EXEC_FAILURE;
	if (!check_invalid_opts(opt, "umask", UMASK_OPT_VALID_OPTS))
	{
		if (twl_opt_args_len(opt) < 1)
			builtin_umask_2(opt, &flag);
		else
			flag = modify_umask(opt, (char *)twl_lst_first(opt->args));
	}
	environment_set_last_exit_status_2(this, flag);
	twl_arr_del(arr, &free);
	twl_opt_del(opt);
	return (flag);
}
