/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:29:37 by asouchet          #+#    #+#             */
/*   Updated: 2023/03/03 18:25:32 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
