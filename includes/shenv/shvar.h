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

typedef struct				s_shvar
{
	char					*shvar_key;
	char					*shvar_value;
	int						shvar_read_only;
	bool					shvar_exported;
}							t_shvar;

t_shvar				*shvar_new(char *key, char *value, bool exported);
void				shvar_del(t_shvar *shvar);
void				shvar_del_void(t_shvar *shvar);
t_shvar				*shvar_copy(t_shvar *src);
void				*shvar_copy_void(void *src);

#endif