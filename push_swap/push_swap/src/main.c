/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:39:12 by asouchet          #+#    #+#             */
/*   Updated: 2023/03/13 16:43:06 by asouchet         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_env	env;
	char	**split_av;

	handle_error(ac, av);
	if (ac == 2)
	{
		split_av = ft_split(av[1], ' ');
		env.a = create_pile(split_av, 0);
		env.b = NULL;
		free_tab(split_av);
	}
	if (ac > 2)
	{
		env.a = create_pile(av + 1, 0);
		env.b = NULL;
	}
	if (!is_sorted(&env))
		exit(0);
	set_t_setup(&env, env.set);
	sort(&env);
	free_list(env.a);
	free_list(env.b);
	return (0);
}
