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

#ifndef PROG_H
# define PROG_H

# include "basics.h"
# include "shenv/shenv.h"
# include "utils.h"
# include "argparser_extension.h"

typedef struct		s_prog
{
	char			*prog_command_arg;
	char			*argv0;
}					t_prog;

t_prog				*prog_new(void);
t_prog				*prog_singl(void);
void				prog_init(t_prog *prog, char **argv);
void				prog_del(t_prog *prog);
int					prog_run(t_prog *prog);
void				prog_run_interactive(t_prog *prog);
void				prog_utils_run_input(char *input, int line);
void				prog_utils_run_fd(int fd);
void				prog_utils_run_file(char *file);
int					prog_utils_print_ast(char *input);
int					prog_utils_print_arexp(char *input);
char				*prog_line_edit_get_input(t_prog *prog);
char				*prog_line_edit_get_input_gnl(t_prog *prog);
void				prog_handle_exit_signal(t_prog *prog);
void				prog_parse_args(t_prog *prog, char **argv);
void				prog_utils_set_command_pos_params(void);

#endif
