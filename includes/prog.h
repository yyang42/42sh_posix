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

#ifndef PROG_H
# define PROG_H

# include "basics.h"
# include "xopt.h"

typedef struct		s_prog
{
	void			*test;
}					t_prog;

t_prog				*prog_new(void);
void				prog_del(t_prog *prog);
void				prog_run(t_prog *prog);
void				prog_print_ast(t_prog *prog);

#endif
