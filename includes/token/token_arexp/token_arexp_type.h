/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_norris_loves_the_norminette.h                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuck <chuck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2042/02/30 42:00:00 by chuck             #+#    #+#             */
/*   Updated: 2042/02/30 41:59:59 by chuck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_AREXP_TYPE_H
# define TOKEN_AREXP_TYPE_H

typedef enum		e_token_arexp_type
{
	TOKEN_AREXP_NUMBER,		// 0 1 2 -1 -2 etc...
	TOKEN_AREXP_VARIABLE,	// a, index etc...
	TOKEN_AREXP_ADD,		// +
	TOKEN_AREXP_SUB,		// -
	TOKEN_AREXP_MUL,		// *
	TOKEN_AREXP_DIV,		// /
	TOKEN_AREXP_MOD,		// %
	TOKEN_AREXP_OR,			// |
	TOKEN_AREXP_AND,		// &
	TOKEN_AREXP_XOR,		// ^
	TOKEN_AREXP_LSHIFT,		// <<
	TOKEN_AREXP_RSHIFT,		// >>
	TOKEN_AREXP_ASSIG_ADD,	// +=
	TOKEN_AREXP_ASSIG_SUB,	// -=
	TOKEN_AREXP_ASSIG_MUL,	// *=
	TOKEN_AREXP_ASSIG_DIV,	// /=
	TOKEN_AREXP_ASSIG_MOD,	// %=
	TOKEN_AREXP_,
	TOKEN_AREXP_,
	TOKEN_AREXP_,
	TOKEN_AREXP_,
	TOKEN_AREXP_,
	TOKEN_AREXP_,
	TOKEN_AREXP_,
	TOKEN_AREXP_,
}					t_token_arexp_type

#endif
