/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:25:12 by asouchet          #+#    #+#             */
/*   Updated: 2023/03/03 18:11:45 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lst_add_front(t_list_nb **lst, t_list_nb *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
	return ;
}

void	ft_lst_add_back(t_list_nb **lst, t_list_nb *new)
{
	t_list_nb	*tmp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = ft_lst_last(*lst);
	tmp->next = new;
}

t_list_nb	*create_pile(char **av, int a)
{
	t_list_nb	*pile;
	int			i;

	i = 0;
	pile = NULL;
	if (a <= 0)
	{
		while (av[i])
		{
			ft_lst_add_back(&pile, ft_lst_new(ft_atoi(av[i])));
			i++;
		}
	}
	return (pile);
}
