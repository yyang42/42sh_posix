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

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

# include "basics.h"

# include "twl_dict.h"
# include <errno.h>
# include "twl_arr.h"
# include "twl_arr2.h"

# define READ_ONLY 1
# define NOT_READ_ONLY 0
# define DEFAULT_FUNCTION_MAX_RECURSION_DEPTH 1000

typedef enum				e_environment_var_type
{
	ENVIRONMENT,
	LOCAL
}							t_environment_var_type;

typedef struct				s_environment_info
{
	int						last_exit_status;
	int						cur_shell_pid;
	int						parent_shell_pid;
	int						most_recent_background_command_pid;
	char					*name;
}							t_environment_info;

typedef struct				s_environment
{
	t_lst					*env_vars;
	t_lst					*pos_params;
	t_lst					*flags;
	t_dict					*alias;
	t_dict					*flag_verbose;
	t_dict					*shell_func;
	int						function_depth;
	t_environment_info		info;
	t_lst					*jobs;
}							t_environment;

typedef struct				s_environment_var
{
	char					*evar_key;
	char					*evar_value;
	int						read_only;
	t_environment_var_type	type;
	int						evar_value_is_set;
}							t_environment_var;

t_environment				*environment_new(void);
void						environment_del(t_environment *this);
t_environment				*environment_clone(t_environment *this);
void						environment_init(t_environment *this);
t_environment_var			*environment_setenv(t_environment *this, char *str);
t_environment_var			*environment_setenv_v2(t_environment *this, char *key, char *value);
char						*environment_getenv_value(t_environment *this,
	char *key);
t_environment_var			*environment_setenv_value(t_environment *t,
	char *k, char *v, int value_is_set);
t_environment_var			*environment_var_new(char *key, char *value,
	t_environment_var_type type, bool value_is_set);
void						environment_print(t_environment *this);
void						environment_unsetenv(t_environment *this,
	char *str);
t_environment				*environment_singleton(void);
int							environment_flag_exist(t_environment *this,
	char *flag);
char						*environment_concat_flags(t_environment *env);
void						environment_print_flags(t_environment *env);
void						environment_print_all(t_environment *this);
char						**environment_get_paths(t_environment *this);
void						environment_add_flag(char *flag,
														t_environment *env);
void						environment_remove_flag(char *flag,
													t_environment *env);
void						environment_add_pos_param(char *param,
														t_environment *env);
void						environment_remove_all_pos_params(
														t_environment *env);
char						*environment_concat_pos_param_char(t_environment
	*env, char *sep);
t_environment_var			*environment_setenv_or_setlocal__(t_environment
	*this, char *key, char *value, t_environment_var_type type);
t_environment_var			*environment_get(t_environment *this, char *key);
void						**environment_get_env_arr(t_environment *this);
int							environment_get_last_exit_status(void);
void						environment_set_last_exit_status(int status);
void						environment_set_last_exit_status_2(t_environment *e,
																	int status);
char						*environment_get_pos_param_at(t_environment *env,
	size_t index);

/*
** SHELL FUNCTIONS
*/
struct s_ast_compound_command;

void						environment_remove_shell_func(t_environment *env,
																	char *key);
void						environment_add_shell_func(t_environment *env,
								char *key, struct s_ast_compound_command *data);
struct s_ast_compound_command	*environment_get_shell_func(t_environment *env,
														char *key);

#endif
