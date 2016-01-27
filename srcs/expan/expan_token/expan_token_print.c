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

#include "expan/expan_token.h"
#include "expan/expan_utils.h"

void				expan_token_print(t_expan_token *expan_token)
{
	void	(*print_func)(void*);
	void	*raw_func;

	twl_printf("**********************\n");
	twl_printf("\tType : %d\n", expan_token->type);
	twl_printf("\tRes : %s\n", expan_token->res);
	twl_printf("\tDouble quote : %d\n", expan_token->is_double_quoted);
	twl_printf("\tOrigin : %d\n", expan_token->origin);
	raw_func = expan_param_type_to_print_func(expan_token->type);
	print_func = raw_func;
	if (print_func && expan_token->expan_data)
	{
		print_func(expan_token->expan_data);
	}
	twl_printf("**********************\n");
}
