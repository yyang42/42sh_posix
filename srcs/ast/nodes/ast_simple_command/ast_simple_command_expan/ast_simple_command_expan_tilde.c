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

// "tilde-prefix" consists of an unquoted <tilde> character at the beginning of a word,
//followed by all of the characters preceding the first unquoted <slash> in the word,
// or all the characters in the word if there is no <slash>

/*
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
			twl_printf("%s\n", result.pw_dir);
			return(twl_strdup(result.pw_dir));
	}
	return (get_home_path());
}

int		get_position_last_char_of_tilde_prefix(char *str)
{
	int 	i;
	bool	between_quotes;

	i = 0;
	between_quotes = false;
	while (str[i] != 0){
		if (str[i] == '"')
			between_quotes = !between_quotes;
		else if (str[i] == '/' && !between_quotes)
			return (i - 1);
		i++;
	}
	return (i);
}
void	ast_simple_command_expan_tilde(t_token *token)
{
	char	*save_string;
	char	*temp_string;
	char	*expansion_string;
	int		prefix_length;

	save_string = NULL;
	if (token->text)
	{
		if (token->text[0] == '~')
		{
			save_string = twl_strdup(token->text);
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

	// t_token *token;
	// char	*words;
	// char	*home;
	// t_environment	*env;
	//
	// token = cmd->command_tokens;
	// words = twl_strsplit(token->text, " ")
	// env = environment_singleton();
	// if (!isDoubleQuoted(token->text) && !isSingleQuoted(token->text)){
	// 	twl_strdel(&token->text);
	// 	home = environment_getenv_value(env, "HOME")
	// 	if (home)
	// 		token->text = twl_strdup(home);
	// 	else
	// 		token->text = twl_strdup("");
	// }
}
