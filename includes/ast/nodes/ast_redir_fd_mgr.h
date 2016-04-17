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

#ifndef AST_REDIR_FD_MGR_H
# define AST_REDIR_FD_MGR_H

# include "basics.h"

void				ast_redir_fd_mgr_init(t_lst *redir_fds, t_lst *redir_items);
void				ast_redir_fd_mgr_close_clear(t_lst *redir_fds);

#endif
