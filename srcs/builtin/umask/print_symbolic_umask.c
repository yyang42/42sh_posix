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

#include "umask.h"

static void print_symbolic_umask_2(mode_t um, t_mask *mask)
{
	int i;
	
	i = 0;
	if ((um & S_IROTH) == 0)
	  mask->obits[i++] = 'r';
	if ((um & S_IWOTH) == 0)
	  mask->obits[i++] = 'w';
	if ((um & S_IXOTH) == 0)
	  mask->obits[i++] = 'x';
	mask->obits[i] = '\0';

	twl_printf("u=%s,g=%s,o=%s\n", mask->ubits, mask->gbits, mask->obits);
}

void print_symbolic_umask(mode_t um)
{
	t_mask	mask;
	int		i;

	i = 0;
	if ((um & S_IRUSR) == 0)
		mask.ubits[i++] = 'r';
	if ((um & S_IWUSR) == 0)
		mask.ubits[i++] = 'w';
	if ((um & S_IXUSR) == 0)
		mask.ubits[i++] = 'x';
	mask.ubits[i] = '\0';
	i = 0;
	if ((um & S_IRGRP) == 0)
		mask.gbits[i++] = 'r';
	if ((um & S_IWGRP) == 0)
		mask.gbits[i++] = 'w';
	if ((um & S_IXGRP) == 0)
		mask.gbits[i++] = 'x';
	mask.gbits[i] = '\0';
	print_symbolic_umask_2(um, &mask);
}
