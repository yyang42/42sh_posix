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

#include "openclose/openclose_matcher.h"

t_openclose_matcher *openclose_matcher_singleton_parser(void)
{
	static t_openclose_matcher *matcher = NULL;

	if (matcher == NULL)
	{
		matcher = openclose_matcher_new();
		openclose_matcher_add(matcher, "(", ")");
		openclose_matcher_add(matcher, "{", "}");
		openclose_matcher_add(matcher, "if", "fi");
		// openclose_matcher_add(matcher, "while", "done");
	}
	return (matcher);
}
