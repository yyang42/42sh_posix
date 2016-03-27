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

char				*get_prompt(void);
char				*get_search_prompt(void);

char				*build_ast_line(int depth, char *s1, char *s2);
bool				str_is_redir_operator(char *str);

char				*get_path_of_file(char *str);
char				*get_last_part_of_path(char *str);
t_lst				*read_directory(char *path);

void				signal_handle_ctrl_c(void);
void				signal_handle_sigwinch(void);
void				disable_all_signals(void);

#endif
