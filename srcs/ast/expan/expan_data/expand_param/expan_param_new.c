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

#include "ast/expan/ast_expan.h"

t_expan_param *expan_param_new(void)
{
	t_expan_param *expan_param;

	expan_param = twl_malloc_x0(sizeof(t_expan_param));
	expan_param->parameter = NULL;
	expan_param->word = NULL;
	expan_param->type = EXPAN_VAR;
	return (expan_param);
}
