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

#ifndef OPENCLOSE_H
# define OPENCLOSE_H

# include "basics.h"

typedef struct		s_openclose
{
	char			*open;
	char			*close;
	char			*pos;
}					t_openclose;

t_openclose			*openclose_new(char *open, char *close);
void				openclose_del(t_openclose *this);

#endif
