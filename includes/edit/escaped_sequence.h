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

#ifndef ESCAPED_SEQUENCE_H
# define ESCAPED_SEQUENCE_H

# include "edit/edit.h"

typedef struct		s_escaped_sequence
{
	char			*sequence;
	void			(*apply_fn)(t_edit *);
}					t_escaped_sequence;

t_escaped_sequence	*escaped_sequence_new(char *sequence, void (*fn)(t_edit *));
void				escaped_sequence_del(t_escaped_sequence *this);

#endif
