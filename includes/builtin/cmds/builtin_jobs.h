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

#ifndef BUILTIN_JOBS_H
# define BUILTIN_JOBS_H

# include "basics.h"
# include "twl_opt.h"
# include "shenv/shenv.h"
# include "argparser_extension.h"
# include "job_control/job_mgr.h"

# define BUILTIN_JOBS_FLAG_OPT_L 0x01
# define BUILTIN_JOBS_FLAG_OPT_P 0x02

void				builtin_jobs_exec(t_lst *tokens, t_shenv *this);
void				builtin_jobs_exec_print(t_lst *jobs, int flags);

t_argparser			*builtin_jobs_argparser(void);


#endif
