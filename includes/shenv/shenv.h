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

# include "twl_dict.h"
# include <errno.h>
# include "twl_arr.h"
# include "twl_arr2.h"

# define DEFAULT_FUNCTION_MAX_RECURSION_DEPTH 1000

typedef struct				s_shenv_info
{
	int						last_exit_status;
	int						cur_shell_pid;
	int						parent_shell_pid;
	int						most_recent_background_command_pid;
	char					*name;
}							t_shenv_info;

typedef struct				s_shenv
{
	t_lst					*shvars;
	t_lst					*pos_params;
	t_lst					*flags;
	t_dict					*alias;
	t_dict					*flag_verbose;
	t_dict					*shell_func;
	int						function_depth;
	t_shenv_info			info;
	t_lst					*jobs;
}							t_shenv;

t_shenv				*shenv_new(void);
void				shenv_del(t_shenv *this);
t_shenv				*shenv_clone(t_shenv *this);
void				shenv_init(t_shenv *this);
t_shvar				*shenv_setenv(t_shenv *this, char *str, char *command_name);
char				*shenv_getenv_value(t_shenv *this, char *key);
t_shvar				*shenv_setenv_value(t_shenv *t, char *k, char *v, char *command_name);

void				shenv_print(t_shenv *this);
void				shenv_unsetenv(t_shenv *this, char *str);
t_shenv				*shenv_singleton(void);
t_shenv				*shenv_singleton_setter(t_shenv *src_env);
int					shenv_flag_exist(t_shenv *this, char *flag);
char				*shenv_concat_flags(t_shenv *env);
void				shenv_print_flags(t_shenv *env);
void				shenv_print_all(t_shenv *this);
char				**shenv_get_paths(t_shenv *this);
void				shenv_add_flag(char *flag, t_shenv *env);
void				shenv_remove_flag(char *flag, t_shenv *env);
void				shenv_add_pos_param(char *param, t_shenv *env);
void				shenv_remove_all_pos_params(t_shenv *env);
char				*shenv_concat_pos_param_char(t_shenv *env, char *sep);
t_shvar				*shenv_get(t_shenv *this, char *key);
void				**shenv_get_env_arr(t_shenv *this);
int					shenv_get_last_exit_status(void);
void				shenv_set_last_exit_status(t_shenv *e, int status);
char				*shenv_get_pos_param_at(t_shenv *env, size_t index);

/*
** SHELL FUNCTIONS
*/
struct s_ast_compound_command;

void				shenv_remove_shell_func(t_shenv *env, char *key);
void				shenv_add_shell_func(t_shenv *env, char *key, struct s_ast_compound_command *data);
struct s_ast_compound_command	*shenv_get_shell_func(t_shenv *env, char *key);

#endif
