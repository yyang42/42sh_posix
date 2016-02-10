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

#ifndef AREXP_TOT_H
# define AREXP_TOT_H

# include "basics.h"
# include "arexp/arexp_basics.h"

typedef struct			s_arexp_tot
{
}						t_arexp_tot;

t_arexp_tot				*arexp_tot_new();
void					arexp_tot_del(t_arexp_tot *this);

#endif
