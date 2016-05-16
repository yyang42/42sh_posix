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

char			*builtin_cd_phypath(char *path)
{
	t_builtin_cd_phypath	*this;

	this = builtin_cd_phypath_new(path);
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
	return (this->ret);
}
