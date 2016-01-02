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

#ifndef TOKEN_LIST_MGR_H
# define TOKEN_LIST_MGR_H

# include "basics.h"
# include "token/token_mgr.h"

t_lst				*token_list_mgr_new(void);
void				token_list_mgr_del(t_lst *token_lists);
void				token_list_mgr_add(t_lst *token_lists, t_lst *token_list);
void				token_list_mgr_remove(t_lst *token_lists, t_lst *token_list);
void				token_list_mgr_print(t_lst *token_lists);

char				*token_list_mgr_strjoin(t_lst *tokens_list);

#endif
