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

#include "edit/research.h"

t_research			*research_new(void)
{
	t_research		*this;

	this = twl_malloc_x0(sizeof(t_research));
	this->search = twl_strnew(DFL_RESEARCH_SIZE);
	this->size = 0;
	this->total = DFL_RESEARCH_SIZE;
	this->found = true;
	return (this);
}
