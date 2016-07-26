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

#ifndef RESEARCH_H
# define RESEARCH_H

# include "basics.h"
# include "edit/edit.h"

# define DFL_RESEARCH_SIZE 64

typedef struct		s_research
{
	char			*search;
	size_t			size;
	size_t			total;
	bool			found;
}					t_research;

t_research			*research_new(void);
void				research_del(t_research *this);
void				research_realloc(t_research *this);

void				research_clear(t_edit *this);
void				research_clear_prompt(t_edit *this);
void				research_clear_line(t_edit *this);

void				research_add_and_find(t_edit *this, unsigned char buf);
void				research_rem_and_find(t_edit *this);
void				research_place_letter(t_edit *this, unsigned char buf);
void				research_delete_letter(t_edit *this);

void				research_print_prompt(t_edit *this);
void				research_print_line(t_edit *this);

void				research_find(t_edit *this);
void				research_find_further(t_edit *this);
void				research_rewind_string(t_edit *this,
						t_line *search, int pos_cursor);
bool				research_compare(t_edit *this,
						t_line *search, int pos_cursor);

void				research_end(t_edit *this);

#endif
