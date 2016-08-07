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

#ifndef BUILTIN_HISTORY_H
# define BUILTIN_HISTORY_H

# include "basics.h"
# include "builtin/builtin.h"
# include "argparser_extension.h"

t_argparser			*builtin_history_argparser(void);
void				builtin_history_exec(t_lst *tokens, t_shenv *this);
//void				builtin_getopts_exec_getopt(char *optstring,
//					char *varname, char **argv, t_shenv *env);

#endif
