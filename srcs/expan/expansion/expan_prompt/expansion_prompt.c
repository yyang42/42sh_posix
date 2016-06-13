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

#include "expan/expansion.h"
#include "expan/expan_prompt.h"

t_expan_prompt		g_expan_prompt_map_fn[17] =
{
	{ 'a', expansion_prompt_ring_bell },
	{ 'd', expansion_prompt_ddate },
	{ 'e', expansion_prompt_escape },
	{ 'h', expansion_prompt_simple_hostname },
	{ 'H', expansion_prompt_hostname },
	{ 'j', expansion_prompt_number_jobs },
	{ 'n', expansion_prompt_new_line },
	{ 'r', expansion_prompt_carriage_return },
	{ 't', expansion_prompt_date_hhmmss24 },
	{ 'T', expansion_prompt_date_hhmmss12 },
	{ '@', expansion_prompt_date_ampm },
	{ 'A', expansion_prompt_date_hhmm24 },
	{ 'u', expansion_prompt_username },
	{ 'w', expansion_prompt_current_directory },
	{ 'W', expansion_prompt_current_basename },
	{ '\\', expansion_prompt_backslash },
	{ '\0', NULL }
};

void				expansion_prompt(t_expansion *this, t_expan_token *token)
{
	char			c;
	size_t			index;

	c = token->text[1];
	index = 0;
	while (g_expan_prompt_map_fn[index].key)
	{
		if (g_expan_prompt_map_fn[index].key == c)
			break ;
		index += 1;
	}
	if (g_expan_prompt_map_fn[index].expan_prompt_fn)
		g_expan_prompt_map_fn[index].expan_prompt_fn(this);
}
