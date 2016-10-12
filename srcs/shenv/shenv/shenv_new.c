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

#include "twl_xstdlib.h"

#include "shenv/shenv.h"

void			shenv_new2(t_shenv *this)
{
	this->jobs = twl_lst_new();
	this->jobs_allocated = twl_lst_new();
	this->shenv_traps = twl_lst_new();
	this->last_exit_code = EXIT_SUCCESS;
	this->shenv_cur_token = NULL;
	this->shenv_break_counter = 0;
	this->shenv_continue_counter = 0;
	this->shenv_loop_level = 0;
	this->shenv_return_triggered = 0;
	this->shenv_is_function_or_script = 0;
	this->shenv_ignore_errexit = false;
	this->shenv_is_inside_job_control = false;
	this->shenv_binary_saved_path = twl_strdup("");
	this->shenv_read_buffer_db = twl_malloc_x0(sizeof(char *)
		* getdtablesize());
	this->shenv_fork_level = 0;
	this->shenv_has_syntax_error = 0;
	this->shenv_read_remainder_ptr = NULL;
	this->shenv_foreground_job = NULL;
}

t_shenv			*shenv_new(void)
{
	t_shenv		*this;

	this = twl_malloc_x0(sizeof(t_shenv));
	this->shenv_shvars = twl_lst_new();
	this->shenv_shflags = shflag_mgr_new();
	this->shenv_prog_flags = 0;
	this->shenv_argv_remainder = NULL;
	this->shenv_home_pw_dir = NULL;
	this->shenv_name = twl_strdup(SHENV_DEFAULT_NAME);
	this->shenv_cur_cmd = twl_strdup(SHENV_DEFAULT_NAME);
	this->shenv_alias = twl_htab_new();
	this->shfuncs = twl_dict_new();
	this->shenv_pos_params = twl_lst_new();
	this->info.name = NULL;
	this->function_depth = 0;
	shenv_new2(this);
	shenv_set_read_buffer_ptr(this, 0);
	return (this);
}
