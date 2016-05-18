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

t_builtin_cd_phypath		*builtin_cd_phypath_new(char *path)
{
	t_builtin_cd_phypath	*this;

	this = twl_malloc_x0(sizeof(t_builtin_cd_phypath));
	this->path = twl_strnew(CD_PATHMAX);
	this->path = twl_strcat(this->path, path);
	this->ret = twl_strnew(CD_PATHMAX);
	if (CD_DOUBLESLASH(this->path))
	{
		twl_strcat(this->ret, "//");
		this->index_ret = 2;
		this->base = 2;
	}
	else
	{
		twl_strcat(this->ret, "/");
		this->index_ret = 1;
		this->base = 1;
	}
	this->index_path = 0;
	this->num_symlink = 0;
	this->error = 0;
	return (this);
}
