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

#ifndef SHSIGNAL_H
# define SHSIGNAL_H

#include "basics.h"
#include <signal.h>

typedef struct		s_shsignal
{
	int				signum;
	char			*signame;
}					t_shsignal;

t_shsignal			*shsignal_new(int signum, char *signame);
void				shsignal_del(t_shsignal *shsignal);

void				handle_signal(int signal);

#endif
