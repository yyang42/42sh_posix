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

void					builtin_cd_exec_do(char *path, char *original_path, int no_symlinks, t_shenv *this);
void					builtin_cd_exec(t_lst *tokens, t_shenv *this);
char					*join_paths(char *path, char *dirname);
char					*builtin_cd_get_path(char *dirname, t_shenv *this);
char					*join_pwd_to_path(char *dirname);
char					*set_canonical_form(char *path);

void					builtin_cd_utils_get_flags(t_opt *opt, int *no_symlinks);
int						builtin_cd_utils_free_all(char *dirname, char **args, t_opt *opt);
t_argparser				*builtin_cd_argparser(void);

char					*builtin_cd_phypath(char *path);
t_builtin_cd_phypath	*builtin_cd_phypath_new(char *path);
void					builtin_cd_phypath_renew(t_builtin_cd_phypath *this);
void					builtin_cd_phypath_del(t_builtin_cd_phypath *this);
void					builtin_cd_phypath_rewind(t_builtin_cd_phypath *this);
void					builtin_cd_phypath_add_path(t_builtin_cd_phypath *this);
bool					builtin_cd_phypath_is_end(t_builtin_cd_phypath *this);

#endif
