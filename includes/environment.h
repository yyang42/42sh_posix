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

typedef enum				e_environment_var_type
{
	ENVIRONMENT,
	LOCAL
}							t_environment_var_type;

typedef struct				s_environment
{
	t_lst					*env_vars;
	t_lst					*pos_params;
	t_lst					*flags;
	t_dict					*flag_verbose;
}							t_environment;

typedef struct				s_environment_var
{
	char					*key;
	char					*value;
	int						read_only;
	t_environment_var_type	type;
}							t_environment_var;

t_environment				*environment_new(void);
void						environment_del(t_environment *this);
t_environment				*environment_clone(t_environment *this);
void						environment_init_env(t_environment *this);
void						environment_setenv(t_environment *this, char *str);
char						*environment_getenv_value(t_environment *this,
	char *key);
int							environment_setenv_value(t_environment *t,
	char *k, char *v);
t_environment_var			*environment_var_new(char *key, char *value,
	t_environment_var_type type);
void						environment_print_env(t_environment *this);
void						environment_unsetenv(t_environment *this,
	char *str);
t_environment				*environment_singleton(void);
int							environment_flag_exist(t_environment *this,
	char *flag);
char						*environment_concat_flags(t_environment *env);
void						environment_print_flags(t_environment *env);
char						**environment_get_paths(t_environment *this);
#endif
