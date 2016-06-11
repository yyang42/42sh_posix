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

#ifndef EXPAN_PROMPT_H
# define EXPAN_PROMPT_H

# include "expan/expansion.h"
# include "basics.h"

typedef struct			s_expan_prompt
{
	char				key;
	void				(*expan_prompt_fn)(t_expansion *this);
}						t_expan_prompt;

void					expansion_prompt_ring_bell(t_expansion *this);
void					expansion_prompt_ddate(t_expansion *this);
void					expansion_prompt_escape(t_expansion *this);
void					expansion_prompt_simple_hostname(t_expansion *this);
void					expansion_prompt_hostname(t_expansion *this);
void					expansion_prompt_number_jobs(t_expansion *this);
void					expansion_prompt_new_line(t_expansion *this);
void					expansion_prompt_carriage_return(t_expansion *this);

#endif
