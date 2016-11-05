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

#include "ast/nodes/ast_andor_item.h"
#include "job_control/job.h"

//static void			wait_last_pipe_item(t_ast_pipe_item *ast_pipe_item)
//{
//	LOG_DEBUG("job_utils_waitpid");
//	job_utils_waitpid(ast_pipe_item->pipe_child_pid, NULL);
//}

//static void			andor_fn_2(t_ast_pipe_item *pi)
//{
//	if (pi->pipe_child_pid == 0)
//	{
//		if (pi->pipe_write_end != -1 && dup2(pi->pipe_write_end, 1) < 0)
//		{
//			LOG_ERROR("dup2: %s", twl_strerror(errno));
//		}
//		if (pi->pipe_read_end != -1 && dup2(pi->pipe_read_end, 0) < 0)
//		{
//			LOG_ERROR("dup2: %s", twl_strerror(errno));
//		}
//		ast_pipe_item_exec(pi);
//		shenv_utils_exit(shenv_singleton()->last_exit_code);
//	}
//	else
//	{
//		if (pi->pipe_read_end != -1 && close(pi->pipe_read_end) < 0)
//		{
//			LOG_ERROR("close: %s", twl_strerror(errno));
//		}
//		if (pi->pipe_write_end != -1 && close(pi->pipe_write_end) < 0)
//		{
//			LOG_ERROR("close: %s", twl_strerror(errno));
//		}
//	}
//}
//
//static void			iter_andor_fn(void *pi_)
//{
//	t_ast_pipe_item	*pi;
//
//	pi = pi_;
//	LOG_DEBUG("pi->pipe_read_end: %d", pi->pipe_read_end);
//	LOG_DEBUG("pi->pipe_write_end: %d", pi->pipe_write_end);
//	pi->pipe_child_pid = shenv_utils_fork();
//	if (pi->pipe_child_pid == -1)
//	{
//		LOG_ERROR("fork: %s", twl_strerror(errno));
//		if (pi->pipe_read_end != -1)
//		{
//			if (close(pi->pipe_read_end) < 0)
//				LOG_ERROR("close: %s", twl_strerror(errno));
//		}
//		if (pi->pipe_write_end != -1)
//		{
//			if (close(pi->pipe_write_end) < 0)
//				LOG_ERROR("close: %s", twl_strerror(errno));
//		}
//	}
//	else
//	{
//		andor_fn_2(pi);
//	}
//}
//
//static void			iter_fds_fn(void *pi_, void *pi_next_, void *ctx)
//{
//	t_ast_pipe_item	*pi;
//	t_ast_pipe_item	*pi_next;
//	int				fds[2];
//
//	if (pipe(fds) < 0)
//		LOG_ERROR("pipe: %s", twl_strerror(errno));
//	pi = pi_;
//	pi_next = pi_next_;
//	if (pi_next)
//	{
//		pi_next->pipe_read_end = fds[0];
//		pi->pipe_write_end = fds[1];
//	}
//	iter_andor_fn(pi);
//	(void)ctx;
//}

static void			iter_fds_fn(void *data, void *data_prev,
		void *data_next, void *ctx)
{
	t_ast_pipe_item	*prev;
	t_ast_pipe_item	*curr;
	t_ast_pipe_item	*next;
	int				fds[2];
	pid_t			id;

	prev = data_prev;
	curr = data;
	next = data_next;
	if (next)
	{
		pipe(fds);
		curr->pipe_write_end = fds[1];
		next->pipe_read_end = fds[0];
		if ((id = shenv_utils_fork()) == -1)
		{
			LOG_ERROR("fork: %s", twl_strerror(errno));
		}
		else if (id == 0)
		{
			if (prev)
			{
				dup2(curr->pipe_read_end, 0);
				// twl_dprintf(2, "fork = 0 :: dup2(curr->pipe_read_end (%i), 0): next && prev\n", curr->pipe_read_end);
				close(prev->pipe_write_end);
				// twl_dprintf(2, "fork = 0 :: close(prev->pipe_write_end (%i)): next && prev\n", prev->pipe_write_end);
			}
			dup2(curr->pipe_write_end, 1);
			// twl_dprintf(2, "fork = 0 :: dup2(curr->pipe_write_end (%i), 1): next\n", curr->pipe_write_end);
			close(next->pipe_read_end);
			// twl_dprintf(2, "fork = 0 :: close(next->pipe_read_end (%i)): next\n", next->pipe_read_end);
			ast_pipe_item_exec(curr);
			shenv_utils_exit(shenv_singleton()->last_exit_code);
		}
	}
	else
	{
		if (prev)
		{
			dup2(curr->pipe_read_end, 0);
			// twl_dprintf(2, "nofork :: dup2(curr->pipe_read_end (%i), 0): prev\n", curr->pipe_read_end);
			close(prev->pipe_write_end);
			// twl_dprintf(2, "nofork :: close(prev->pipe_write_end (%i)): prev\n", prev->pipe_write_end);
		}
		//twl_printf("je passe ici\n");
		ast_pipe_item_exec(curr);
		shenv_utils_exit(shenv_singleton()->last_exit_code);
	}
	(void)ctx;
}

void				ast_andor_item_exec_pipes(t_ast_andor_item *this)
{
	pid_t			id;

	if ((id = shenv_utils_fork()) == -1)
	{
		LOG_ERROR("fork: %s", twl_strerror(errno));
	}
	else if (id == 0)
		twl_lst_iternp(this->ast_pipe_items, iter_fds_fn, NULL);
	else
		wait(NULL);
		//wait_last_pipe_item(twl_lst_last(this->ast_pipe_items));
}
//static const char *path[] =
//{
//	"/usr/bin/python",
//	"/usr/bin/head",
//	"/usr/bin/grep"
//};
//static char *args1[] = { "/usr/bin/python", "-c", "print 'a' * 16384", NULL };
//static char *args2[] = { "/usr/bin/head",   "-c", "1000",   NULL };
//static char *args3[] = { "/usr/bin/grep",   "a",            NULL };
//
//
//char **dup_arr(const char *as[])
//{
//    int i = 0;
//    char **ret;
//    while (as[i])
//        i += 1;
//    ret = malloc(sizeof(char *) * (i + 1));
//    i = 0;
//    while (as[i])
//    {
//        ret[i] = strdup(as[i]);
//        i+=1;
//    }
//    ret[i] = NULL;
//    return (ret);
//}
//
//void dump_arr(char **arr)
//{
//    while (*arr)
//    {
//        arr+=1;
//    }
//}
//
//
//void				ast_andor_item_exec_pipes(t_ast_andor_item *this)
//{
//    int fd1[2];
//
//    if (fork() > 0)
//    {
//        wait(NULL);
//    }
//    else
//    {
//        pipe(fd1);
//        if (fork() > 0)
//        {
//            int fd2[2];
//
//            pipe(fd2);
//            if (fork() > 0)
//            {
//                dup2(fd2[0], 0);
//                close(fd2[1]);
//                execve(path[2], args3, NULL);
//            }
//            else
//            {
//                dup2(fd1[0], 0);
//                close(fd1[1]);
//                dup2(fd2[1], 1);
//                close(fd2[0]);
//                execve(path[1], args2, NULL);
//            }
//        }
//        else
//        {
//            dup2(fd1[1], 1);
//            close(fd1[0]);
//            execve(path[0], args1, NULL);
//        }
//    }
//	(void)this;
//}
