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

#ifndef BUILTIN_DOT_H
# define BUILTIN_DOT_H

# include "basics.h"
# include "builtin/builtin.h"
# include "argparser_extension.h"
# define DOT_BUFSIZE 4096

void				builtin_dot_exec(t_lst *tokens, t_shenv *this);
void				builtin_dot_exec_do(char *file_path);
t_argparser			*builtin_dot_argparser(void);

#endif
