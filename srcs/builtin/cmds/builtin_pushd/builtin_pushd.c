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

#include "builtin/cmds/builtin_pushd.h"
#include "builtin/cmds/builtin_cd.h"

static void		bp_error(t_builtin_dirs *this, t_lst *dirs, size_t len)
{
	if (len == 0)
		shenv_singl_error(1, "pushd: directory stack empty");
	else
		shenv_singl_error(1, "pushd: %c%i: directory stack index out of range",
				this->is_negative ? '-' : '+', this->number);
	free(twl_lst_pop_front(dirs));
}

static void		pushd_number(t_builtin_dirs *this, t_lst *dirs, size_t len)
{
	size_t		index;
	char		*new_pwd;

	this->is_number_set = false;
	index = (this->is_negative) ? len - this->number : this->number;
	while (index != 0)
	{
		twl_lst_push_back(dirs, twl_lst_pop_front(dirs));
		index -= 1;
	}
	new_pwd = twl_lst_pop_front(dirs);
	if (builtin_cd_follow_symlinks(new_pwd, "pushd"))
		builtin_dirs_simple(this);
	free(new_pwd);
}

static void		pushd_no_number(t_builtin_dirs *this, t_lst *dirs, size_t len)
{
	char		*new_pwd;

	new_pwd = twl_lst_first(this->result->remainders);
	if (!new_pwd && !len)
	{
		shenv_singl_error(1, "no other directory");
		return ;
	}
	if (!new_pwd)
	{
		new_pwd = twl_lst_popi(dirs, 1);
	}
	if (builtin_cd_follow_symlinks(new_pwd, "pushd"))
		builtin_dirs_simple(this);
	else
		free(twl_lst_pop_front(dirs));
}

void			builtin_pushd(t_builtin_dirs *this)
{
	t_lst		*dirs;
	size_t		len;

	dirs = builtin_dirs_singleton();
	len = twl_lst_len(dirs);
	if (!builtin_dirs_init_cwd("pushd"))
		return ;
	if (this->is_number_set)
	{
		if (this->number > len)
		{
			bp_error(this, dirs, len);
			return ;
		}
		pushd_number(this, dirs, len);
	}
	else
	{
		pushd_no_number(this, dirs, len);
	}
}
