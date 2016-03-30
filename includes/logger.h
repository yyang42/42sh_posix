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

#ifndef LOGGER_H
# define LOGGER_H

# define _LOGGER(lvl, ...) logger_printf(lvl,__FILE__,__LINE__,__VA_ARGS__);
# define LOGGER_INFO(...) _LOGGER(LOGGER_LEVEL_INFO, __VA_ARGS__);
# define LOGGER_DEBUG(...) _LOGGER(LOGGER_LEVEL_DEBUG, __VA_ARGS__);
# define LOGGER_ERROR(...) _LOGGER(LOGGER_LEVEL_ERROR, __VA_ARGS__);

typedef enum		e_logger_level
{
	LOGGER_LEVEL_DEBUG,
	LOGGER_LEVEL_INFO,
	LOGGER_LEVEL_ERROR,
}					t_logger_level;

void				logger_printf(t_logger_level level, const char *fn, int line, const char *fmt, ...);

#endif
