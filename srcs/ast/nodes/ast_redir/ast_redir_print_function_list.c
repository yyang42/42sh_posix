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

#include "ast/nodes/ast_redir.h"

static void			iter_redir_fn(void *data, void *ctx1, void *ctx2)
{
	t_ast_redir		*this;

	this = data;
	if (this->heredoc_text)
		return ;
	*(size_t *)ctx2 += 1;
	if (this->io_number != IO_NUMBER_NOT_DEFINED)
	{
		twl_putnbr(this->io_number);
	}
	if (this->operator[1] == '&')
	{
		if (this->io_number == IO_NUMBER_NOT_DEFINED)
			twl_printf(this->operator[0] == '>' ? "1%s%s" : "0%s%s",
					this->operator, this->param->text);
		else
			twl_printf("%s%s", this->operator, this->param->text);
	}
	else
		twl_printf("%s %s", this->operator, this->param->text);
	if (*(size_t *)ctx1 > *(size_t *)ctx2)
	{
		twl_putchar(' ');
	}
}

static void			iter_heredoc_fn(void *data)
{
	t_ast_redir		*this;

	this = data;
	if (!this->heredoc_text)
		return ;
	if (this->io_number != IO_NUMBER_NOT_DEFINED)
	{
		twl_putnbr(this->io_number);
	}
	twl_printf(" %s%s\n%s%s\n", this->operator, this->param->text,
			this->heredoc_text_unexpanded, this->param->text);
}

void				ast_redir_print_function_list(t_lst *redir_items)
{
	size_t			len;
	size_t			sum;

	len = twl_lst_len(redir_items);
	if (len == 0)
		return ;
	sum = 0;
	twl_lst_iter2(redir_items, iter_redir_fn, &len, &sum);
	if (sum == len)
		return ;
	twl_lst_iter0(redir_items, iter_heredoc_fn);
}
