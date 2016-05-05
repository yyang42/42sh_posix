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

#ifndef BRACE_TOKEN_TYPE_H
# define BRACE_TOKEN_TYPE_H

typedef enum			e_brace_token_type
{
	BRACE_IGNORE,
	BRACE_LIST,
	BRACE_SEQUENCE_DIGIT,
	BRACE_SEQUENCE_ALPHA
}						t_brace_token_type;

#endif
