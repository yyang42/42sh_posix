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

static void			struct_dirs_init(t_builtin_dirs *this, t_lst *tokens,
										t_shenv *shenv)
{
	this->shenv = shenv;
	this->result = NULL;
	this->token_copy = twl_lst_copy(tokens, NULL);
	this->print_fn = builtin_dirs_print_home;
	this->is_number_set = false;
	this->is_negative = false;
	this->number = 0;
}

static bool			set_number(t_builtin_dirs *this, char *text)
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
	this->is_number_set = true;
	this->number = (size_t)twl_atoi(text + 1);
	this->is_negative = (*text == '-');
	return (true);
}

static bool			builtin_dirs_error(char *text, char *msg)
{
	shenv_singl_error(1, "dirs: %s: %s", text, msg);
	argparser_print_help(builtin_dirs_argparser());
	return (false);
}

static bool			init_flag(t_builtin_dirs *this)
{
	size_t			index;
	t_token			*token;

	index = 1;
	while ((token = twl_lst_get(this->token_copy, index)))
	{
		if (*token->text == '-' && token->text[1] == '-' && !token->text[2])
			break ;
		else if (*token->text == '-' && set_number(this, token->text))
			twl_lst_popi(this->token_copy, index);
		else if (*token->text == '+' && set_number(this, token->text))
			twl_lst_popi(this->token_copy, index);
		else if (*token->text == '-')
			index += 1;
		else if (*token->text == '+')
			return (builtin_dirs_error(token->text, "invalid number"));
		else
			return (builtin_dirs_error(token->text, "does not take arguments"));
	}
	return (true);
}

void				builtin_dirs_exec(t_lst *tokens, t_shenv *shenv)
{
	t_builtin_dirs	this;

	struct_dirs_init(&this, tokens, shenv);
	if (!init_flag(&this))
		return ;
	this.result = argparser_parse_tokens(builtin_dirs_argparser(),
			this.token_copy);
	if (this.result->err_msg)
	{
		shenv_singl_error(1, this.result->err_msg);
		argparser_print_help(builtin_dirs_argparser());
		return ;
	}
	if (argparser_result_opt_is_set(this.result, "l"))
		this.print_fn = builtin_dirs_print_normal;
	if (argparser_result_opt_is_set(this.result, "c"))
		builtin_dirs_clear();
	else if (argparser_result_opt_is_set(this.result, "p"))
		builtin_dirs_new_line(&this);
	else if (argparser_result_opt_is_set(this.result, "v"))
		builtin_dirs_verbose(&this);
	else
		builtin_dirs_simple(&this);
	argparser_result_del(this.result);
	twl_lst_del(this.token_copy, NULL);
}
