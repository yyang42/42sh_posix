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

#ifndef BUILTIN_SET_H
# define BUILTIN_SET_H

# include "basics.h"
# include "builtin/builtin.h"
# include "twl_opt.h"
# include "twl_opt_elem.h"

void				builtin_set_exec(t_lst *tokens, t_shenv *env);
void				builtin_set_exec_args(t_lst *tokens_copy);
void				builtin_set_print_o_positive(t_shenv *env);
void				builtin_set_print_o_negative(t_shenv *env);
void				builtin_set_exec_print(t_shenv *this);

#endif
