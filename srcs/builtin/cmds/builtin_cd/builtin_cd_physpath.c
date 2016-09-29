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

static char		*cd_phypath_end_fn(char *path,
		t_builtin_cd_phypath *this, char *ret)
{
	if (this->error)
	{
		shenv_singl_error(1, "cd: %s: %s", path, strerror(this->error));
	}
	else
	{
		ret = this->ret;
		this->ret = NULL;
	}
	builtin_cd_phypath_del(this);
	return (ret);
}

char			*builtin_cd_phypath(char *path)
{
	t_builtin_cd_phypath	*this;
	char					*ret;

	this = builtin_cd_phypath_new(path);
	ret = NULL;
	while (true)
	{
		if (CD_ISDIRSEP(this->path[this->index_path]))
			this->index_path += 1;
		else if (this->path[this->index_path] == '.' &&
				CD_PATHSEP(this->path[this->index_path + 1]))
			this->index_path += 1;
		else if (this->path[this->index_path] == '.' &&
				this->path[this->index_path + 1] == '.' &&
				CD_PATHSEP(this->path[this->index_path + 2]))
			builtin_cd_phypath_rewind(this);
		else
			builtin_cd_phypath_add_path(this);
		if (builtin_cd_phypath_is_end(this))
			break ;
	}
	return (cd_phypath_end_fn(path, this, ret));
}
