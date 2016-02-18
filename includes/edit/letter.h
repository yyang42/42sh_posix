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

#ifndef LETTER_H
# define LETTER_H

# include "basics.h"

typedef struct		s_letter
{
	char			letter[2];
}					t_letter;

t_letter			*letter_new(int letter);
void				letter_del(t_letter *this);
t_letter			*letter_cpy(t_letter *letter);
void				*letter_copy_void(void *letter);

#endif
