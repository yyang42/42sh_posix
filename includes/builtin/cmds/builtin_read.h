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

#ifndef BUILTIN_READ_H
# define BUILTIN_READ_H

# include "basics.h"
# include "argparser_extension.h"
# include "builtin/builtin.h"

void				builtin_read_exec(t_lst *tokens, t_shenv *env);
void				builtin_read_verbose(t_shenv *env);
void				builtin_read_add(t_shenv *env, t_lst *opt);
t_argparser			*builtin_read_argparser(void);
void				builtin_read_exec_readline(t_lst *remainders);
bool				builtin_read_utils_has_line_continuation(char *str);

#endif
