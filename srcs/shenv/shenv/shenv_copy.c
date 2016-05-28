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

t_shenv				*shenv_copy(t_shenv *this)
{
	t_shenv *copy;

	copy = twl_malloc_x0(sizeof(t_shenv));
	copy->shenv_name = twl_strdup(this->shenv_name);
	copy->shenv_cur_cmd = twl_strdup(this->shenv_cur_cmd);
	copy->shenv_shvars = twl_lst_copy(this->shenv_shvars, shvar_copy_void);
	copy->shenv_shflags = shflag_mgr_new();
	copy->shenv_prog_flags = this->shenv_prog_flags;
	copy->shfuncs = twl_lst_new();
	copy->shenv_pos_params = twl_lst_copy(this->shenv_pos_params, twl_strdup_void);
	copy->function_depth = this->function_depth;
	copy->info = this->info;
	copy->info.name = twl_strdup_or_null(this->info.name);
	copy->last_exit_code = EXIT_SUCCESS;
	copy->shenv_traps = twl_lst_new();
	copy->alias = twl_htab_new();
	copy->shenv_break_counter = this->shenv_break_counter;
	copy->shenv_continue_counter = this->shenv_continue_counter;
	copy->shenv_loop_level = this->shenv_loop_level;
	copy->shenv_return_triggered = copy->shenv_return_triggered;
	copy->shenv_is_function_or_script = this->shenv_is_function_or_script;
	copy->shenv_ignore_errexit = this->shenv_ignore_errexit;
	copy->shenv_is_inside_job_control = this->shenv_is_inside_job_control;
	copy->shenv_binary_db = NULL;
	copy->shenv_binary_saved_path = twl_strdup("");
	copy->shenv_read_buffer_db = twl_malloc_x0(sizeof(char *) * getdtablesize());
	copy->shenv_fork_level = this->shenv_fork_level;
	copy->shenv_home_pw_dir = twl_strdup_or_null(this->shenv_home_pw_dir);
	copy->shenv_has_syntax_error = 0;
	copy->shenv_read_remainder_ptr = NULL;
	shenv_set_read_buffer_ptr(copy, 0);;
	return (copy);
}
