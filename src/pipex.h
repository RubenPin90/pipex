/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:35:29 by rpinchas          #+#    #+#             */
/*   Updated: 2023/02/10 17:35:40 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include "/nfs/homes/rpinchas/chapter1/libft/libft.h"
# define TYPE_PTR 1
# define TYPE_ARRAY 2 
# define TYPE_STRUCT 3

typedef enum e_bool
{
	EXIT,
	STAY,
}	t_bool;

typedef struct s_data
{
	char			*cmd;
	char			**flag;
	char			*filename;
}					t_struc;

int		check_ac(int argc);
t_struc	*save_data(char **argv);
void	*find_cmd(t_struc *data, char **path, char *newcmd);
int		find_path(char **environ, t_struc *data);
int		exec_cmd(t_struc *data);
void	child_two(int *ultfd, t_struc *data);
void	child_two(int *ultfd, t_struc *data);
int		ft_eliminate(void *tnt, int type, t_bool check);
void	free_array(char **tnt);
void	free_struct(t_struc *tnt);
void	*free_null(char *ptr);

#endif
