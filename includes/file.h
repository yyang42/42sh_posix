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
# include "token/token.h"

# define FILE_DEFAULT_PERM 0666

int				file_exists(char *fn);
int				file_isdir(char *fn);
int				file_isexecutable(char *fn);
int				file_open_append(t_token *token);
int				file_open_read(t_token *token);
int				file_open_write_trunc(t_token *token);
int				file_create_handle_noclobber(t_token *param_token);
int				file_close(int fd);
int				file_open_read_write(t_token *token);
int				file_open_and_hand_error(t_token *token, int flags, int mod);

#endif
