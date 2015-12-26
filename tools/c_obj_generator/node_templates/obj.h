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

#ifndef <OBJ_NAME_UPPER>_H
# define <OBJ_NAME_UPPER>_H

# include "basics.h"

# include "ast/ast_utils.h"

typedef struct		s_<OBJ_NAME>
{
}					t_<OBJ_NAME>;

t_<OBJ_NAME>			<PADDING>*<OBJ_NAME>_new(void);
void				<OBJ_NAME>_del(t_<OBJ_NAME> *<OBJ_NAME>);

t_<OBJ_NAME>		*<OBJ_NAME>_new_from_tokens(
								t_lst *tokens);
void						<OBJ_NAME>_print_rec(
								t_<OBJ_NAME> *<OBJ_NAME>,
								int depth);
#endif
