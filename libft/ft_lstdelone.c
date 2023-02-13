/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 19:28:42 by rpinchas          #+#    #+#             */
/*   Updated: 2022/10/24 12:20:43 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	del(lst->content);
	free(lst);
}
/*
int main()
{
	t_list	*head;
	char	name[] = "Ruben";
	char	name2[] = "Gabriel";
	char	name3[] = "Annie";

	head = ft_lstnew(name);
	ft_lstadd_front(&head, ft_lstnew(name2));
	printf("%d\n", ft_lstsize(head));
	printf("%s\n", (char *)ft_lstlast(head)->content);
	ft_lstadd_back(&head, ft_lstnew(name3));
	printf("%s\n", (char *)ft_lstlast(head)->content);
	return (0);
}
*/
