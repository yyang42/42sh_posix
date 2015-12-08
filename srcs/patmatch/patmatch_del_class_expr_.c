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
	free(to_del->map);
	free(to_del);
}

void				patmatch_del_class_expr_(t_patmatch *this)
{
	twl_dict_delone(this->class_expr, "[:alnum:]", &del_class_expr);
	twl_dict_delone(this->class_expr, "[:alpha:]", &del_class_expr);
	twl_dict_delone(this->class_expr, "[:blank:]", &del_class_expr);
	twl_dict_delone(this->class_expr, "[:cntrl:]", &del_class_expr);
	twl_dict_delone(this->class_expr, "[:digit:]", &del_class_expr);
	twl_dict_delone(this->class_expr, "[:graph:]", &del_class_expr);
	twl_dict_delone(this->class_expr, "[:lower:]", &del_class_expr);
	twl_dict_delone(this->class_expr, "[:print:]", &del_class_expr);
	twl_dict_delone(this->class_expr, "[:punct:]", &del_class_expr);
	twl_dict_delone(this->class_expr, "[:space:]", &del_class_expr);
	twl_dict_delone(this->class_expr, "[:upper:]", &del_class_expr);
	twl_dict_delone(this->class_expr, "[:xdigit:]", &del_class_expr);
}
