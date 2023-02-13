/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:08:14 by rpinchas          #+#    #+#             */
/*   Updated: 2023/02/10 18:05:04 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_ac(int argc)
{
	if (argc < 5 || argc > 5)
	{
		perror("Not enough arguments");
		exit(0);
	}
	else
		return (0);
}

int	find_path(char **environ, t_struc *data)
{
	char	**path;

	while (*environ)
	{
		if (!ft_strncmp(*environ, "PATH=", 5))
			break ;
		environ++;
	}
	path = ft_split(*environ + 5, ':');
	if (!path)
		return (ft_eliminate(path, TYPE_ARRAY, STAY));
	if (!(find_cmd(&data[0], path, 0)))
	{
		ft_eliminate(path, TYPE_ARRAY, STAY);
		ft_eliminate(data, TYPE_STRUCT, EXIT);
	}
	if (!(find_cmd(&data[1], path, 0)))
	{
		ft_eliminate(path, TYPE_ARRAY, STAY);
		ft_eliminate(data, TYPE_STRUCT, EXIT);
	}
	ft_eliminate(path, TYPE_ARRAY, STAY);
	return (1);
}

void	*find_cmd(t_struc *input, char **path, char *cmdpath)
{
	int		i;
	char	*tmp;

	i = 0;
	while (path[i])
	{	
		cmdpath = ft_strjoin("/", input->cmd);
		if (!cmdpath)
			return (NULL);
		tmp = cmdpath;
		cmdpath = ft_strjoin(path[i], cmdpath);
		free_null(tmp);
		if (!cmdpath)
			return (free_null(cmdpath));
		if (access(cmdpath, F_OK | X_OK) == 0)
		{
			free_null(input->cmd);
			input->cmd = cmdpath;
			break ;
		}
		free_null(cmdpath);
		i++;
	}
	return (input);
}

t_struc	*save_data(char **argv)
{
	t_struc	*input;

	input = (t_struc *) ft_calloc(sizeof(t_struc), 2);
	if (!input)
		return (NULL);
	input[0].filename = argv[1];
	input[1].filename = argv[4];
	input[0].flag = ft_split(argv[2], ' ');
	if (!input[0].flag)
		ft_eliminate(input, TYPE_STRUCT, EXIT);
	input[0].cmd = ft_strdup(input[0].flag[0]);
	if (!input[0].cmd)
		return (free_null(input[0].cmd));
	input[1].flag = ft_split(argv[3], ' ');
	if (!input[1].flag)
		ft_eliminate(input, TYPE_STRUCT, EXIT);
	input[1].cmd = ft_strdup(input[1].flag[0]);
	if (!input[1].cmd)
		return (free_null(input[1].cmd));
	return (input);
}
