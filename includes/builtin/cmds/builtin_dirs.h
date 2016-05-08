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

#ifndef BUILTIN_DIRS_H
# define BUILTIN_DIRS_H

# include "basics.h"
# include "twl_opt.h"
# include "argparser_extension.h"
# include "shenv/shenv.h"
# include "builtin/builtin.h"

t_argparser			*builtin_dirs_argparser(void);

t_lst				*builtin_dirs_singleton(void);
void				builtin_dirs_exec(t_lst *tokens, t_shenv *shenv);
void				builtin_dirs_clear(t_argparser_result *result);
void				builtin_dirs_verbose(t_argparser_result *result);
void				builtin_dirs_new_line(t_argparser_result *result);
void				builtin_dirs_simple(t_argparser_result *result);

#endif
