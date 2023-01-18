/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:19:16 by asouchet          #+#    #+#             */
/*   Updated: 2023/01/18 15:39:09 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

// permet de cree une liste chainer vide une "une tete de liste"
t_list_nb	*empty_list(void)
{
	return (NULL);
}

int is_empty_list(t_list_nb *l)
{
	return (l == NULL);
}
// on aimerai avoir un moyen d'allouer dinamiquement des place dans la liste
// pour ca on va donc commencer par cree un outil qui cree un nouvel element de liste en pointeur
// puis set la valeur de next a NULL pour potentiellement modifier l'ordre des cellule dans le future
// <-.->
t_list_nb *create_list(int data)
{
	t_list_nb *list;

	list = malloc(sizeof(t_list_nb));
	if (!list)
		return (NULL);
	list->data = data;
	list->next = NULL;
	
	return (list);
}

t_list_nb	*free_list(t_list_nb *l)
{
	t_list_nb *tmp;

	tmp = NULL;
	while (l)
	{
		tmp = l->next;
		free(l);
		l = tmp;
	}
	return (l);
}

t_list_nb	*add_at(t_list_nb *l, int data, int pos)
{
	t_list_nb *prec;
	t_list_nb *cur;
	int		i;
	t_list_nb	*list;

	i = 0;
	prec = l;
	cur = l;
	list = create_list(data);
	if(is_empty_list(l))
		return (list);
	if (pos == 0)
	{
		list->next = l;
		return (list);
	}
	while (i < pos)
	{
		i++;
		prec = cur;
		cur = cur->next;
	}
	prec->next = list;
	list->next = cur;
	
	return (list);
}

void print_list(t_list_nb *l)
{
	while (!is_empty_list(l))
	{	
		printf("%d ", l->data);
		l = l->next;
	}
	printf("\n");
}
