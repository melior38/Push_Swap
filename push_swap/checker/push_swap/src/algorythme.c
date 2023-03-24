/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:08:26 by asouchet          #+#    #+#             */
/*   Updated: 2023/03/03 17:53:42 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_env *env)
{
	if (env->a->data == x_min(env->a, 3))
	{
		ra(env);
		if (env->a->next->data == x_min(env->a, 0))
			sa(env);
	}
	else if (env->a->data == x_min(env->a, 0))
	{
		if (env->a->next->data == x_min(env->a, 3))
		{
			rra(env);
			sa(env);
		}
	}
	else
	{
		if (env->a->next->data == x_min(env->a, 0))
			sa(env);
		else
			rra(env);
	}
}

void	sort_100(t_env *env)
{
	int			loop;
	int			i;
	t_setup		tmp;

	tmp.chunk_size = lst_len(env->a) / 4;
	loop = 0;
	i = 1;
	while (loop < 4)
	{
		set_t_setup(env, tmp);
		while (env->set.chunk_size >= i)
		{
			mid_upper_chunk(env, env->a, env->set.chunk_data);
			i++;
		}
		loop++;
		i = 1;
	}
	if (lst_len(env->a) == 3)
		sort_3(env);
	else if (lst_len(env->a) == 2)
		if (env->a->data > env->a->next->data)
			sa(env);
	push_to_a(env);
}

void	sort_500(t_env *env)
{
	int			loop;
	int			i;
	t_setup		tmp;

	loop = 0;
	i = 1;
	while (lst_len(env->a) > 3)
	{
		if (loop < 5)
			tmp.chunk_size = lst_len(env->a) / (10 - loop);
		set_t_setup(env, tmp);
		while (env->set.chunk_size >= i)
		{
			mid_upper_chunk(env, env->a, env->set.chunk_data);
			i++;
		}
		loop++;
		i = 1;
	}
	if (lst_len(env->a) == 3)
		sort_3(env);
	else if (lst_len(env->a) == 2)
		if (env->a->data < env->a->next->data)
			sa(env);
	push_to_a(env);
}

void	sort_5(t_env *env)
{
	while (lst_len(env->a) > 3)
	{
		while (x_min(env->a, 0) != env->a->data)
			ra(env);
		pb(env);
	}
	sort_3(env);
	if (env->b->data < env->b->next->data)
		sa(env);
	pa(env);
	pa(env);
}

// ./visualizer/build/bin/visualizer