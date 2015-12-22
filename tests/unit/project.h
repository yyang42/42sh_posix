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
		t_tokenizer		*tokenizer; \
		char			*joined; \
		tokenizer = tokenizer_new(input); \
		if (debug) \
		{ \
			token_mgr_print(tokenizer->tokens); \
		} \
		joined = token_mgr_strjoin(tokenizer->tokens); \
		mt_assert(strcmp(joined, expected) == 0); \
		free(joined); \
		tokenizer_del(tokenizer); \
	}

#endif
