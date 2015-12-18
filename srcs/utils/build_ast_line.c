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

#include "twl_stdio.h"

#include "ast/ast_defines.h"

char				*build_ast_line(int depth, char *s1, char *s2)
{
	char			*tmp;
	twl_asprintf(&tmp, "%*s%s %s\n", depth * AST_TAB_WIDTH, "", s1, s2);
	return (tmp);
}
