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

#ifndef SHVAR_H
# define SHVAR_H

# include "basics.h"

# define READ_ONLY 1
# define NOT_READ_ONLY 0

typedef enum				e_shvar_type
{
	ENVIRONMENT,
	LOCAL
}							t_shvar_type;

typedef struct				s_shvar
{
	char					*shvar_key;
	char					*shvar_value;
	int						shvar_read_only;
	t_shvar_type			shvar_type;
	int						shvar_value_is_set;
}							t_shvar;

t_shvar				*shvar_new(char *key, char *value, t_shvar_type type, bool value_is_set);
void				shvar_del(t_shvar *shvar);
void				shvar_del_void(t_shvar *shvar);

#endif
