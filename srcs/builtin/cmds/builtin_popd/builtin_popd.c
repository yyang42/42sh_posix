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

#include "builtin/cmds/builtin_popd.h"
#include "builtin/cmds/builtin_cd.h"

static void		bp_error(t_builtin_dirs *this, t_lst *dirs, size_t len)
{
	if (len == 0)
		shenv_singl_error(1, "popd: directory stack empty");
	else
		shenv_singl_error(1, "popd: %c%i: directory stack index out of range",
				this->is_negative ? '-' : '+', this->number);
	free(twl_lst_pop_front(dirs));
}

static void		popd_number(t_builtin_dirs *this, t_lst *dirs, size_t len)
{
	size_t		index;
	char		*new_pwd;
	char		*tmp;

	this->is_number_set = false;
	index = (this->is_negative) ? len - this->number : this->number;
	tmp = twl_lst_popi(dirs, index);
	new_pwd = twl_lst_pop_front(dirs);
	if (!builtin_cd_follow_symlinks(new_pwd, "popd"))
	{
		free(new_pwd);
		return ;
	}
	free(tmp);
	free(new_pwd);
	builtin_dirs_simple(this);
}

static void		popd_no_number(t_builtin_dirs *this, t_lst *dirs, size_t len)
{
	char		*new_pwd;

	new_pwd = twl_lst_popi(dirs, 1);
	if (!builtin_cd_follow_symlinks(new_pwd, "popd"))
		return ;
	free(twl_lst_pop_front(dirs));
	builtin_dirs_simple(this);
	(void)len;
}

void			builtin_popd(t_builtin_dirs *this)
{
	t_lst		*dirs;
	size_t		len;

	dirs = builtin_dirs_singleton();
	len = twl_lst_len(dirs);
	if (!builtin_dirs_init_cwd("popd"))
		return ;
	if (!len)
	{
		bp_error(this, dirs, len);
		return ;
	}
	if (this->is_number_set)
	{
		if (this->number > len)
		{
			bp_error(this, dirs, len);
			return ;
		}
		popd_number(this, dirs, len);
	}
	else
	{
		popd_no_number(this, dirs, len);
	}
}
