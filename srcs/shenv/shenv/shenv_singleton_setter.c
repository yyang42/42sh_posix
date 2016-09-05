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

#include "shenv/shenv.h"

t_shenv				*shenv_singleton_setter(t_shenv *src_env)
{
	static t_shenv	*env = NULL;

	if (src_env)
	{
		env = src_env;
	}
	if (!env)
	{
		LOG_INFO("=====================2 1");
		env = shenv_new();
		LOG_INFO("=====================2 2");
		shenv_init(env);
		LOG_INFO("=====================2 3");
		shenv_increase_shlvl(env);
		LOG_INFO("=====================2 4");
	}
	return (env);
}
