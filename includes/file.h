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

#ifndef FILE_H
# define FILE_H

# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include "basics.h"
# include <fcntl.h>
# include <string.h>
# include <stdio.h>

int			file_exists (char *fn);
int			file_isdir (char *fn);
int			file_isexecutable(char *fn);
int			append_to_file(char *str);
int 		read_file(char *str);
int			create_file(char *str);
void		close_file(int fd);
int			read_write_file(char *str);

#endif
