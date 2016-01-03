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

#ifndef TOKEN_MGR_H
# define TOKEN_MGR_H

# include "basics.h"
# include "token/token.h"

t_lst				*token_mgr_new(void);
void				token_mgr_del(t_lst *tokens);
void				token_mgr_del_void(void *tokens);
void				token_mgr_add(t_lst *tokens, t_token *token);
void				token_mgr_remove(t_lst *tokens, t_token *token);
void				token_mgr_print(t_lst *tokens);
void				token_mgr_print_token_text_by_index(t_lst *tokens,
																	int index);

char				*token_mgr_strjoin(t_lst *tokens, char *sep);
char				*token_mgr_strjoin_with_num(t_lst *tokens);
t_lst				*token_mgr_split(t_lst *tokens, t_lst *split_strings,
														bool keep_delimiter);
t_lst				*token_mgr_split_by_one_sep(t_lst *tokens, char *sep,
														bool keep_delimiter);
char				*token_list_mgr_strjoin(t_lst *tokens_list);
t_token				*token_mgr_first(t_lst *tokens);
bool				token_mgr_first_equ(t_lst *tokens, char *str);
t_token				*token_mgr_last(t_lst *tokens);
bool				token_mgr_last_equ(t_lst *tokens, char *str);
t_token				*token_mgr_get(t_lst *tokens, int index);

t_lst				*token_mgr_extract_redir(t_lst *tokens);
t_lst				*token_mgr_extract_assignment(t_lst *tokens);

#endif
