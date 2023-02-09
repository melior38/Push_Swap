/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythme_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:31:30 by asouchet          #+#    #+#             */
/*   Updated: 2023/02/05 17:06:06 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// j'ai besoin de faire une fonciton qui trouve le plus petit
// une autre pour le plus grand
// une pour trouver la moitier du premier chunk
// et comment est ce que je parcour ma liste 
// fonction qui donne le x eme plus petit -> OK.

// int higher_data(t_list_nb *a, int *data_max)
// {
// 	t_list_nb	tmp;
	
// 	tmp = *a;
// 	while(tmp->next != NULL)
// 	{
// 		if (*(tmp.data) < data_max)
// 		{
// 			tmp_min = *(tmp.data);
// 			return (1);
// 		}
// 		tmp = *(tmp.next);
// 	}
// 	return (0);
// }

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
	// print_list(pile);
	return (data);
}

// solution possible c'est qu'avant de rentrer dans cette fonction on ajoute un noeud obsolete pour l'enlever apres operation
// on fait pointer head vers la tmp et tmp vers la pile pour garder une sauvegarde de la position une. ensuite on avance dans la liste
// tant qu'elle existe pour ensuite reset le tout en attribuant a tmp la head puis pile la head 

int secund_min(t_list_nb *pile, int first_min) 
{
	t_list_nb	*head;
	t_list_nb	*tmp;
	int			save;
	int			count;
	
	save = first_min;
	tmp = pile;
	head = pile;
	count = 1;
	while (count != 0)
	{
		count = 0;
		while (tmp)
		{
			if ((first_min < tmp->data && save == first_min) ||
			 (first_min > tmp->data && save < tmp->data))
			{
				first_min = tmp->data;
				count++;
			}
			tmp = tmp->next;
		}
		tmp = head;
	}
	pile = head;
	return (first_min);
}

int	x_min(t_list_nb *list, int x) // donne le nieme plus petit
{
	int min;
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
