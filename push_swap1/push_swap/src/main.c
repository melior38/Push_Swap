/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:39:12 by asouchet          #+#    #+#             */
/*   Updated: 2023/02/25 12:40:04 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	list_tools()

int	main(int ac, char **av)
{
	t_env	env; 
	char		**split_av;
	
	handle_error(ac, av);
	if (ac == 2)
	{
		split_av = ft_split(av[1], ' ');
		env.a = create_pile(split_av, 0);
		env.b = NULL;
		// env.b = create_pile(split_av, 1);
		// remember to free split_av
	}
	if (ac > 2)
	{
		env.a = create_pile(av + 1, 0);
		env.b = NULL;
		// env.b = create_pile(av + 1, 1);
	}
	// pb(&env);
	// pb(&env);
	set_t_setup(&env, 1);
	sort_100(&env);

	// print_list(pile_a);
	// printf("le 6eme plus petit[%d]\n", x_min(pile_a, 5));
	// printf("le 5eme plus petit[%d]\n", x_min(pile_a, 4));
	// printf("le 4eme plus petit[%d]\n", x_min(pile_a, 3));
	// printf("le 3eme plus petit[%d]\n", x_min(pile_a, 2));
	// printf("le 2eme plus petit[%d]\n", x_min(pile_a, 1));
	// printf("le plus petit[%d]\n", x_min(pile_a, 0));
	print_list(env.a);
	print_list(env.b);


	// pile_a = free_list(pile_a);
	// pile_b = free_list(pile_b);
}