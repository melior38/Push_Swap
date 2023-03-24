/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:39:12 by asouchet          #+#    #+#             */
/*   Updated: 2023/03/03 21:14:03 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_env *env)
{
	t_list_nb	*tmp;

	tmp = env->a;
	while (tmp->next)
	{
		if (tmp->data < tmp->next->data)
			tmp = tmp->next;
		else
			return (1);
	}
	return (0);
}

void	free_tab(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
	split = NULL;
}
