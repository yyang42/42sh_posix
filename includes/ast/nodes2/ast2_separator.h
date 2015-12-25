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

#ifndef AST2_SEPARATOR_H
# define AST2_SEPARATOR_H

# include "basics.h"

typedef struct		s_ast2_separator
{
}					t_ast2_separator;

t_ast2_separator			*ast2_separator_new(void);
void				ast2_separator_del(t_ast2_separator *ast2_separator);

#endif
