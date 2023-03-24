/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythme_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:31:30 by asouchet          #+#    #+#             */
/*   Updated: 2023/03/03 18:01:24 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	data_min(t_list_nb *pile, int data)
{
	t_list_nb	*tmp;

	tmp = pile;
	while (tmp)
	{
		if (tmp->data < data)
			data = tmp->data;
		tmp = tmp->next;
	}
	return (data);
}

int	data_max_utils(t_list_nb *pile, int data)
{
	t_list_nb	*tmp;

	tmp = pile;
	while (tmp)
	{
		if (tmp->data > data)
			data = tmp->data;
		tmp = tmp->next;
	}
	return (data);
}

int	data_max(t_list_nb *pile)
{
	int	max;

	if (!pile)
		return (2147483647);
	max = data_max_utils(pile, pile->data);
	while (max != data_max_utils(pile, max))
		max = data_max_utils(pile, pile->data);
	return (max);
}

int	secund_min(t_list_nb *pile, int first_min)
{
	t_list_nb	*head;
	t_list_nb	*tmp;
	t_cringe	cringe;

	cringe.save = first_min;
	tmp = pile;
	head = pile;
	cringe.count = 1;
	while (cringe.count != 0)
	{
		cringe.count = 0;
		while (tmp)
		{
			if ((first_min < tmp->data && cringe.save == first_min)
				|| (first_min > tmp->data && cringe.save < tmp->data))
			{
				first_min = tmp->data;
				cringe.count++;
			}
			tmp = tmp->next;
		}
		tmp = head;
	}
	pile = head;
	return (first_min);
}

int	x_min(t_list_nb *list, int x)
{
	int	min;
	int	i;

	i = 0;
	if (x == 0)
	{
		min = data_min(list, list->data);
		while (min != data_min(list, min))
			min = data_min(list, min);
		return (min);
	}
	min = data_min(list, list->data);
	while (min != data_min(list, min))
		min = data_min(list, min);
	while (i < x)
	{
		min = secund_min(list, min);
		i++;
	}
	return (min);
}
