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

#ifndef SIMPLE_CHAR_H
# define SIMPLE_CHAR_H

# include "edit/edit.h"

typedef struct		s_simple_char
{
	unsigned char	simple;
	void			(*apply_fn)(t_edit *);
}					t_simple_char;

t_simple_char		*simple_char_new(unsigned char simple,
						void (*fn)(t_edit *));
void				simple_char_del(t_simple_char *this);

#endif
