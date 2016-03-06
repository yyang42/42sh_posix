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

#include "builtin/builtin_read.h"
#include "twl_get_next_line.h"

static void			fn_read(t_lst *input)
{
	char			buf[16];
	int				ret;

	while ((ret = read(0, buf, 15)) >= 0)
	{
		buf[ret] = 0;
		twl_lst_push_back(input, twl_strdup(buf));
		if (ret != 15)
			break ;
	}
}

static void			fn_iter(void *data)
{
	twl_printf("%s\n", data);
}

int					builtin_read_exec(t_lst *tokens, t_environment *this)
{
	t_lst			*copy;
	t_lst			*input;
	bool			opt_r;

	opt_r = false;
	copy = twl_lst_copy(tokens, NULL);
	input = twl_lst_new();
	twl_lst_pop_front(copy);
	if (token_mgr_first_equ(copy, "-r"))
	{
		opt_r = true;
		twl_lst_pop_front(copy);
	}
	fn_read(input);
	twl_lst_iter0(input, fn_iter);
	(void)this;
	return (0);
}
