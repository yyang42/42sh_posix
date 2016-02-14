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

#ifndef AST_REDIR_FD_H
# define AST_REDIR_FD_H

# include "basics.h"

typedef struct		s_ast_redir_fd
{
	int					fd_save;
	int					fd_origin;
	int					fd_file;
}					t_ast_redir_fd;

t_ast_redir_fd			*ast_redir_fd_new(void);
void				ast_redir_fd_del(t_ast_redir_fd *ast_redir_fd);

#endif
