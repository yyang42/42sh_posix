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

#ifndef EXPAN_TOKEN_TYPE_H
# define EXPAN_TOKEN_TYPE_H

typedef enum		e_expan_token_type
{
	EXPAN_TILDE,
	EXPAN_PARAMETER,
	EXPAN_CMDSBT_DOLLAR,
	EXPAN_CMDSBT_BQUOTE,
	EXPAN_ARITHMETIC,
	EXPAN_SQUOTE,
	EXPAN_DQUOTE,
	EXPAN_PROMPT,
	EXPAN_PROMPT_NUMBER,
	EXPAN_NONE
}					t_expan_token_type;

#endif
