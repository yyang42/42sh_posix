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

#ifndef UTILS_H
# define UTILS_H

# include "basics.h"

int					demo_sum(int num1, int num2);
t_lst				*str_split_except_quote(char *str);
void				increment_len(int *len_ptr, int len);
char				*get_prompt(void);
char				*build_ast_line(int depth, char *s1, char *s2);
bool				str_is_redir_operator(char *str);
void				disable_all_sigs(void);
void				signal_handle_ctrl_c(void);

#endif
