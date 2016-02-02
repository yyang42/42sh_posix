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

#include "pattern_matching/substr.h"

char			*substr_percentpercent(t_substr *this, char *str, char *pattern)
{
	char	*ret;

	this->patss = pattern_substr_new(pattern); 
	pattern_substr_rev(this->patss);
	this->match = twl_strnew(twl_strlen(str));
	this->str = twl_strrev(twl_strdup(str));
	this->ind_m = 0;
	this->ind_p = 0;
	substr_sharpsharp_supervisor(this);
	ret = twl_strndup(str, twl_strlen(str) - twl_strlen(this->match));
	free(this->match);
	free(this->str);
	pattern_substr_del(this->patss);
	this->patss = NULL;
	return (ret);
}
