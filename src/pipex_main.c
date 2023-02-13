/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:24:48 by rpinchas          #+#    #+#             */
/*   Updated: 2023/02/13 15:16:59 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	t_struc		*data;
	extern char	**environ;

	data = NULL;
	check_ac(argc);
	data = save_data(argv);
	if (!data)
		return (0);
	if (!find_path(environ, data))
		ft_eliminate(data, TYPE_STRUCT, STAY);
	if (!exec_cmd(data))
		ft_eliminate(data, TYPE_STRUCT, STAY);
	return (0);
}
