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

#include "alias.h"

static void		print_key_value(char *key, void *data, void *context_)
{
	char *str;

	str = data;
	twl_printf("%s=%s\n", key, str);
	(void)context_;
}

void			print_alias(t_environment *env)
{
	twl_dict_iter(env->alias, print_key_value, NULL);
}
