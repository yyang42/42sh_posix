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

#ifndef TOKEN_H
# define TOKEN_H

# include "basics.h"

typedef enum		e_token_type
{
	TOKEN_WORD,
	TOKEN_ASSIGNMENT_WORD,
	TOKEN_NAME,
	TOKEN_NEWLINE,
	TOKEN_IO_NUMBER,
	/* Operators */
	TOKEN_AND_IF,
	TOKEN_OR_IF,
	TOKEN_DSEMI,
	TOKEN_DLESS,
	TOKEN_DGREAT,
	TOKEN_LESSAND,
	TOKEN_GREATAND,
	TOKEN_LESSGREAT,
	TOKEN_DLESSDASH,
	TOKEN_CLOBBER,
	/* Reserved words */
	TOKEN_IF,
	TOKEN_THEN,
	TOKEN_ELSE,
	TOKEN_ELIF,
	TOKEN_FI,
	TOKEN_DO,
	TOKEN_DONE,
	TOKEN_CASE,
	TOKEN_ESAC,
	TOKEN_WHILE,
	TOKEN_UNTIL,
	TOKEN_FOR,
	/* Recognized when reserved words are recognized */
	TOKEN_LBRACE,
	TOKEN_RBRACE,
	TOKEN_BANG,
	TOKEN_IN
}					t_token_type;

typedef	enum		e_tokentype
{
	PREV_NONE,
	PREV_WORD,
	PREV_OPERATOR
}					t_tokentype;

typedef struct		s_token
{
	t_token_type	type;
	char			*text;
}					t_token;

t_token				*token_new(t_token_type type, char *text);
void				token_del(t_token *this);

#endif

	// TOKEN_WORD
	// TOKEN_ASSIGNMENT_WORD
	// TOKEN_NAME
	// TOKEN_NEWLINE
	// TOKEN_IO_NUMBER
	// /* Operators */
	// TOKEN_AND_IF "&&"
	// TOKEN_OR_IF "||"
	// TOKEN_DSEMI ";;"
	// TOKEN_DLESS "<<"
	// TOKEN_DGREAT ">>"
	// TOKEN_LESSAND "<&"
	// TOKEN_GREATAND ">&"
	// TOKEN_LESSGREAT "<>"
	// TOKEN_DLESSDASH "<<-"
	// TOKEN_CLOBBER ">|"
	// /* Reserved words */
	// TOKEN_IF "if"
	// TOKEN_THEN "then"
	// TOKEN_ELSE "else"
	// TOKEN_ELIF "elif"
	// TOKEN_FI "fi"
	// TOKEN_DO "do"
	// TOKEN_DONE "done"
	// TOKEN_CASE "case"
	// TOKEN_ESAC "esac"
	// TOKEN_WHILE "while"
	// TOKEN_UNTIL "until"
	// TOKEN_FOR "for"
	// /* Recognized when reserved words are recognized */
	// TOKEN_LBRACE "{"
	// TOKEN_RBRACE "}"
	// TOKEN_BANG "!"
	// TOKEN_IN "in"
