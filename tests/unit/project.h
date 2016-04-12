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

#ifndef PROJECT_H
# define PROJECT_H

# define _GNU_SOURCE

# include <fw.h>
# include <string.h>
# include <ctype.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include "xopt.h"

char	*get_cmd_out(const char *cmd);
void	sandbox_cmd(const char *cmd);
void	reset_sandbox(void);

# define mt_test_tokenizer(test_name, input, expected, debug) \
	static void test_## test_name(t_test *test) \
	{ \
		t_lst			*tokens; \
		char			*joined; \
		tokens = tokenizer_utils_tokenize(input); \
		if (debug) \
		{ \
			token_mgr_print(tokens); \
		} \
		joined = token_mgr_strjoin(tokens, "_"); \
		mt_assert(strcmp(joined, expected) == 0); \
		free(joined); \
		token_mgr_del(tokens); \
	}

# define mt_test_tokenizer_arexp(test_name, input, expected, debug)	\
	static void test_## test_name(t_test *test)						\
	{																\
		t_lst			*tokens;									\
		char			*joined;									\
		tokens = tokenizer_arexp_tokenize(input);					\
		if (debug)													\
		{															\
			token_mgr_print(tokens);								\
		}															\
		joined = token_mgr_strjoin(tokens, "_");					\
		mt_assert(strcmp(joined, expected) == 0);					\
		free(joined);												\
		token_mgr_del(tokens);								\
	}

# define mt_test_expan(name, input, no, expectedtext, expectedtype, debug)	\
static void test_## name(t_test *test)										\
{																			\
	t_lst			*tokens = expan_tokenizer_tokenize(input);				\
	t_expan_token	*token = twl_lst_get(tokens, no);						\
	if (debug && token)														\
	{																		\
		printf("  input:    %s\n", input);									\
		printf("  actual:   %s\n", token->text);							\
		printf("  expected: %s\n", expectedtext);							\
	}																		\
	mt_assert(token != NULL);												\
	mt_assert(strcmp(token->text, expectedtext) == 0);						\
	mt_assert(token->type == expectedtype);									\
	twl_lst_del(tokens, expan_token_del);									\
}

# define mt_test_ast_error(test_name, input, expected, debug) \
	static void test_## test_name(t_test *test) \
	{ \
		t_ast			*ast; \
		xopt_singleton()->print_ast = true; \
		ast = ast_new(input); \
		if (debug) \
		{ \
			twl_printf("input    : %s\n", input); \
			twl_printf("actual   : %s\n", ast->error_msg); \
			twl_printf("expected : %s\n", expected); \
		} \
		mt_assert(ast->error_msg && strcmp(ast->error_msg, expected) == 0); \
		ast_del(ast); \
	}

#endif
