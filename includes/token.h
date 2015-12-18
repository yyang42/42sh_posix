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

/* Operators */
# define TOKEN_AND_IF "&&"
# define TOKEN_OR_IF "||"
# define TOKEN_DSEMI ";;"
# define TOKEN_DLESS "<<"
# define TOKEN_DGREAT ">>"
# define TOKEN_LESSAND "<&"
# define TOKEN_GREATAND ">&"
# define TOKEN_LESSGREAT "<>"
# define TOKEN_DLESSDASH "<<-"
# define TOKEN_CLOBBER ">|"

/* Reserved words */
# define TOKEN_IF "if"
# define TOKEN_THEN "then"
# define TOKEN_ELSE "else"
# define TOKEN_ELIF "elif"
# define TOKEN_FI "fi"
# define TOKEN_DO "do"
# define TOKEN_DONE "done"
# define TOKEN_CASE "case"
# define TOKEN_ESAC "esac"
# define TOKEN_WHILE "while"
# define TOKEN_UNTIL "until"
# define TOKEN_FOR "for"

/* Recognized when reserved words are recognized */
# define TOKEN_LBRACE "{"
# define TOKEN_RBRACE "}"
# define TOKEN_BANG "!"
# define TOKEN_IN "in"

#endif
