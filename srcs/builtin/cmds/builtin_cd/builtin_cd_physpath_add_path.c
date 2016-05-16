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

static bool		copy_to_end(t_builtin_cd_phypath *this)
{
	while (this->path[this->index_path] &&
			(CD_ISDIRSEP(this->path[this->index_path]) == 0))
	{
		if (this->index_ret >= CD_PATHMAX)
		{
			this->error = ENAMETOOLONG;
			return (false);
		}
		this->ret[this->index_ret] = this->path[this->index_path];
		this->index_ret += 1;
		this->index_path += 1;
	}
	return (true);
}

static void		concat_symlink(t_builtin_cd_phypath *this,
								char *buf, int linklen)
{
	char		tmpbuf[CD_PATHMAX + 1];

	if (twl_strlen(this->path + this->index_path) + linklen + 2 > CD_PATHMAX)
	{
		this->error = ENAMETOOLONG;
		return ;
	}
	twl_strcpy(tmpbuf, buf);
	tmpbuf[linklen] = '/';
	twl_strcpy(tmpbuf + linklen, this->path + this->index_path);
	twl_strcpy(this->path, tmpbuf);
	if (CD_ABSPATH(buf))
	{
		builtin_cd_phypath_renew(this);
	}
	else
	{
		this->index_path = 0;
		twl_bzero(this->ret + this->index_save, CD_PATHMAX - this->index_ret);
		this->index_ret = this->index_save;
	}
}

void			builtin_cd_phypath_add_path(t_builtin_cd_phypath *this)
{
	char		buf[CD_PATHMAX + 1];
	int			linklen;

	this->index_save = this->index_ret;
	if (this->index_ret != this->base)
	{
		this->ret[this->index_ret] = CD_DIRSEP;
		this->index_ret += 1;
	}
	if (!copy_to_end(this))
		return ;
	if ((linklen = readlink(this->ret, buf, CD_PATHMAX)) < 0)
	{
		if (errno != EINVAL)
			this->error = errno;
		return ;
	}
	buf[linklen] = 0;
	LOG_DEBUG("%s %s %i", this->ret, buf, linklen)
	this->num_symlink += 1;
	if (this->num_symlink > CD_MAXSYMLINKS)
		this->error = ELOOP;
	if (this->error)
		return ;
	concat_symlink(this, buf, linklen);
}
