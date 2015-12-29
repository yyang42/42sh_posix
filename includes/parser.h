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

#ifndef PARSER_H
# define PARSER_H

# include "basics.h"

# include "token.h"

typedef struct		s_parser
{
	char			*raw;
	int				index;
	int				len;
}					t_parser;

t_parser			*parser_new(char *str);
void				parser_del(t_parser *this);

char				parser_cchar(t_parser *this);
char				*parser_cstr(t_parser *this);
int					parser_remain_len(t_parser *this);

bool				parser_is_andor(t_parser *this);
bool				parser_is_comp(t_parser *parser);
bool				parser_is_list_elem(t_parser *this);
bool				parser_is_pipe_elem(t_parser *parser);
bool				parser_is_simple_cmd_chars(t_parser *parser);
bool				parser_is_subshell(t_parser *parser);

#endif
