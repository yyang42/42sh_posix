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

#include "alias/alias_mgr.h"
#include "logger.h"
#include "data_utils.h"
#include "token/token_mgr.h"
#include "token/tokenizer.h"

static bool			is_command_separator(char *str)
{
	return (data_utils_is_control_operators_nl(str)
		|| data_utils_is_reserved_word(str));
}

static char			*expan_token(t_token *token, char **accumulator_ptr, t_htab *aliases, t_ast *ast)
{
	char			*found;
	// t_lst			*tokenized_tokens;
	// t_tokenizer		*tokenizer;

	(void)ast;
	found = twl_htab_get(aliases, token->text);
	if (found)
	{
		*accumulator_ptr = twl_strjoinfree(*accumulator_ptr, found, 'l');
		// tokenizer = tokenizer_new(found);
		// tokenized_tokens = tokenizer_tokenize(tokenizer);
		// if (tokenizer->err_msg)
		// {
		// 	twl_dprintf(2, "%s\n", tokenizer->err_msg);
		// 	tokenizer_del(tokenizer);
		// 	return (NULL);
		// }
		// twl_lst_extend(accumulator, tokenized_tokens);
		// if (ast)
		// {
		// 	twl_lst_extend(ast->tokens_ref_tracker, tokenized_tokens);
		// }
		// twl_lst_del(tokenized_tokens, NULL);
		// tokenizer_del(tokenizer);
		return (found);
	}
	return (NULL);
}

void				alias_mgr_expan_tokens(t_htab *aliases, t_lst *tokens, t_ast *ast)
{
	t_lst			*copy_tokens;
	t_token			*token;
	char			*alias;
	char			*accumulator;
	int				line;

	if (twl_lst_len(tokens))
		line = token_mgr_first(tokens)->line;
	else
		line = 1;
	copy_tokens = twl_lst_copy(tokens, NULL);
	accumulator = twl_strdup("");
	while (true)
	{
		token = twl_lst_pop_front(copy_tokens);
		if (!token || is_command_separator(token->text))
			break ;
		alias = expan_token(token, &accumulator, aliases, ast);
		if (alias)
		{
			twl_lst_pop_front(tokens);
			if (twl_str_ends_with(alias, " ") && twl_lst_len(copy_tokens))
				continue ;
		}
		break ;
	}

	// char *joined;
	t_lst			*tokenized_tokens;
	t_tokenizer		*tokenizer;
	if (twl_lst_len(tokens))
	{
		accumulator = twl_strjoinfree(accumulator, "  ", 'l');
		accumulator = twl_strjoinfree(accumulator, token_mgr_first(tokens)->text, 'l');
		twl_lst_pop_front(tokens);
	}
	// joined = twl_strjoin(accumulator, " ");
	tokenizer = tokenizer_new(accumulator);
	tokenizer->cur_line = line;
	tokenized_tokens = tokenizer_tokenize(tokenizer);
	twl_lst_extend_front(tokens, tokenized_tokens);
	free(accumulator);
}