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


#include "xopt.h"
#include "twl_opt_elem.h"

#include "shenv/shenv.h"

void				shenv_del(t_shenv *this)
{
	if (!this)
		return ;
	shvar_mgr_del(this->shvars);
	if (this->flag_verbose)
		twl_lst_del(this->flag_verbose, NULL);
	if (this->shfuncs)
		twl_lst_del(this->shfuncs, NULL);
	twl_lst_del(this->flags, twl_opt_elem_del);
	twl_lst_del(this->pos_params, free);
	if (this->alias)
		twl_lst_del(this->alias, NULL);
	if (this->info.name)
		free(this->info.name);
	free(this);
}
