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

#ifndef EXPAN_TYPE_H
# define EXPAN_TYPE_H

typedef enum	e_expan_type
{
	NONE,
	TILDE,
	PARAMETER,
	COMMAND_SUBSTITUTION_DOLLAR,
	COMMAND_SUBSTITUTION_BACKQUOTE,
	ARITHMETIC,
	PATHNAME,
	QUOTE_REMOVAL
}				t_expan_type;

#endif
