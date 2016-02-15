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

#include "builtin/set.h"
#include "twl_opt_elem.h"

void				set_opt_del(t_set_opt *opt)
{
	free(opt->cmd);
	free(opt->valid_opts);
	twl_lst_del(opt->positive_opts, twl_opt_elem_del);
	twl_lst_del(opt->negative_opts, twl_opt_elem_del);
	twl_lst_del(opt->args, free);
	free(opt);
}
