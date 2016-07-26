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

#include "edit/edit.h"
#include "edit/research.h"

/*
** "(reverse-i-search)`': "
** "(failed reverse-i-search)`': "
** TODO:
**   Terminer cette partie... En cas de mode déjà activé... chercher plus haut
**   dans l'historique.
*/

void			edit_research(t_edit *this)
{
	this->research_mode = true;
	this->research = research_new();
	research_clear(this);
	research_print_prompt(this);
	research_print_line(this);
}
