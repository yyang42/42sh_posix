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

#ifndef EDIT_KEY_FUNC_H
# define EDIT_KEY_FUNC_H

void				edit_move_left(void *edit);
void				edit_move_right(void *edit);
void				edit_move_start(void *edit);
void				edit_move_end(void *edit);
void				edit_delete_letter(void *_edit);
void				edit_handle_ctrl_c(void *_edit);

#endif
