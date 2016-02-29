#include "arexp/arexp.h"
#include "twl_ctype.h"

long long		arexp_atoll_base(t_arexp *this, char *input, int base, t_token *token)
{
	long long	ret;
	long long	tmp;
	size_t		index;
	char		c;

	index = 0;
	tmp = 0;
	ret = 0;
	while ((c = input[index]))
	{
		if (twl_isdigit(c))
			tmp = c - '0';
		else if (twl_islower(c))
			tmp = c - 'a' + 10;
		else if (twl_isupper(c))
			tmp = c - 'A' + 36;
		else if (c == '@' || c == '_')
			tmp = c == '@' ? 62 : 63;
		else
		{
			arexp_set_error_msg(this, "invalid number: ", token);
			return (0);
		}
		if (tmp >= base)
		{
			arexp_set_error_msg(this, "value too great for base: ", token);
			return (0);
		}
		ret *= base;
		ret += tmp;
		index += 1;
	}
	return (0);
}

static int		get_base(char *input)
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

long long		arexp_atoll(t_arexp *this, t_token *token)
{
	char		*input;
	char		*sharp;
	long long	ret;
	int			base;

	input = twl_strdup(token->text);
	if (input[0] == '0' && (input[1] == 'X' || input[1] == 'x'))
	{
		ret = arexp_atoll_base(this, twl_strlowcase(input) + 2, 16, token);
	}
	else if (input[0] == '0')
	{
		ret = arexp_atoll_base(this, input + 1, 8, token);
	}
	else if ((sharp = twl_strchr(input, '#')))
	{
		if (sharp == input)
		{
			arexp_set_error_msg(this, "syntax error: operand expected got ", token);
			free(input);
			return (0);
		}
		if (!(base = get_base(input)))
		{
			arexp_set_error_msg(this, "base should be between 2 and 64 ; got ", token);
			free(input);
			return (0);
		}
		if (base < 36)
			arexp_atoll_base(this, twl_strlowcase(input) + (sharp - input + 1), base, token);
		else
			arexp_atoll_base(this, input + (sharp - input + 1), base, token);
	}
	free(input);
	return (ret);
}
