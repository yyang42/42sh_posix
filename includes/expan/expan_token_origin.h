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

#ifndef EXPAN_TOKEN_ORIGIN_H
# define EXPAN_TOKEN_ORIGIN_H

typedef enum			s_token_origin
{
	TOKEN_ORIGIN_WORD,
	TOKEN_ORIGIN_ASSIGNMENT_KEY,
	TOKEN_ORIGIN_ASSIGNMENT_VALUE,
	TOKEN_ORIGIN_REDIR_PARAM,
	TOKEN_ORIGIN_REDIR_HEREDOC,
	TOKEN_ORIGIN_PARAM_SUBSTITUTION
}						t_token_origin;

#endif
