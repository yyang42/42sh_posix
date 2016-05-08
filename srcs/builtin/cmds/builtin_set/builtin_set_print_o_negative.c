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

#include "builtin/cmds/builtin_set.h"
#include "shenv/shenv.h"
#include "twl_opt.h"
#include "twl_opt_elem.h"
#include "twl_xstring.h"

#define SET_MINUS_O_PADDING 15

static void			get_flag_verbose(char *key, void *data, void *context)
{
	t_shenv	*env;
	char			*flag;
	int				space_count;
	char			*space;

	env = context;
	flag = data;
	space_count = SET_MINUS_O_PADDING - (int)twl_strlen(flag);
	if (space_count < 0)
		space = twl_strdup("\t");
	else
	{
		space = (char*)malloc(sizeof(char) * (space_count + 1));
		twl_memset(space, ' ', space_count);
		space[space_count] = 0;
	}
	LOG_DEBUG("shenv_flag_exist key %s", key);
	if (shenv_flag_exist(env, key))
		twl_printf("%s%s\t%s\n", flag, space, "on");
	else
		twl_printf("%s%s\t%s\n", flag, space, "off");
	free(space);
}

void				builtin_set_print_o_negative(t_shenv *env)
{
	if (env->flag_verbose)
		twl_dict_iter(env->flag_verbose, get_flag_verbose, env);
}
