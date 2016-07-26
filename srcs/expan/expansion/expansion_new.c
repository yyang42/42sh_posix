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

#include "expan/expansion.h"

t_expansion			*expansion_new(void)
{
	t_expansion		*this;

	this = twl_malloc_x0(sizeof(t_expansion));
	this->before_split = twl_lst_new();
	this->after_split = twl_lst_new();
	this->patmatch = twl_lst_new();
	this->quoted = false;
	this->error = NULL;
	this->to_push_as = NULL;
	this->flag_prompt = false;
	this->flag_prompt_open_close = false;
	this->size_prompt = 0;
	return (this);
}
