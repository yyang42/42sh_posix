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

#ifndef BUILTIN_ECHO_H
# define BUILTIN_ECHO_H

# include "basics.h"
# include "twl_opt.h"
# include "builtin/builtin.h"

# define ECHO_OPT_VALID_OPTS "n"

int				builtin_echo(t_lst *tokens, t_environment *this);

#endif
