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

#include "builtin/builtin_export.h"
#include "environment.h"
#include "twl_opt.h"
#include "twl_lst.h"

static void			export_something_segs(void *data, void *context)
{
	t_environment	*env;
	t_lst			*segs;
	char			*joined;

	segs = data;
	env = context;
	joined = twl_lst_strjoin(segs, "=");
	if (segs)
	{
		environment_setenv(env, joined);
	}
	free(joined);
}

static void			export_something_tokens(void *token_, void *env)
{
	t_token			*token;

	token = token_;
	if (token)
	{
		// if (environment_getenv_value(this, key))
		environment_setenv(env, token->text);
	}
}

void				builtin_export_add(t_environment *env, t_lst *tokens)
{
	t_lst			*list_of_segs;
	t_lst			*remaining_tokens;
	t_lst			*tokens_copy;

	tokens_copy = twl_lst_copy(tokens, NULL);
	remaining_tokens = twl_lst_new();
	twl_lst_pop_front(tokens_copy);
	list_of_segs = token_mgr_extract_assignment(tokens_copy, remaining_tokens);
	twl_lst_iter(list_of_segs, export_something_segs, env);
	twl_lst_iter(remaining_tokens, export_something_tokens, env);
	(void)remaining_tokens;
}
