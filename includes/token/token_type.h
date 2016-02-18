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

#ifndef TOKEN_TYPE_H
# define TOKEN_TYPE_H

# include "basics.h"

typedef enum		e_token_type
{
	TOKEN_TOKEN,
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
	TOKEN_IN,
	/* Arithmetic expansion tokens */
	TOK_AREXP_NUMBER,
	TOK_AREXP_ENV_VAR,
	TOK_AREXP_COMMA,
	TOK_AREXP_LPARENTHESIS,
	TOK_AREXP_RPARENTHESIS,
	TOK_AREXP_QUESTION_MARK,
	TOK_AREXP_COLON,
	/* Operators */
	TOK_AREXP_LOGICAL_OR,
	TOK_AREXP_LOGICAL_AND,
	TOK_AREXP_INC_OR,
	TOK_AREXP_EXC_OR,
	TOK_AREXP_AND,
	TOK_AREXP_PLUS,
	TOK_AREXP_MINUS,
	TOK_AREXP_MUL,
	TOK_AREXP_DIV,
	TOK_AREXP_MOD,
	TOK_AREXP_LSHIFT,
	TOK_AREXP_RSHIFT,
	/* Assignments */
	TOK_AREXP_ASSIGN,
	TOK_AREXP_ASSIGN_LOGICAL_OR,
	TOK_AREXP_ASSIGN_LOGICAL_AND,
	TOK_AREXP_ASSIGN_INC_OR,
	TOK_AREXP_ASSIGN_EXC_OR,
	TOK_AREXP_ASSIGN_AND,
	TOK_AREXP_ASSIGN_PLUS,
	TOK_AREXP_ASSIGN_MINUS,
	TOK_AREXP_ASSIGN_MUL,
	TOK_AREXP_ASSIGN_DIV,
	TOK_AREXP_ASSIGN_MOD,
	TOK_AREXP_ASSIGN_LSHIFT,
	TOK_AREXP_ASSIGN_RSHIFT,
	/* ...Things */
	TOK_AREXP_TILDE,
	TOK_AREXP_EXC_MARK,
	/* Comparisons */
	TOK_AREXP_LESS,
	TOK_AREXP_GREAT,
	TOK_AREXP_LESS_EQ,
	TOK_AREXP_GREAT_EQ,
	TOK_AREXP_EQUAL,
	TOK_AREXP_NOT_EQUAL
}					t_token_type;

t_token_type		token_type_from_str(char *str);
char				*token_type_to_str(t_token_type type);

t_token_type		token_arexp_type_from_str(char *str);

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
