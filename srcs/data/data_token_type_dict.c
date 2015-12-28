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

#include "twl_lst.h"

#include "twl_dict.h"

#include "token.h"

static t_token_type	*malloc_type(t_token_type type)
{
	t_token_type	*type_ptr;

	type_ptr = twl_malloc_x0(sizeof(t_token_type));
	*type_ptr = type;
	return (type_ptr);
}

t_dict				*data_token_type_dict(void)
{
	static t_lst	*dict = NULL;

	if (dict == NULL)
	{
		dict = twl_lst_new();
		twl_dict_add(dict, "\n", malloc_type(TOKEN_NEWLINE));
		twl_dict_add(dict, "&&", malloc_type(TOKEN_AND_IF));
		twl_dict_add(dict, "||", malloc_type(TOKEN_OR_IF));
		twl_dict_add(dict, ";;", malloc_type(TOKEN_DSEMI));
		twl_dict_add(dict, "<<", malloc_type(TOKEN_DLESS));
		twl_dict_add(dict, ">>", malloc_type(TOKEN_DGREAT));
		twl_dict_add(dict, "<&", malloc_type(TOKEN_LESSAND));
		twl_dict_add(dict, ">&", malloc_type(TOKEN_GREATAND));
		twl_dict_add(dict, "<>", malloc_type(TOKEN_LESSGREAT));
		twl_dict_add(dict, "<<-", malloc_type(TOKEN_DLESSDASH));
		twl_dict_add(dict, ">|", malloc_type(TOKEN_CLOBBER));
		twl_dict_add(dict, "if", malloc_type(TOKEN_IF));
		twl_dict_add(dict, "then", malloc_type(TOKEN_THEN));
		twl_dict_add(dict, "else", malloc_type(TOKEN_ELSE));
		twl_dict_add(dict, "elif", malloc_type(TOKEN_ELIF));
		twl_dict_add(dict, "fi", malloc_type(TOKEN_FI));
		twl_dict_add(dict, "do", malloc_type(TOKEN_DO));
		twl_dict_add(dict, "done", malloc_type(TOKEN_DONE));
		twl_dict_add(dict, "case", malloc_type(TOKEN_CASE));
		twl_dict_add(dict, "esac", malloc_type(TOKEN_ESAC));
		twl_dict_add(dict, "while", malloc_type(TOKEN_WHILE));
		twl_dict_add(dict, "until", malloc_type(TOKEN_UNTIL));
		twl_dict_add(dict, "for", malloc_type(TOKEN_FOR));
		twl_dict_add(dict, "{", malloc_type(TOKEN_LBRACE));
		twl_dict_add(dict, "}", malloc_type(TOKEN_RBRACE));
		twl_dict_add(dict, "!", malloc_type(TOKEN_BANG));
		twl_dict_add(dict, "in", malloc_type(TOKEN_IN));
	}
	return (dict);
}
