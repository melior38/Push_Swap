/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:13:44 by asouchet          #+#    #+#             */
/*   Updated: 2023/02/09 14:50:23 by asouchet         ###   ########.fr       */
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

	i = 0;
	tmp = list;
	while (tmp->next != NULL)
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

	tmp = env->a;
	nex = tmp->data;
	cur = tmp->next->data;
	env->a->data = cur;
	env->a->next->data = nex;
	env->action++;
	printf("sa\n");
	// printf("cur[%d], nex[%d]\n", cur, nex);
}

void	sb(t_env *env)
{
	int			nex;
	int			cur;
	t_list_nb	*tmp;

	tmp = env->b;
	nex = tmp->data;
	cur = tmp->next->data;
	env->b->data = cur;
	env->b->next->data = nex;
	env->action++;
	printf("sb\n");
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
	printf("pb\n");
}

void	pa(t_env *env)
{
	t_list_nb	*tmp;

	tmp = env->b;
	env->b = env->b->next;
	ft_lst_add_front(&env->a, tmp);
	env->action++;
	printf("pa\n");
}

void	ra(t_env *env)
{
	t_list_nb	*tmp;

	tmp = env->a;
	tmp = tmp->next;
	env->a->next = NULL;
	ft_lst_add_back(&tmp, env->a);
	env->a = tmp;
	env->action++;
	printf("ra\n");
}

void	rb(t_env *env)
{
	t_list_nb	*tmp;

	tmp = env->b;
	tmp = tmp->next;
	env->b->next = NULL;
	ft_lst_add_back(&tmp, env->b);
	env->b = tmp;
	env->action++;
	printf("rb\n");
}

void	rr(t_env *env)
{
	ra(env);
	rb(env);
	printf("rr\n");
}

void	rra(t_env *env) // besoin de plus d'explication chuis duper
{
	t_list_nb	*tmp;
	t_list_nb	*old_head;
	t_list_nb	*new_last;

	if (!env->a)
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
	printf("rra\n");
}

void	rrb(t_env *env)
{
	t_list_nb	*tmp;
	t_list_nb	*old_head;
	t_list_nb	*new_last;

	if (!env->b)
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
	printf("rrb\n");

}

void	rrr(t_env *env)
{
	rra(env);
	rrb(env);
	env->action++;
	printf("rrr\n");

}