/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:22:04 by asouchet          #+#    #+#             */
/*   Updated: 2023/03/03 18:27:34 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_env *env)
{
	t_list_nb	*tmp;

	if (!env->b || lst_len(env->b) == 1)
		return ;
	tmp = env->b;
	tmp = tmp->next;
	env->b->next = NULL;
	ft_lst_add_back(&tmp, env->b);
	env->b = tmp;
	env->action++;
	write(1, "rb\n", 3);
}

int	up_or_down(t_list_nb *pile)
{
	int			mid;
	int			count;
	t_list_nb	*head;

	if (!pile)
		return (-1);
	head = pile;
	count = 0;
	mid = lst_len(pile) / 2;
	while (pile && pile->data != data_max(pile))
	{
		count++;
		pile = pile->next;
	}
	pile = head;
	if (count > mid)
		return (1);
	else
		return (0);
}

int	under_data(t_list_nb *pile)
{
	int	res;

	if (!pile)
		return (2147483647);
	while (pile->next)
		pile = pile->next;
	res = pile->data;
	return (res);
}
