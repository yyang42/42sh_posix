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

#ifndef DATA_H
# define DATA_H

# include "twl_dict.h"

# include "basics.h"

t_lst				*data_all_operators(void);
t_lst				*data_all_separators(void);
t_lst				*data_redir_operators(void);
t_lst				*data_token_item_list(void);
t_lst				*data_list_separators(void);
t_lst				*data_pipe_separators(void);
t_lst				*data_andor_separators(void);
t_lst				*data_compound_commands(void);
t_lst				*data_control_operators(void);

#endif
