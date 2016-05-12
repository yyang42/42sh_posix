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

static void			get_home(t_expansion *this)
{
	char			*home;

	home = shenv_get_home(shenv_singleton());
	if (!home)
		home = "~";
	expansion_push_before_split(this, home, false);
}

void				expansion_tilde(t_expansion *this, t_expan_token *token)
{
	struct passwd	*pw;

	if (this->error)
		return ;
	if (!token->text[1])
		get_home(this);
	else if ((pw = getpwnam(token->text + 1)))
		expansion_push_before_split(this, pw->pw_dir, false);
	else
		expansion_no_tilde(this, token);
}
