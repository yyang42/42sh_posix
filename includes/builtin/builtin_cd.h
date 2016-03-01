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

# include <unistd.h>
# include <sys/types.h>
# include <string.h>
# include <sys/param.h>
# include <sys/stat.h>
# include <errno.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include "builtin/builtin.h"
# include "twl_opt.h"
# include "twl_opt_elem.h"

# define MAX_SIZE 4096

void		execute_cd(char *path, int no_symlinks, t_environment *this);
int			builtin_cd(t_lst *tokens, t_environment *this);
char		*join_paths(char *path, char *dirname);
char		*get_cdpath(char *dirname, t_environment *this);
char		*join_pwd_to_path(char *dirname);
char		*set_canonical_form(char *path);
void		get_flags(t_opt *opt, int *no_symlinks);
int			free_all(char *dirname, char **args, t_opt *opt);

#endif