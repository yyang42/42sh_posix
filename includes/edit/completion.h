/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_norris_loves_the_norminette.h                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuck <chuck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2042/02/30 42:00:00 by chuck             #+#    #+#             */
/*   Updated: 2042/02/30 41:59:59 by chuck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLETION_H
# define COMPLETION_H

# include "basics.h"
# include "edit/edit.h"

typedef enum			e_completion_type
{
	COMPLETION_DIRS,
	COMPLETION_EXEC,
	COMPLETION_VARIABLE,
	COMPLETION_BRACE_VARIABLE
}						t_completion_type;

typedef struct			s_completion
{
	t_completion_type	type;
	char				*current_word;
	size_t				current_len;
	t_edit				*edit;
	t_lst				*all;
}						t_completion;

typedef struct			s_completion_path
{
	char				*begin;
	char				*end;
}						t_completion_path;

t_completion			*completion_new(t_edit *edit);
void					completion_del(t_completion *this);

void					completion_dirs(t_completion *this);
void					completion_exec(t_completion *this);
void					completion_exec_from_cwd(t_completion *this);
void					completion_exec_from_root(t_completion *this);
void					completion_exec_from_shenv(t_completion *this);
void					completion_variable(t_completion *this);
void					completion_brace_variable(t_completion *this);

bool					completion_utils_start_with(char *base, char *prefix);
char					*completion_utils_get_begin_list(t_completion *this);
void					completion_utils_print_lst(t_completion *this);
bool					completion_utils_exec_absolute_path(t_completion *this);

void					completion_path_init(t_completion_path *this,
							t_completion *completion);
void					completion_path_clear(t_completion_path *this);

void					completion_path_exec_readfile(t_completion *this,
							t_completion_path *path);

bool					completion_path_utils_is_begin_dot(char *p);
char					*completion_path_utils_join_path(char *beg, char *end);
char					*completion_path_utils_get_begin_list(
							t_completion *this,
							t_completion_path *path);

#endif
