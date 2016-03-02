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

#include "builtin/builtin_unset.h"

int				builtin_unsetenv_exec(t_lst *tokens, t_environment *env)
{
	char	*new_str;
	int		flag;
	char	*str;

	str = token_mgr_strjoin(tokens, " "); // TODO: refactor
	new_str = twl_strjoin("unset", &str[8]);
	flag = builtin_unset_exec(tokens, env);
	free(new_str);
	return (flag);
}
