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

#include "builtin/cmds/builtin_unset.h"

void				builtin_unsetenv_exec(t_lst *tokens, t_shenv *env)
{
	char	*new_str;
	char	*str;

	str = token_mgr_strjoin(tokens, " "); // TODO: refactor
	new_str = twl_strjoin("unset", &str[8]);
	builtin_unset_exec(tokens, env);
	free(new_str);
}
