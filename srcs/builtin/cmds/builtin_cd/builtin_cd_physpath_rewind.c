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

#include "builtin/cmds/builtin_cd.h"

void			builtin_cd_phypath_rewind(t_builtin_cd_phypath *this)
{
	this->index_path += 2;
	if (this->index_ret <= this->base)
	{
		return ;
	}
	this->ret[this->index_ret] = 0;
	this->index_ret -= 1;
	while (this->index_ret > this->base &&
			CD_ISDIRSEP(this->ret[this->index_ret]) == 0)
	{
		this->ret[this->index_ret] = 0;
		this->index_ret -= 1;
	}
	if (this->index_ret <= this->base)
	{
		this->index_ret += 1;
	}
	else
	{
		this->ret[this->index_ret] = 0;
	}
}
