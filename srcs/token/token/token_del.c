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

#include "token/token.h"

void				token_del(t_token *this)
{
	if (!this)
		return ;
	if (this->text)
		free(this->text);
	if (this->text_unexpanded)
		free(this->text_unexpanded);
	if (this->heredoc_text)
		free(this->heredoc_text);
	if (this->source_alias_expans)
		twl_lst_del(this->source_alias_expans, NULL);
	free(this->heredoc_operator);
	free(this);
}
