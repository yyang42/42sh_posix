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

#ifndef ALIAS_H
# define ALIAS_H

# include "twl_arr.h"
# include "twl_opt.h"
# include "twl_stdio.h"
# include "environment.h"
# include "twl_dict.h"
# include "twl_arr.h"
# include "builtin.h"
# include <stdbool.h>

char 			*get_alias(char *key);
void 			set_alias(char *str);
void 			print_alias();
void 			alias(char *str);

#endif
