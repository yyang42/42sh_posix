/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_norris_loves_the_norminette.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuck <chuck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2042/02/30 42:00:00 by chuck             #+#    #+#             */
/*   Updated: 2042/02/30 42:59:59 by chuck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "patmatch.h"

static void			del_class_expr(t_class_expr *to_del)
{
	free(to_del->match);
	free(to_del);
}

static void			del_dict(void *key_, void *class_expr_)
{
	char			*key;
	t_dict			*class_expr;

	key = key_;
	class_expr = class_expr_;
	twl_dict_delone(class_expr, key, &del_class_expr);
}

void				patmatch_del_class_expr_(t_patmatch *this)
{
	t_lst			*keys;

	keys = twl_dict_keys(this->class_expr);
	twl_lst_iter(keys, &del_dict, this->class_expr);
	twl_lst_del(keys, &free);
}
