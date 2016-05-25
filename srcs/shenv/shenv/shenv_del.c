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

#include "shenv/shenv.h"
#include "twl_opt_elem.h"
#include "job_control/job.h"
#include "trap/trap.h"

void				shenv_del(t_shenv *this)
{
	if (!this)
		return ;
	shvar_mgr_del(this->shenv_shvars);
	if (this->shfuncs)
		twl_lst_del(this->shfuncs, NULL);
	twl_lst_del(this->shenv_pos_params, free);
	if (this->alias)
		twl_htab_del(this->alias, NULL);
	if (this->info.name)
		free(this->info.name);
	free(this->shenv_name);
	free(this->shenv_cur_cmd);
	free(this->shenv_read_buffer_db);
	if (this->shenv_binary_saved_path)
		free(this->shenv_binary_saved_path);
	if (this->jobs)
		twl_lst_del(this->jobs, job_del);
	twl_lst_del(this->shenv_traps, trap_del);
	if (this->shenv_binary_db)
		twl_htab_del(this->shenv_binary_db, NULL);
	free(this->shenv_current_directory);
	free(this);
}
