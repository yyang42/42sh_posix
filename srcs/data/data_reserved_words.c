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

#include "data.h"

t_lst				*data_reserved_words(void)
{
	static t_lst	*separators = NULL;

	if (separators == NULL)
	{
		separators = twl_lst_new();
		twl_lst_push_back(separators, "!");
		twl_lst_push_back(separators, "{");
		twl_lst_push_back(separators, "}");
		twl_lst_push_back(separators, "case");
		twl_lst_push_back(separators, "do");
		twl_lst_push_back(separators, "done");
		twl_lst_push_back(separators, "elif");
		twl_lst_push_back(separators, "else");
		twl_lst_push_back(separators, "esac");
		twl_lst_push_back(separators, "fi");
		twl_lst_push_back(separators, "for");
		twl_lst_push_back(separators, "if");
		twl_lst_push_back(separators, "in");
		twl_lst_push_back(separators, "then");
		twl_lst_push_back(separators, "until");
		twl_lst_push_back(separators, "while");
	}
	return (separators);
}
