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

#ifndef BUILTIN_WAIT_H
# define BUILTIN_WAIT_H

# include "basics.h"
# include "shenv/shenv.h"
# include "job_control/job_mgr.h"
# include "token/token_mgr.h"
# include "argparser_extension.h"

# define WAIT_ERROR_ALREADY_STOPPED 146

void			builtin_wait_exec(t_lst *tokens, t_shenv *shenv);
void			builtin_wait_exec_segs(t_argparser_result *argparser_result);
void			builtin_wait_put_job_in_wait(t_job *job);
void			builtin_wait_exec_wait_all(void);

t_argparser		*builtin_wait_argparser(void);

#endif
