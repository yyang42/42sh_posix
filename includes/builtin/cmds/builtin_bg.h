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

#ifndef BUILTIN_BG_H
# define BUILTIN_BG_H

# include "basics.h"
# include "shenv/shenv.h"
# include "job_control/job_mgr.h"
# include "token/token_mgr.h"
# include "argparser_extension.h"

void				builtin_bg_exec(t_lst *tokens, t_shenv *shenv);
void				builtin_bg_exec_segs(t_argparser_result *argparser_result);
void				builtin_bg_put_job_in_bg(t_job *job);

t_argparser			*builtin_bg_argparser(void);

#endif
