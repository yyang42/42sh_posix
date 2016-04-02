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

#include "builtin/cmds/builtin_wait.h"
#include <stdio.h>
#include <setjmp.h>

static jmp_buf jump_buf;

static void         sigint_handler(int sig)
{
    LOGGER_INFO("SIGINT handler: %d", sig);
    longjmp(jump_buf, 1);
}

void                builtin_wait_exec(t_lst *tokens, t_shenv *shenv)
{
    t_argparser_result *argparser_result;

    argparser_result = argparser_parse_tokens(builtin_wait_argparser(), tokens);
    shenv->shenv_cur_token = token_mgr_first(tokens);
    if (argparser_result->err_msg)
    {
        argparser_result_print_error_with_help(argparser_result);
        shenv->last_exit_code = EXIT_FAILURE;
    }
    else
    {
        signal(SIGINT, sigint_handler);
        if (setjmp(jump_buf) == 0)
        {
            builtin_wait_exec_segs(argparser_result);
        }
        else
        {
            shenv->last_exit_code = EXIT_FAILURE;
        }
        signal(SIGINT, SIG_IGN);
    }
}
