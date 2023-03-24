/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:19:16 by asouchet          #+#    #+#             */
/*   Updated: 2023/03/03 18:12:58 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_nb	*empty_list(void)
{
	return (NULL);
}

int	is_empty_list(t_list_nb *l)
{
	return (l == NULL);
}

t_list_nb	*create_list(int data)
{
	t_list_nb	*list;

	list = malloc(sizeof(t_list_nb));
	if (!list)
		return (NULL);
	list->data = data;
	list->next = NULL;
	return (list);
}

void	free_list(t_list_nb *l)
{
	t_list_nb	*tmp;

	tmp = NULL;
	while (l)
	{
		tmp = l->next;
		free(l);
		l = tmp;
	}
}

void	print_list(t_list_nb *l)
{
	while (!is_empty_list(l))
	{	
		printf("%d ", l->data);
		l = l->next;
	}
	printf("\n");
}
// t_list_nb	*add_at(t_list_nb *l, int data, int pos)
// {
// 	t_list_nb *prec;
// 	t_list_nb *cur;
// 	int		i;
// 	t_list_nb	*list;

// 	i = 0;
// 	prec = l;
// 	cur = l;
// 	list = create_list(data);
// 	if(is_empty_list(l))
// 		return (list);
// 	if (pos == 0)
// 	{
// 		list->next = l;
// 		return (list);
// 	}
// 	while (i < pos)
// 	{
// 		i++;
// 		prec = cur;
// 		cur = cur->next;
// 	}
// 	prec->next = list;
// 	list->next = cur;
// 	return (list);
// }
