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

#ifndef BUILTIN_CD_H
# define BUILTIN_CD_H

# include <unistd.h>
# include <sys/types.h>
# include <string.h>
# include <sys/param.h>
# include <sys/stat.h>
# include <errno.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include "builtin/builtin.h"
# include "argparser_extension.h"

# define CD_ABSPATH(x) ((x)[0] == '/')
# define CD_RELPATH(x) ((x)[0] != '/')
# define CD_ROOTEDPATH(x) (CD_ABSPATH(x))

# define CD_DIRSEP '/'
# define CD_ISDIRSEP(c) ((c) == '/')
# define CD_PATHSEP(c) (CD_ISDIRSEP(c) || (c) == 0)
# define CD_PATHMAX 1024
# define CD_MAXSYMLINKS 32

# define CD_DOUBLESLASH(p) ((p[0] == '/') && (p[1] == '/') && p[2] != '/')

# define MAX_SIZE 4096

typedef struct			s_builtin_cd_phypath
{
	char				*path;
	char				*ret;
	size_t				base;
	size_t				index_path;
	size_t				index_ret;
	size_t				index_save;
	size_t				num_symlink;
	size_t				error;
}						t_builtin_cd_phypath;

typedef struct			s_builtin_cd
{
	char				*path;
	bool				to_print;
}						t_builtin_cd;

t_builtin_cd			*builtin_cd_new(char *path, bool to_print);
void					builtin_cd_del(t_builtin_cd *this);

void					builtin_cd_exec(t_lst *tokens, t_shenv *this);

t_argparser				*builtin_cd_argparser(void);

char					*builtin_cd_phypath(char *path);
t_builtin_cd_phypath	*builtin_cd_phypath_new(char *path);
void					builtin_cd_phypath_renew(t_builtin_cd_phypath *this);
void					builtin_cd_phypath_del(t_builtin_cd_phypath *this);
void					builtin_cd_phypath_rewind(t_builtin_cd_phypath *this);
void					builtin_cd_phypath_add_path(t_builtin_cd_phypath *this);
bool					builtin_cd_phypath_is_end(t_builtin_cd_phypath *this);

char					*builtin_cd_logpath(char *path);

char					*builtin_cd_make_path_from_dir(char *path, char *dir);

t_lst					*builtin_cd_get_directories(char *dir);
bool					builtin_cd_follow_symlinks(char *dir, char *from_whom);
void					builtin_cd_unfollow_symlinks(char *dir);

#endif
