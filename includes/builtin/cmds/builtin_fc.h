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

#ifndef BUILTIN_FC_H
# define BUILTIN_FC_H

# include "basics.h"
# include "shenv/shenv.h"
# include "job_control/job_mgr.h"
# include "token/token_mgr.h"
# include "argparser_extension.h"
# include "edit/history.h"

void				builtin_fc_exec(t_lst *tokens, t_shenv *env);

t_argparser			*builtin_fc_argparser(void);

#endif
