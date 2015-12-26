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

char	*get_cmd_out(const char *cmd);
char	*sandbox_cmd(const char *cmd);
void	reset_sandbox(void);

# define mt_test_tokenizer(test_name, input, expected, debug) \
	static void test_## test_name(t_test *test) \
	{ \
		t_lst		*tokens; \
		char			*joined; \
		tokens = tokenizer_tokenize(input); \
		if (debug) \
		{ \
			token_mgr_print(tokens); \
		} \
		joined = token_mgr_strjoin(tokens); \
		mt_assert(strcmp(joined, expected) == 0); \
		free(joined); \
	}

# define mt_test_token_mgr_split(test_name, input, split_strings_str, expected, debug) \
	static void test_## test_name(t_test *test) \
	{ \
		t_lst			*tokens_list; \
		t_lst			*split_strings; \
		t_lst			*tokens; \
		char			*joined_str; \
		tokens = tokenizer_tokenize(input); \
		split_strings = twl_str_split_to_lst(split_strings_str, "_"); \
		tokens_list = token_mgr_split(tokens, split_strings); \
		joined_str = token_mgr_split_strjoin(tokens_list); \
		if (debug) \
		{ \
			token_mgr_print(tokens); \
			twl_printf("actual   {%s}\n", joined_str); \
			twl_printf("expected {%s}\n", expected); \
		} \
		mt_assert(strcmp(joined_str, expected) == 0); \
		free(joined_str); \
		twl_lst_del(split_strings, free); \
		twl_lst_del(tokens, free); \
		twl_lst_del(tokens_list, NULL); \
	}
#endif
