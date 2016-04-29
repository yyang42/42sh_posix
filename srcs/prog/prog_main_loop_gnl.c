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

#include "prog.h"
#include "ast/ast.h"

#include "twl_gnl.h"


#include <stdio.h> // remove
#include <stdlib.h>

static void			exec_input(char *input)
{
	ast_exec_string(input);;
}
/*
void				prog_main_loop_gnl(t_prog *prog)
{
	char      *input;
	char      *remain;

	remain = NULL;
	input = NULL;
	twl_printf("GNL Line Edit\n");
	while (true)
	{
		twl_printf("$ ");
		if (twl_gnl(0, &input, &remain))
		{
			exec_input(input);
			free(input);
		}
		else
		{
			break ;
		}
	}
	(void)prog;
}
*/

#define BUFF_SIZE 1000

void				prog_main_loop_gnl(t_prog *prog)
{
	char			buff[BUFF_SIZE + 1];
	int				ret;
	int				errno_save;

	while (true)
	{
		ret = read(0, buff, BUFF_SIZE);
		errno_save = errno;
		printf("ret %d\n", ret);
		if (ret < 0)
		{
			twl_dprintf(2, "[error] %s\n", strerror(errno_save));
			exit(1);
		}
		else if (ret == 0)
		{
			twl_dprintf(2, "ret zero");
		}
		else
		{
			buff[ret] = 0;
			twl_printf("read: {%s}\n", buff);
			twl_printf("====== before exec\n");
			exec_input(buff);
			twl_printf("====== after exec\n");
		}
	}
	(void)prog;
	(void)exec_input;
}
