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

#ifndef SHFLAG_H
# define SHFLAG_H

# include "basics.h"

typedef struct		s_shflag
{
	char			shf_mono;
	char			*shf_long;
	bool			shf_enabled;
}					t_shflag;

t_shflag			*shflag_new(char c, char *long_form);
void				shflag_del(t_shflag *shflag);

#endif
