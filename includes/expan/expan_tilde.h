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

#ifndef EXPAN_TILDE_H
# define EXPAN_TILDE_H

#include "basics.h"

typedef struct			s_expan_tilde
{
	char				*token;
	char				*suffix;
}						t_expan_tilde;

t_expan_tilde			*expan_tilde_new(void);
void					expan_tilde_del(void *expan_tilde);
void					expan_tilde_print(t_expan_tilde *expan_tilde);
void					expan_tilde_do(char **res, char *token, char *suffix);
#endif
