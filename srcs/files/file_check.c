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

#include "file.h"

int file_exists (char *file)
{
	struct stat sb;

	return (stat(file, &sb) == 0);
}

int file_isdir (char *file)
{
	struct stat sb;

	return ((stat (file, &sb) == 0) && S_ISDIR(sb.st_mode));
}

int	file_isexecutable(char *file)
{
	struct stat sb;

	return (stat(file, &sb) == 0 && sb.st_mode & S_IXUSR);
}
