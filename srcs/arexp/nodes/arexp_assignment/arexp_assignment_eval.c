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

#include "arexp/nodes/arexp_assignment.h"

//static void			fn_iter(void *token_, void *ret)
//{
//	t_token			**token;
//	char			*old_value;
//	int				sign;
//	long long		ll_value;
//
//	token = token_;
//	old_value = environment_getenv_value(environment_singleton, token[0]->text);
//	if (!old_value)
//
//
//
//}

long long			arexp_assignment_eval(t_arexp_assignment *this)
{
	long long		ret;

	ret = arexp_condition_eval(this->condition);
//	twl_lst_iter(this->assign, fn_iter, &ret);
	return (ret);
}
