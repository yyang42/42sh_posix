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

void				builtin_wait_exec(t_lst *tokens, t_shenv *shenv);
void				builtin_wait_put_job_in_wait(t_job *job);
void				builtin_wait_invalid_opt_print_usage(char *opt, t_token *token);

#endif
