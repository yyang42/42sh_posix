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
	t_edit				*edit;
}						t_completion;

t_completion			*completion_new(t_edit *edit);
void					completion_del(t_completion *this);

void					completion_dirs(t_completion *this);
void					completion_exec(t_completion *this);
void					completion_variable(t_completion *this);
void					completion_brace_variable(t_completion *this);

bool					completion_utils_start_with(char *base, char *prefix);

#endif
