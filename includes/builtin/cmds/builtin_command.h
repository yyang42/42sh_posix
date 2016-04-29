/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_norris_loves_the_norminette.h                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuck <chuck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2042/02/30 42:00:00 by chuck             #+#    #+#             */
/*   Updated: 2042/02/30 41:59:59 by chuck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_COMMAND_H
# define BUILTIN_COMMAND_H

# include "basics.h"
# include "twl_opt.h"
# include "argparser_extension.h"
# include "builtin/builtin.h"
# include "shenv/shenv.h"

# define BUILTIN_COMMAND_USUAL_PATHS "/bin:/usr/bin:/usr/local/bin"

void				builtin_command_exec(t_lst *tokens, t_shenv *shenv);
void				builtin_command_exec_command(t_lst *tokens,
													t_argparser_result *result,
													t_shenv *shenv);
void				builtin_command_exec_verbose(t_argparser_result *result,
													t_shenv *shenv);
void				builtin_command_exec_true_verbose(
													t_argparser_result *result,
													t_shenv *shenv);

t_argparser			*builtin_command_argparser(void);

#endif
