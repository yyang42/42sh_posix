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

#include "expan/expan_tokenizer.h"
#include "twl_ctype.h"

/*
** Prompt case \ sequence.
**   \a  : \007 ring bell
**   \d  : the date in “Weekday Month Date” format (e.g., “Tue May 26”)
**   \e  : \033 escape character
**   \h  : the hostname up to the first '.'
**   \H  : the hostname
**   \j  : the number of jobs currently managed by the shell
**   \n  : newline
**   \r  : carriage return
**   \t  : the current time in 24-hour HH:MM:SS format
**   \T  : the current time in 12-hour HH:MM:SS format
**   \@  : the current time in 12-hour am/pm format
**   \A  : the current time in 24-hour HH:MM format
**   \u  : the username of the current user
**   \w  : the current working directory, with $HOME abbreviated with a tilde
**   \W  : the basename of the current working directory,
**         with $HOME abbreviated with a tilde
**   \nnn: the character corresponding to the octal number nnn
**   \xnn: the character corresponding to the hexa number nn
**   \\  : a backslash
*/

static void			simple_char_fn(t_expan_tokenizer *this)
{
	if (this->to_push_index != 0)
		expan_tokenizer_delimit(this, EXPAN_NONE);
	expan_tokenizer_addone(this);
	expan_tokenizer_addone(this);
	expan_tokenizer_delimit(this, EXPAN_PROMPT);
	this->is_last_colon = false;
}

static void			number_fn(t_expan_tokenizer *this)
{
	if (this->to_push_index != 0)
		expan_tokenizer_delimit(this, EXPAN_NONE);
	expan_tokenizer_addone(this);
	expan_tokenizer_addone(this);
	expan_tokenizer_addone(this);
	expan_tokenizer_addone(this);
	expan_tokenizer_delimit(this, EXPAN_PROMPT_NUMBER);
	this->is_last_colon = false;
}

static bool			isodigit_fn(int num)
{
	return (num >= '0' && num <= '7');
}

t_rule_expan_status	expan_tokenizer_apply_rule_prompt(t_expan_tokenizer *this)
{
	char			c;

	if (this->input[this->input_index] == '\\')
	{
		c = this->input[this->input_index + 1];
		if (c == 'a' || c == 'd' || c == 'e' || c == 'h' || c == 'H' ||
				c == 'j' || c == 'n' || c == 'r' || c == 't' || c == 'T' ||
				c == '@' || c == 'A' || c == 'u' || c == 'U' || c == 'w' ||
				c == 'W' || c == '\\' || c == '[' || c == ']')
		{
			simple_char_fn(this);
			return (EXPAN_STATUS_APPLIED);
		}
		if ((isodigit_fn(c) &&
				isodigit_fn(this->input[this->input_index + 2]) &&
				isodigit_fn(this->input[this->input_index + 3])) ||
			((c == 'x' || c == 'X') &&
				twl_isxdigit(this->input[this->input_index + 2]) &&
				twl_isxdigit(this->input[this->input_index + 3])))
		{
			number_fn(this);
			return (EXPAN_STATUS_APPLIED);
		}
	}
	return (EXPAN_STATUS_NOT_APPLIED);
}
