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

#ifndef PIPELINE_H
# define PIPELINE_H

# include "basics.h"

# include "ast/ast_defines.h"
# include "ast/anode/anode.h"

typedef struct		s_pipeline
{
	t_atype			type;
	void			*left;
	void			*right;
}					t_pipeline;

t_pipeline			*pipeline_new(void);
void				pipeline_del(t_pipeline *this);

t_pipeline			*pipeline_build(char *str, int *len_ptr);

#endif
