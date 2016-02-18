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

#include "twl_xstdlib.h"

#include "edit/letter.h"

t_letter			*letter_cpy(t_letter *letter)
{
	t_letter		*new_letter;

	new_letter = twl_malloc_x0(sizeof(t_letter));
	twl_memcpy(new_letter, letter, sizeof(t_letter));
	return (new_letter);
}
