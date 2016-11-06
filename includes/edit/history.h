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

#ifndef HISTORY_H
# define HISTORY_H

# include "utils.h"
# include "edit/line.h"
# include "shenv/shenv.h"

# define DFL_HISTSIZE 128
# define DFL_HISTFILESIZE 128ul

typedef struct			s_histlist
{
	t_line				*line;
	size_t				number;
	bool				limit;
	struct s_histlist	*next;
	struct s_histlist	*prev;
}						t_histlist;

typedef struct			s_history
{
	t_histlist			*first;
	t_histlist			*current;
	t_histlist			*last;
	t_lst				*save;
	size_t				length;
	size_t				total;
	bool				is_break;
}						t_history;

t_history				*history_new(void);
void					history_del(t_history *this);

void					history_clear(t_history *this);
void					history_remove_one_line_from_number(t_history *this,
							size_t pos);

void					history_get_histsize(t_history *this);
size_t					history_get_histfilesize(t_history *this);

void					history_read_file(t_history *this);
void					history_write_file(t_history *this, char *path);
void					history_append_list_to_file(t_history *this,
							char *path);
void					history_append_file_to_list(t_history *this,
							char *path);
void					history_append_all_file_to_list(t_history *this,
							char *path);
void					history_append_all_list_to_file(t_history *this,
							char *path);

void					history_push(t_history *this, t_line *line);
void					history_push_multiline(t_history *this, char *commands);
void					history_pop(t_history *this);
void					history_pop_last(t_history *this);

t_line					*history_get_from_number(t_history *this, size_t index);
t_line					*history_get_from_last(t_history *this, size_t index);
t_line					*history_get_current(t_history *this);
t_line					*history_get_first(t_history *this);
char					*history_get_command_from_index_without_overflow(
		t_history *this, int index);
int						history_get_index_without_overflow(t_history *this,
		int index);

void					history_set_current(t_history *this, t_line *new_line);

void					history_up(t_history *this);
void					history_down(t_history *this);

bool					history_is_current_first(t_history *this);
bool					history_is_current_last(t_history *this);

void					history_reset_current(t_history *this);
void					history_reset_numbers(t_history *this);

t_line					*history_find(t_history *this,
							bool (*fn)(void *, void *), void *context);
t_line					*history_find2(t_history *this,
							bool (*fn)(void *, void *, void *),
							void *ctx1, void *ctx2);
int						history_find_index(t_history *this,
							bool (*fn)(void *, void *), void *context);
void					history_iter_from_current_to_first(t_history *this,
							void (*fn)(void *, void *), void *ctx);
void					history_iter_from_prev_to_first(t_history *this,
							void (*fn)(void *, void *), void *ctx);
void					history_iter0_from_ind1_to_ind2(t_history *this,
							void (*fn)(void *), size_t ind1, size_t ind2);

void					history_dump(t_history *this);
void					history_dump_last(t_history *this, int index);

t_lst					*history_utils_get_histfile(char *path);
int						history_utils_get_fd_histfile(char *path, int opt);

#endif
