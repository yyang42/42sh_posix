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

#include "builtin/cmds/builtin_dirs.h"
#include "twl_ctype.h"

static bool		set_number(char *text, bool *is_number_set, int *number)
{
	size_t		index;

	index = 1;
	if (text[index] == 0)
		return (false);
	while (text[index])
	{
		if (!twl_isdigit(text[index]))
			return (false);
		index += 1;
	}
	*is_number_set = true;
	*number = twl_atoi(text + 1);
	return (true);
}

static void		iter_fn(void *data) { twl_printf("%s\n", data); }

void			builtin_dirs_exec(t_lst *tokens, t_shenv *shenv)
{
	t_lst		*copy;
	t_token		*token;
	size_t		index;
	bool		is_number_set;
	bool		is_neg;
	int			number;
	t_argparser_result	*result;

	copy = twl_lst_copy(tokens, NULL);
	index = 1;
	is_number_set = false;
	while ((token = twl_lst_get(copy, index)))
	{
		if (*token->text == '-' || *token->text == '+')
		{
			if (token->text[0] == '-' && token->text[1] == '-' && !token->text[2])
				break ;
			if (set_number(token->text, &is_number_set, &number))
			{
				is_neg = (*token->text == '-');
				twl_lst_popi(copy, index);
			}
			else if (*token->text == '+')
			{
				shenv_singl_error(1, "dirs: %s: invalid number", token->text);
				argparser_print_help(builtin_dirs_argparser());
				return ;
			}
			else
			{
				index += 1;
			}
		}
		else
		{
			shenv_singl_error(1, "dirs: %s: does not take arguments", token->text);
			argparser_print_help(builtin_dirs_argparser());
			return ;
		}
	}
	result = argparser_parse_tokens(builtin_dirs_argparser(), copy);
	if (result->err_msg)
	{
		shenv_singl_error(1, result->err_msg);
		argparser_print_help(builtin_dirs_argparser());
		return ;
	}
	twl_lst_iter0(result->remainders, iter_fn);
	twl_lst_del(copy, NULL);
	(void)shenv;
}
