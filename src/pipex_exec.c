/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:44:37 by rpinchas          #+#    #+#             */
/*   Updated: 2023/02/18 21:08:11 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_two(int *ultfd, t_struc *data)
{
	extern char	**environ;

	close(ultfd[1]);
	ultfd[2] = open(data[1].filename, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (ultfd[2] == -1)
		ft_eliminate(data, TYPE_STRUCT, EXIT);
	dup2(ultfd[0], STDIN_FILENO);
	dup2(ultfd[2], STDOUT_FILENO);
	execve(data[1].cmd, data[1].flag, environ);
}

void	child_one(int *ultfd, t_struc *data)
{
	extern char	**environ;

	close(ultfd[0]);
	ultfd[2] = open(data->filename, O_RDONLY);
	if (ultfd[2] == -1)
		ft_eliminate(data, TYPE_STRUCT, EXIT);
	dup2(ultfd[2], STDIN_FILENO);
	dup2(ultfd[1], STDOUT_FILENO);
	execve(data->cmd, data->flag, environ);
}

int	exec_cmd(t_struc *data)
{
	int		ultfd[3];
	int		status;
	pid_t	child1;
	pid_t	child2;

	if (pipe(ultfd) == -1)
		return (0);
	child1 = fork();
	if (child1 == -1)
		return (0);
	if (child1 == 0)
		child_one(ultfd, data);
	child2 = fork();
	if (child2 == -1)
		return (0);
	if (child2 == 0)
		child_two(ultfd, data);
	if (close(ultfd[0]) == -1 || close(ultfd[1]) == -1)
		perror("trouble");
	close(ultfd[2]);
	waitpid(child1, &status, 0);
	waitpid(child2, &status, 0);
	ft_eliminate(data, TYPE_STRUCT, STAY);
	return (1);

