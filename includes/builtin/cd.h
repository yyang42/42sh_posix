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

#ifndef CD_H
# define CD_H

# include "builtin.h"
# include "environment.h"
# include "twl_opt.h"
# include "twl_opt_elem.h"
# include "execute.h"
# include <unistd.h>
# include <sys/types.h>
# include <string.h>
# include <sys/param.h>
# include <sys/stat.h>
# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>

void 		cd(char *str);
void		execute_cd(char *path, int no_symlinks, int xattrflag,
	t_environment *this);
void		cd_with_env(char *str, t_environment *this);

#endif