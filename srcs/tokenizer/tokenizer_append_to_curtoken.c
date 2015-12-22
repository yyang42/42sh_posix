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

#include "tokenizer.h"

void				tokenizer_append_to_curtoken(t_tokenizer *t)
{
	int				len;

	len = twl_strlen(t->curtoken);
	t->curtoken[len + 1] = '\0';
	t->curtoken[len] = t->curpos[0];
	twl_strcpy(t->curtokenplus, t->curtoken);
	t->curtokenplus[len + 2] = '\0';
	t->curtokenplus[len + 1] = t->curpos[1];
}
