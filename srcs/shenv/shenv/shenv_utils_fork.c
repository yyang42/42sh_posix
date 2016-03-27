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


#include "xopt.h"
#include "twl_opt_elem.h"

#include "shenv/shenv.h"

pid_t					shenv_utils_fork(void)
{
	pid_t				pid;
	pid = fork();
	if (pid == 0)
	{
		twl_lst_clear(shenv_singleton()->jobs, NULL);
	}
	return (pid);
}