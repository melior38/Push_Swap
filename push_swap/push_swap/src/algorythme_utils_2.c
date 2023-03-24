/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythme_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:35:07 by asouchet          #+#    #+#             */
/*   Updated: 2023/03/03 18:05:44 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_data(t_env *env, int range, int type)
{
	if (type == RA)
	{
		while (env->a->data >= range && lst_len(env->a) > 1)
			ra(env);
	}
	else if (type == RRA)
	{
		while (env->a->data >= range && lst_len(env->a) > 1)
		{
			rra(env);
		}
	}
	if (env->a->data >= env->set.pivot)
		pb(env);
	else
	{
		pb(env);
		rb(env);
	}
}

void	mid_upper_chunk(t_env *env, t_list_nb *l, int range)
{
	int			mid;
	int			count;
	t_list_nb	*head;

	head = l;
	count = 0;
	mid = lst_len(l) / 2;
	while (l && l->data >= range)
	{
		count++;
		l = l->next;
	}
	l = head;
	if (count > mid)
		r_data(env, range, RRA);
	else
		r_data(env, range, RA);
}

void	set_t_setup(t_env *env, t_setup chunk_size)
{
	t_setup	tmp;

	tmp = chunk_size;
	tmp.chunk_data = x_min(env->a, tmp.chunk_size);
	tmp.pivot = x_min(env->a, tmp.chunk_size / 2);
	env->set = tmp;
}
