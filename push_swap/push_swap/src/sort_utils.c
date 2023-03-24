/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:13:44 by asouchet          #+#    #+#             */
/*   Updated: 2023/03/03 18:19:33 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_nb	*ft_lst_last(t_list_nb *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

t_list_nb	*ft_lst_new(int content)
{
	t_list_nb	*new;

	new = malloc(sizeof(t_list_nb));
	if (!new)
		return (NULL);
	new->data = content;
	new->next = NULL;
	return (new);
}

int	lst_len(t_list_nb *list)
{
	t_list_nb	*tmp;
	int			i;

	if (!list)
		return (0);
	i = 0;
	tmp = list;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	sa(t_env *env)
{
	int			nex;
	int			cur;
	t_list_nb	*tmp;

	if (!env->a || lst_len(env->a) == 1)
		return ;
	tmp = env->a;
	nex = tmp->data;
	cur = tmp->next->data;
	env->a->data = cur;
	env->a->next->data = nex;
	env->action++;
	write(1, "sa\n", 3);
}

void	sb(t_env *env)
{
	int			nex;
	int			cur;
	t_list_nb	*tmp;

	if (!env->b || lst_len(env->b) == 1)
		return ;
	tmp = env->b;
	nex = tmp->data;
	cur = tmp->next->data;
	env->b->data = cur;
	env->b->next->data = nex;
	env->action++;
	write(1, "sb\n", 3);
}
