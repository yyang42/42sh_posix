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

#ifndef BUILTIN_UMASK_H
# define BUILTIN_UMASK_H

# include <sys/stat.h>
# include <sys/types.h>
# include "basics.h"
# include "builtin/builtin.h"
# include "twl_arr.h"
# include "argparser_extension.h"
# include "twl_opt_elem.h"
# include "error.h"
# include "twl_ctype.h"

# define UMASK_OPT_VALID_OPTS "S"
# define ISOCTAL(c)	((c) >= '0' && (c) <= '7')
# define S_IRUGO         (S_IRUSR|S_IRGRP|S_IROTH)
# define S_IWUGO         (S_IWUSR|S_IWGRP|S_IWOTH)
# define S_IXUGO         (S_IXUSR|S_IXGRP|S_IXOTH)

# define UMASK_INVALID_MSG "invalid symbolic mode operator"

typedef struct	s_mask
{
	char ubits[4];
	char gbits[4];
	char obits[4];
}				t_mask;

typedef struct	s_parse_mask
{
	int			who;
	int			op;
	int			perm;
	int			bits;
	int			c;
	char		*s;
}				t_parse_mask;

void			builtin_umask_exec(t_lst *tokens, t_shenv *this);
void			builtin_umask_print_symbolic(mode_t um);
int				builtin_umask_parse_symbolic_mode(char *mode, int initial_bits);
t_argparser		*builtin_umask_argparser(void);

#endif
