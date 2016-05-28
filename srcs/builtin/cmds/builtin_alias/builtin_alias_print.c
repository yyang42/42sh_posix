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

#include "builtin/cmds/builtin_alias.h"

static void			print_key_value(void *key, void *value, void *context_)
{
	twl_printf("%s='%s'\n", key, value);
	(void)context_;
}

void				builtin_alias_print(t_shenv *env)
{
	twl_htab_iter(env->shenv_alias, print_key_value, NULL);
}
