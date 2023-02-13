/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:29:21 by rpinchas          #+#    #+#             */
/*   Updated: 2023/02/13 15:23:00 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_eliminate(void *tnt, int type, t_bool check)
{
	char	**array;
	t_struc	*nodes;

	if (tnt != NULL)
	{	
		if (type == TYPE_ARRAY)
		{
			array = (char **)tnt;
			free_array(array);
		}
		if (type == TYPE_STRUCT)
		{
			nodes = (t_struc *)tnt;
			free_struct(nodes);
		}
	}
	if (check == EXIT)
	{
		perror("EXIT ERROR");
		exit(0);
	}
	return (0);
}

void	free_array(char **tnt)
{
	int	i;

	i = 0;
	while ((tnt)[i])
	{
		free_null(tnt[i]);
		i++;
	}
	free(tnt);
	tnt = NULL;
}

void	free_struct(t_struc *tnt)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (tnt[i].cmd != NULL)
			free_null(tnt[i].cmd);
		if (tnt[i].flag != NULL)
			free_array(tnt[i].flag);
		i++;
	}
	free(tnt);
	tnt = NULL;
}

void	*free_null(char *ptr)
{
	if (ptr != NULL)
	{
		free(ptr);
		ptr = NULL;
	}
	return (NULL);
}
