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

#ifndef EXPANSION_PARAMETER_BRACE_H
# define EXPANSION_PARAMETER_BRACE_H

# include "basics.h"
# include "expan/expansion.h"
# include "twl_ctype.h"

typedef enum			e_brace_type
{
	BRACE_NONE = 0,
	BRACE_COLON_HYPHEN = 1,
	BRACE_COLON_EQUAL = 2,
	BRACE_COLON_QMARK = 3,
	BRACE_COLON_PLUS = 4,
	BRACE_HYPHEN = 5,
	BRACE_EQUAL = 6,
	BRACE_QMARK = 7,
	BRACE_PLUS = 8,
	BRACE_LENGTH = 9,
	BRACE_SHARP = 10,
	BRACE_PERCENT = 11,
	BRACE_SHARP_SHARP = 12,
	BRACE_PERCENT_PERCENT = 13,
	BRACE_NOT_APPLIED,
	BRACE_ERROR
}						t_brace_type;

typedef struct			s_expansion_brace
{
	char				*param;
	char				*word;
	t_brace_type		type;
	char				*error;
	size_t				index;
}						t_expansion_brace;

t_expansion_brace		*expansion_brace_new(char *input);
void					expansion_brace_del(t_expansion_brace *this);

bool					expansion_brace_length_case_applied(
										t_expansion_brace *this, char *input);
void					expansion_brace_flush_before(t_expansion_brace *this,
																char *input);
void					expansion_brace_flush_token(t_expansion_brace *this,
																char *input);

void					expansion_brace_set_error(t_expansion_brace *this,
														char *input, char *msg);

void					expansion_brace_none(t_expansion *this,
												t_expansion_brace *eb);
void					expbrace_none_special(t_expansion *this,
												t_expansion_brace *eb);

void					expansion_brace_colon_hyphen(t_expansion *this,
												t_expansion_brace *eb);
void					expbrace_colon_hyphen_special(t_expansion *this,
												t_expansion_brace *eb);

void					expansion_brace_colon_equal(t_expansion *this,
												t_expansion_brace *eb);

void					expansion_brace_colon_qmark(t_expansion *this,
												t_expansion_brace *eb);
void					expbrace_colon_qmark_special(t_expansion *this,
												t_expansion_brace *eb);

void					expansion_brace_colon_plus(t_expansion *this,
												t_expansion_brace *eb);
void					expbrace_colon_plus_special(t_expansion *this,
												t_expansion_brace *eb);

void					expansion_brace_hyphen(t_expansion *this,
												t_expansion_brace *eb);
void					expbrace_hyphen_special(t_expansion *this,
												t_expansion_brace *eb);

void					expansion_brace_equal(t_expansion *this,
												t_expansion_brace *eb);

void					expansion_brace_qmark(t_expansion *this,
												t_expansion_brace *eb);
void					expbrace_qmark_special(t_expansion *this,
												t_expansion_brace *eb);

void					expansion_brace_plus(t_expansion *this,
												t_expansion_brace *eb);
void					expbrace_plus_special(t_expansion *this,
												t_expansion_brace *eb);

void					expansion_brace_length(t_expansion *this,
												t_expansion_brace *eb);

void					expansion_brace_sharp(t_expansion *this,
												t_expansion_brace *eb);
void					expbrace_sharp_special(t_expansion *this,
												t_expansion_brace *eb);

void					expansion_brace_percent(t_expansion *this,
												t_expansion_brace *eb);
void					expbrace_percent_special(t_expansion *this,
												t_expansion_brace *eb);

void					expansion_brace_sharpsharp(t_expansion *this,
												t_expansion_brace *eb);
void					expbrace_sharpsharp_special(t_expansion *this,
												t_expansion_brace *eb);

void					expansion_brace_percentpercent(t_expansion *this,
												t_expansion_brace *eb);
void					expbrace_percentpercent_special(t_expansion *this,
												t_expansion_brace *eb);

void					expansion_brace_hyphen_solve(t_expansion *this,
												char *word);
void					expansion_brace_equal_solve(t_expansion *this,
												t_expansion_brace *eb);
void					expansion_brace_qmark_solve(t_expansion *this,
												t_expansion_brace *eb);
void					expansion_brace_plus_solve(t_expansion *this,
												t_expansion_brace *eb);

typedef void			(*t_expbrace_fn)(t_expansion *this,
											t_expansion_brace *eb);

#endif
