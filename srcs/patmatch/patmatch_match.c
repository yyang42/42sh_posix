/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_norris_loves_the_norminette.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuck <chuck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2042/02/30 42:00:00 by chuck             #+#    #+#             */
/*   Updated: 2042/02/30 42:59:59 by chuck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "patmatch.h"

//int					is_escaped(char *pattern, int index)
//{
//	if (pattern[index] == '\\')
//		return (1);
//	return (0);
//}
//
//void				pattern_build_double_quote(t_pattern_str *new, int *index_new, char *pattern, int *index_pat)
//{
//	*index_pat += 1;
//	while (pattern[*index_pat])
//	{
//		if (is_escaped(pattern, *index_pat) && pattern[*index_pat + 1] == '\\')
//		{
//			new->string[*index_new] = '\\';
//			*index_new += 1;
//			*index_pat += 1;
//		}
//		else if (is_escaped(pattern, *index_pat) && pattern[*index_pat + 1] == '"')
//		{
//			new->string[*index_new] = '"';
//			*index_new += 1;
//			*index_pat += 1;
//		}
//		else if (pattern[*index_pat] == '"')
//		{
//			break ;
//			*index_pat += 1;
//		}
//		else
//		{
//			new->string[*index_new] = pattern[*index_pat];
//			*index_new += 1;
//		}
//		*index_pat += 1;
//	}
//}
//
//void				pattern_build_simple_quote(t_pattern_str *new, int *index_new, char *pattern, int *index_pat)
//{
//	*index_pat += 1;
//	while (pattern[*index_pat])
//	{
//		if (pattern[*index_pat] == '\'')
//		{
//			break ;
//			*index_pat += 1;
//		}
//		else
//		{
//			new->string[*index_new] = pattern[*index_pat];
//			*index_new += 1;
//		}
//		*index_pat += 1;
//	}
//}
//
//void				patmatch_build_pattern_str_(t_patmatch *this, char *pattern)
//{
//	t_pattern_str	*elem;
//	int				index_pat;
//	int				index_new;
//
//	new = (t_pattern_str *)malloc(sizeof(t_pattern_str));
//	new->string = twl_strnew(twl_strlen(pattern));	
//	index_pat = 0;
//	index_new = 0;
//	while (pattern[index_pat])
//	{
//		if (is_escaped(pattern, index_pat))
//		{
//			index_pat += 1;
//			new->string[index_new] = pattern[index_pat];
//			index_new += 1;
//		}
//		else
//		{
//			if (pattern[index_pat] == '"')
//				pattern_build_double_quote(new, &index_new, pattern, &index_pat);
//			else if (pattern[index_pat] == '\'')
//				pattern_build_simple_quote(new, &index_new, pattern, &index_pat);
//			else
//			{
//				new->string[index_new] = pattern[index_pat];
//				index_pat += 1;
//				index_new += 1;
//			}
//		}
//	}
//	this->pattern_str = new;
//}

char				*patmatch_match(t_patmatch *this, char *pattern)
{
	pattern_new(pattern);
	return (NULL);
	(void)this;
}
