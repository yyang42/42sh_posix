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

#ifndef ALIAS_H
# define ALIAS_H

# include "basics.h"
# include "twl_htab.h"
# include "ast/ast.h"
# include "twl_ctype.h"

typedef struct		s_alias_processor
{
	t_htab			*aliases;
	t_lst			*tokens;
	t_ast			*ast;
	int				line;
	t_lst			*processed;
	t_lst			*prev_processed;
}					t_alias_processor;

bool				alias_utils_is_valid_name(char *str);
bool				alias_utils_starts_with(char *alias_str, char *needle);

#endif
