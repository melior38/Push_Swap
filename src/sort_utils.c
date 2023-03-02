/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:13:44 by asouchet          #+#    #+#             */
/*   Updated: 2023/03/02 16:39:59 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// sa
// sb	}	OK.
// ss

// pa
// pb	}	KO.

// ra
// rb	}	KO.
// rr

// rra 
// rrb
// rrr



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
		return 0;
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
	// printf("cur[%d], nex[%d]\n", cur, nex);
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
	// printf("cur[%d], nex[%d]\n", cur, nex);
}

void	ss(t_env *env)
{
	sa(env);
	sb(env);
	env->action++;
}

void	pb(t_env *env)
{
	t_list_nb	*tmp;
	
	tmp = env->a;
	env->a = env->a->next;
	ft_lst_add_front(&env->b, tmp);
	env->action++;
	write(1, "pb\n", 3);
}

void	pa(t_env *env)
{
	t_list_nb	*tmp;

	tmp = env->b;
	env->b = env->b->next;
	ft_lst_add_front(&env->a, tmp);
	env->action++;
	write(1, "pa\n", 3);
}

void	ra(t_env *env)
{
	t_list_nb	*tmp;

	if (!env->a || lst_len(env->a) == 1)
		return ;
	tmp = env->a;
	tmp = tmp->next;
	env->a->next = NULL;
	ft_lst_add_back(&tmp, env->a);
	env->a = tmp;
	env->action++;
	write(1, "ra\n", 3);
}

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

void	rr(t_env *env)
{
	ra(env);
	rb(env);
	write(1, "rr\n", 3);
}

void	rra(t_env *env) // besoin de plus d'explication chuis duper
{
	t_list_nb	*tmp;
	t_list_nb	*old_head;
	t_list_nb	*new_last;

	if (!env->a || lst_len(env->a) == 1)
		return ;
	tmp = env->a;
	old_head = env->a;
	while (tmp->next)
	{
		new_last = tmp;
		tmp = tmp->next;
	}
	ft_lst_add_front(&env->a, tmp);
	tmp->next = old_head;
	new_last->next = NULL;
	env->action++;
	write(1, "rra\n", 4);
}

void	rrb(t_env *env)
{
	t_list_nb	*tmp;
	t_list_nb	*old_head;
	t_list_nb	*new_last;

	if (!env->b || lst_len(env->b) == 1)
		return ;
	tmp = env->b;
	old_head = env->b;
	while (tmp->next)
	{
		new_last = tmp;
		tmp = tmp->next;
	}
	ft_lst_add_front(&env->b, tmp);
	tmp->next = old_head;
	new_last->next = NULL;
	env->action++;
	write(1, "rrb\n", 4);
}

void	rrr(t_env *env)
{
	rra(env);
	rrb(env);
	env->action++;
	write(1, "rrr\n", 4);
}