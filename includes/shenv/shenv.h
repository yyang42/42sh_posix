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

#ifndef SHENV_H
# define SHENV_H

# include "basics.h"
# include "shenv/shvar_mgr.h"
# include "shenv/shflag_mgr.h"

# include "twl_dict.h"
# include <errno.h>
# include "twl_arr.h"
# include "twl_htab.h"
# include "twl_arr2.h"
# include "twl_opt.h"
# include "token/token.h"

#include <sys/types.h>
#include <termios.h>
#include <unistd.h>
#include <signal.h>

# define DEFAULT_FUNCTION_MAX_RECURSION_DEPTH 1000
# define SHENV_DEFAULT_NAME "42sh"
# define SHENV_ERROR_COMMAND_NOT_FOUND "command not found"
# define SHENV_ERROR_FILE_NOT_FOUND "No such file or directory"
# define EXIT_COMMAND_NOT_FOUND 127
# define SHENV_DEFAULT_IFS " \t\n"
# define SHENV_SH_PATH_FALLBACK_WHEN_NO_SHEBANG "/bin/sh"
# define SHENV_FLAG_AST (1 << 1)
# define SHENV_FLAG_AREXP (1 << 2)
# define SHENV_FLAG_GNL (1 << 3)
# define SHENV_FLAG_EXIT_ON_AST_ERROR (1 << 4)

# define FTSH_VALID_SET_OPTS "abc:Cefhimnuvx"
# define FTSH_VALID_ALL_OPTS ":AGo:s"FTSH_VALID_SET_OPTS

# define SHENV_DEFAULT_HISTORY_FILE ".sh_history"

typedef struct				s_shenv_info
{
	int						saved_last_exit;
	int						cur_shell_pid;
	int						parent_shell_pid;
	int						most_recent_background_command_pid;
	char					*name;
}							t_shenv_info;

struct s_job;

typedef struct				s_shenv
{
	char					*shenv_name;
	char					*shenv_cur_cmd;
	char					*shenv_home_pw_dir;
	t_token					*shenv_cur_token;
	t_lst					*shenv_shvars;
	t_lst					*shenv_shflags;
	int						shenv_prog_flags;
	t_lst					*shenv_argv_remainder;
	t_lst					*shenv_pos_params;
	t_htab					*shenv_alias;
	t_dict					*shfuncs;
	int						function_depth;
	t_shenv_info			info;
	t_lst					*jobs;
	t_lst					*shenv_traps;
	int						last_exit_code;

	int						shenv_break_counter;
	int						shenv_continue_counter;
	int						shenv_loop_level;
	bool					shenv_return_triggered;
	bool					shenv_shall_quit_curr_ast;
	bool					shenv_is_function_or_script;
	bool					shenv_ignore_errexit;
	bool					shenv_is_inside_job_control;
	t_htab					*shenv_binary_db;
	char					*shenv_binary_saved_path;
	int						shenv_list_item_level;
	char					**shenv_read_remainder_ptr;
	char					**shenv_read_buffer_db;
	int						shenv_fork_level;
	char					*shenv_current_directory;
	bool					shenv_has_syntax_error;
}							t_shenv;

t_shenv				*shenv_new(void);
void				shenv_del(t_shenv *this);
t_shenv				*shenv_copy(t_shenv *this);
void				shenv_init(t_shenv *this);
void				shenv_init_shell_vars(t_shenv *this);
t_shvar				*shenv_shvars_set_split_by_equal(t_shenv *this,
					char *str, char *command_name);
char				*shenv_shvars_get_value(t_shenv *this, char *key);
t_shvar				*shenv_shvars_set(t_shenv *t,
					char *k, char *v, char *command_name);
t_shvar				*shenv_shvars_set_int(t_shenv *shenv,
					char *key, int intval, char *command_name);

void				shenv_print(t_shenv *this);
void				shenv_unsetenv(t_shenv *this, char *str);
t_shenv				*shenv_singleton(void);
t_shenv				*shenv_singleton_setter(t_shenv *src_env);
int					shenv_shflag_enabled(t_shenv *this, char *flag);
void				shenv_shflag_set(t_shenv *this, char mono, bool enabled);
void				shenv_print_flags(t_shenv *env);
void				shenv_print_all(t_shenv *this);
void				shenv_add_flag(char *flag, t_shenv *env);
void				shenv_remove_flag(char *flag, t_shenv *env);
void				shenv_add_pos_param(char *param, t_shenv *env);
void				shenv_remove_all_pos_params(t_shenv *env);
char				*shenv_concat_pos_param_char(t_shenv *env, char *sep);
t_shvar				*shenv_shvars_get(t_shenv *this, char *key);
void				**shenv_get_env_arr(t_shenv *this);
char				*shenv_get_pos_param_at(t_shenv *env, size_t index);
void				shenv_pos_params_copy_deep_from(t_shenv *env,
					t_lst *new_pos_params);

void				shenv_set_name(t_shenv *env, char *name);
void				shenv_set_cur_cmd(t_shenv *env, char *cur_cmd);
void				shenv_set_cur_token(t_shenv *env, t_token *token);
int					shenv_get_cur_line(void);
int					shenv_print_error_printf(t_shenv *this, int line,
											char *fmt, ...);
void				shenv_singl_error(int exit_code, char *fmt, ...);
void				shenv_singl_error_simple(int exit_code, char *fmt, ...);
void				shenv_increase_shlvl(t_shenv *this);
pid_t				shenv_utils_fork(void);
char				*shenv_find_binary_path(t_shenv *env, char *cmd);
void				shenv_build_binary_db(t_shenv *env);
void				shenv_set_binary_saved_path(t_shenv *env, char *path);
int					shenv_set_read_buffer_ptr(t_shenv *env, int fd);
void				shenv_clear_stdin_read_buffer(t_shenv *env);
void				shenv_execve(t_shenv *env, char *path, t_lst *argv_lst);
void				shenv_execve_findpath(t_shenv *env, t_lst *argv_lst);

char				**shenv_get_paths(t_shenv *this);
char				*shenv_get_ifs(t_shenv *this);
char				*shenv_get_home(t_shenv *this);

void				shenv_set_current_directory(t_shenv *this, char *fm_whom);
void				shenv_reset_current_directory(t_shenv *this, char *new_dir);
char				*shenv_get_current_directory(t_shenv *this, char *fm_whom);
void				shenv_print_ps4(t_shenv *this);
bool				shenv_is_dryrun(t_shenv *this);

/*
** exit
*/
void				shenv_exit_if_errexit_enabled(t_shenv *env);

/*
** loops
*/

void				shenv_loop_level_incr(t_shenv *this);
void				shenv_loop_level_decr(t_shenv *this);
void				shenv_break_counter_decr(t_shenv *this);
void				shenv_continue_counter_decr(t_shenv *this);
void				shenv_continue_counter_decr_if_one(t_shenv *this);
bool				shenv_should_continue_exec(t_shenv *this);

/*
** SHELL FUNCTIONS
*/
struct s_ast_function_def;

void				shenv_remove_shell_func(t_shenv *env, char *key);
void				shenv_add_shell_func(t_shenv *env, char *key, struct s_ast_function_def *data);
struct s_ast_function_def	*shenv_shfuncs_get(t_shenv *env, char *key);

#endif
