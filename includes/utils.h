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

#define CHECK(subject) utils_log_errno(#subject, (subject));

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
char				*str_unescape_backslash(char *str);
char				*utils_str_unescape_backslash(char *str);
bool				utils_str_has_line_continuation(char *str);
char				*utils_strchr_multi_skip_escaped(char *str, char *needles);
void				utils_log_signal(int signum);
void				utils_log_errno(char *name, int error_code);
int					utils_get_current_tty(void);
void				utils_tcsetpgrp_for_tty_012(pid_t pid);

#endif
