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

#include "arexp/arexp.h"

void			arexp_del(t_arexp *this)
{
	arexp_singleton(NULL, true);
	if (!this)
		return ;
	if (this->tokens)
		twl_lst_del(this->tokens, token_del);
	if (this->expression)
		arexp_expression_del(this->expression);
	if (this->error_msg)
		free(this->error_msg);
	free(this);
}
