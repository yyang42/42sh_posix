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
#include "job_control/job_mgr.h"
#include "trap/trap.h"
#include "ast/nodes/ast_function_def.h"

static void			del_shenv_read_buffer_db(char **shenv_read_buffer_db)
{
	int				size;
	int				i;

	size = getdtablesize();
	i = 0;
	while (i < size)
	{
		free(shenv_read_buffer_db[i]);
		i++;
	}
	free(shenv_read_buffer_db);
}

void				shenv_del(t_shenv *this)
{
	if (!this)
		return ;
	shvar_mgr_del(this->shenv_shvars);
	twl_lst_del(this->shfuncs, ast_function_def_del_void);
	twl_lst_del(this->shenv_pos_params, free);
	twl_htab_del(this->shenv_alias, free);
	free(this->info.name);
	free(this->shenv_name);
	free(this->shenv_cur_cmd);
	del_shenv_read_buffer_db(this->shenv_read_buffer_db);
	free(this->shenv_binary_saved_path);
	job_mgr_del(this->jobs);
	twl_lst_del(this->jobs_allocated, NULL);
	twl_lst_del(this->shenv_traps, trap_del);
	twl_htab_del(this->shenv_binary_db, free);
	free(this->shenv_current_directory);
	twl_lst_del(this->shenv_argv_remainder, NULL);
	shflag_mgr_del(this->shenv_shflags);
	free(this->shenv_home_pw_dir);
	free(this);
}
