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

#include "expan/expan_param.h"

void				expan_param_print(t_expan_param *expan_param)
{
	twl_printf("\t\tType : %d\n", expan_param->type);
	twl_printf("\t\tParameter : %s\n", expan_param->parameter);
	twl_printf("\t\tWord : %s\n", expan_param->word);
}
