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

#include "arexp/arexp.h"
#include "twl_ctype.h"

static int			get_base(char *input)
{
	int			base;

	base = 0;
	if (twl_isdigit(input[0]))
	{
		base += input[0] - '0';
		if (twl_isdigit(input[1]))
		{
			base *= 10;
			base += input[1] - '0';
			if (input[2] != '#')
				return (0);
		}
		else if (input[1] != '#')
			return (0);
	}
	else
		return (0);
	if (base < 2 || base > 64)
		return (0);
	return (base);
}

static long long	get_value_other_base(t_arexp *this, char *input,
																t_token *token)
{
	char			*sharp;
	int				base;

	if ((sharp = twl_strchr(input, '#')))
	{
		if (sharp == input)
		{
			arexp_set_error_msg(this, "syntax error: operand expected got ",
																		token);
			return (0);
		}
		if (!(base = get_base(input)))
		{
			arexp_set_error_msg(this, "base should be between 2 and 64 ; got ",
																		token);
			return (0);
		}
		if (base < 36)
			return (arexp_atoll_base(this, twl_strlowcase(input) +
											(sharp - input + 1), base, token));
		else
			return (arexp_atoll_base(this, input +
											(sharp - input + 1), base, token));
	}
	return (arexp_atoll_base(this, input, 10, token));
}

long long			arexp_atoll(t_arexp *this, t_token *token)
{
	char		*input;
	long long	ret;

	input = twl_strdup(token->text);
	ret = 0;
	if (input[0] == '0' && (input[1] == 'X' || input[1] == 'x'))
		ret = arexp_atoll_base(this, twl_strlowcase(input) + 2, 16, token);
	else if (input[0] == '0')
		ret = arexp_atoll_base(this, input + 1, 8, token);
	else
		ret = get_value_other_base(this, input, token);
	free(input);
	return (ret);
}
