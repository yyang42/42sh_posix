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

#ifndef BUILTIN_PWD_H
# define BUILTIN_PWD_H

# include "basics.h"
# include "twl_opt.h"
# include "argparser_extension.h"
# include "shenv/shenv.h"
# include "builtin/builtin.h"

t_argparser				*builtin_pwd_argparser(void);

void					builtin_pwd_exec(t_lst *tokens, t_shenv *shenv);
void					builtin_pwd_exec_logically(void);
void					builtin_pwd_exec_physically(void);

#endif
