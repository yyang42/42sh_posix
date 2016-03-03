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

#include "utils.h"
#include "data.h"
#include "token/token_utils.h"
#include "token/token_mgr.h"
#include "openclose/openclose_matcher.h"

char				*token_mgr_extract_assignment_join(t_lst *list_of_segs)
{
	t_lst			*copy;
	char			*str;
	t_lst			*segs;
	t_lst			*master_segs;

	copy = twl_lst_copy(list_of_segs, NULL);
	str = twl_strdup("");
	master_segs = twl_lst_new();
	while ((segs = twl_lst_pop_front(copy)))
	{
		twl_lst_push_back(master_segs, twl_lst_strjoin(segs, "="));
	}
	return (twl_lst_strjoin(master_segs, "_"));
}
