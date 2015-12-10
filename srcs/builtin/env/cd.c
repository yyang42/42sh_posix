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

#include "cd.h"

// static int	setpwd(char *dirname)
// {

// }

void 		cd(char *str)
{
	t_opt				*opt;
	char				**args;

	if (!str || *str == '\0')
		return ;
	args = twl_strsplit_mul(str, " \t");
	opt = twl_opt_new(args, "LP@");
	if (!check_invalid_opts(opt, "cd", "LP@"))
		return ;
}
