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

#include "shenv/shflag.h"

t_shflag			*shflag_new(char c, char *long_form)
{
	t_shflag		*shflag;

	shflag = twl_malloc_x0(sizeof(t_shflag));
	shflag->shf_mono = c;
	shflag->shf_long = long_form;
	shflag->shf_enabled = false;
	return (shflag);
}
