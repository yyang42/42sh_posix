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
	t_argparser			*argparser;
	t_argparser_result	*argparser_result;
}					t_prog;

t_prog				*prog_new(void);
t_prog				*prog_singl(void);
void				prog_init(t_prog *prog, char **argv);
void				prog_del(t_prog *prog);
int					prog_run(t_prog *prog);
void				prog_run_interactive(t_prog *prog);
void				prog_run_input(t_prog *prog, char *input);
void				prog_run_input_from_stdin(t_prog *prog);
char				*prog_run_file_to_str(t_prog *prog, char *file);
int					prog_print_ast(t_prog *prog, char *input);
int					prog_print_arexp(t_prog *prog, char *input);
char				*prog_line_edit_get_input(t_prog *prog);
char				*prog_line_edit_get_input_gnl(t_prog *prog);
void				prog_handle_exit_signal(t_prog *prog);
t_argparser			*prog_argparser(void);
int					prog_is_opt_set(t_prog *prog, char *opt);

#endif
