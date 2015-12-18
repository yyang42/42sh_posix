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

#ifndef LETTER_MGR_H
# define LETTER_MGR_H

# include "basics.h"
# include "edit/letter.h"

t_lst				*letter_mgr_new(void);
void				letter_mgr_del(t_lst *letters);
void				letter_mgr_add(t_lst *letters, t_letter *letter,
															unsigned int index);
void				letter_mgr_remove(t_lst *letters, t_letter *letter);
void				letter_mgr_print(t_lst *letters, int index);

char				*letter_mgr_concat_string(t_lst *letters);
t_lst				*letter_mgr_clear(t_lst *letters);

#endif
