/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_norris_loves_the_norminette.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuck <chuck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2042/02/30 42:00:00 by chuck             #+#    #+#             */
/*   Updated: 2042/02/30 42:00:00 by chuck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XOPT_H
# define XOPT_H

# include "twl_opt.h"

# include "basics.h"
# include "twl_dict.h"

# define XOPT_VALID_OPTS "abcCefimnosuvx"

typedef struct		s_xopt
{
	t_opt			*opt__;
	t_dict			*flag_verbose;
	// bool			is_enabled;
}					t_xopt;

t_xopt				*xopt_new(void);
void				xopt_del(t_xopt *xopt);

t_xopt				*xopt_singleton(void);

void				xopt_init(t_xopt *xopt, char **av);
void				xopt_check_valid_opts(t_xopt *xopt);
t_lst				*xopt_get_opts(t_xopt *xopt);
t_lst				*xopt_get_args(t_xopt *xopt);

void				xopt_print_opts(t_xopt *xopt);
char				*xopt_concat_opts(t_xopt *xopt);

#endif
