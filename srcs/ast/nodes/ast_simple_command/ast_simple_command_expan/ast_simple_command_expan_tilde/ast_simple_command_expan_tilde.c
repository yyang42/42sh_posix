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

#include "ast/nodes/ast_simple_command.h"
#include "ast/nodes/ast_assignment.h"
#include "ast/nodes/ast_redir.h"
#include "environment.h"

/*
TODO
In an assignment (see XBD Variable Assignment),
multiple tilde-prefixes can be used: at the beginning of the word (that is, following the <equals-sign> of the assignment),
following any unquoted <colon>, or both. A tilde-prefix in an assignment is terminated by the first unquoted <colon> or <slash>.
*/

char	*get_home_path()
{
	t_environment	*env;
	char			*home;

	env = environment_singleton();
	home = environment_getenv_value(env, "HOME");
	if (home){
		return (twl_strdup(home));
	}
	else
		return (twl_strdup(""));
}

char	*get_path_from_user_database(char *data){

	struct passwd	result;
	struct passwd	*resultp;
	int				e;
	char			buffer[10000];

	(void)data;
	if((e = getpwnam_r("mgiraud-", &result, buffer, 10000, &resultp)) != 0)
	{
		if (result.pw_dir)
			return(twl_strdup(result.pw_dir));
	}
	return (NULL);
}

int		get_position_last_char_of_tilde_prefix(char *str)
{
	int 	i;
	bool	between_double_quotes;
	bool	between_single_quotes;

	i = 0;
	between_double_quotes = false;
	between_single_quotes = false;
	while (str[i] != 0){
		if (str[i] == '"')
			between_double_quotes = !between_double_quotes;
		if (str[i] == '\'')
			between_single_quotes = !between_single_quotes;
		else if (str[i] == '/' && !between_double_quotes && !between_single_quotes)
			return (i - 1);
		i++;
	}
	return (i);
}

void	ast_simple_command_expan_tilde(t_token *token)
{
	char	*temp_string;
	char	*expansion_string;
	int		prefix_length;

	if (token->text)
	{
		if (token->text[0] == '~')
		{
			prefix_length = get_position_last_char_of_tilde_prefix(token->text);
			if (prefix_length > 1 && token->text[1] != '/'){
				temp_string = twl_strsub(token->text, 1, prefix_length);
				expansion_string = get_path_from_user_database(temp_string);
			}
			else
				expansion_string = get_home_path();
			if (expansion_string){
				token->text = twl_strjoinfree(expansion_string, &token->text[prefix_length + 1], 'l');
			}
		}
		else{
			return ;
		}
	}
}
