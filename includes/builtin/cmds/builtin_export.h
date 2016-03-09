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

#ifndef BUILTIN_EXPORT_H
# define BUILTIN_EXPORT_H

# include "basics.h"
# include "twl_opt.h"
# include "argparser_extension.h"
# include "builtin/builtin.h"

# define EXPORT_OPT_VALID_OPTS "p"


void				builtin_export_exec(t_lst *tokens, t_shenv *env);
void				builtin_export_exec_export_tokens(t_argparser_result *argparser_result, t_shenv *shenv);
void				builtin_export_verbose(t_shenv *env);

t_argparser			*builtin_export_argparser(void);

#endif
