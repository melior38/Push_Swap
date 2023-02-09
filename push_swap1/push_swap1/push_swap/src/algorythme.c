/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:08:26 by asouchet          #+#    #+#             */
/*   Updated: 2023/02/05 17:23:20 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	sort(t_env *env)
// {
// 	int	model;

// 	model = sort_case(env);
// 	if (model == 0)
// 		sort_3(env);
// 	if (model == 1)
// 		sort_100(env);
// 	if (model == 2)
// 		sort_300(env);
// 	if (model == 3)
// 		sort_500(env);
// }

int	sort_case(t_env *env)
{
	int	size;
	int sort_case;

	size = lst_len(env->a) + 1;
	if (size >= 4 && size <= 15)
		sort_case = 1;
	else if (size >= 16 && size <= 100)
		sort_case = 2;
	else if (size >= 101 && size <= 300)
		sort_case = 3;
	else if (size >= 301)
		sort_case = 4;
	else if (size >= 501)
		sort_case = 5;
	else 
		sort_case = 0;
	return (sort_case);
}

void	sort_3(t_env *env)
{
	int	max;
	int min;

	min = x_min(env->a, 0);
	// printf("%d\n", min);
	max = x_min(env->a, 3);
	// printf("%d\n", max);
	if (env->a->data == max)
	{
		ra(env);
		if (env->a->next->data == min)
			sa(env);
	}
	else if (env->a->data == min)
	{
		if (env->a->next->data == max)
		{
			rra(env);
			sa(env);
		}
	}
	else 
	{
		if (env->a->next->data == min)
			sa(env);
		else
		{
			rra(env);
		}
	}
}

void	sort_100(t_env *env)
{
	int l_len;
	int chunk;
	t_list_nb	*tmp;

	tmp = env->a;
	l_len = lst_len(env->a);
	chunk = l_len / 4;
	l_len = 0;
	while (chunk >= l_len++) // tu peut deja penser a une opti du genre si on se trouve a + de la moitier de la liste ou pas
	{
		
	}

}

// void	sort_300(t_env *env)
// {}

// void	sort_500(t_env *env)
// {}