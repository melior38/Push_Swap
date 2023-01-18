/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:25:12 by asouchet          #+#    #+#             */
/*   Updated: 2023/01/18 15:46:16 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_nb	*create_pile(char **av, int a)
{
	t_list_nb	*pile;
	int			i;

	i = 0;
	if (a <= 0)
	{
		while (av[i])
		{
			pile = add_at(pile, atoi(av[i]), 0);
			i++;
		}
	}
	else
	{
		while (av[i])
		{
			pile = create_list(0);
			i++;
		}
	}
	return (pile);
}

int	main(int ac, char **av)
{
	t_list_nb	*pile_a;
	t_list_nb	*pile_b;
	
	handle_error(ac, av);
	pile_a = create_pile(av, 0);
	pile_b = create_pile(av, 1);
	print_list(pile_a);


	pile_a = free_list(pile_a);
	pile_b = free_list(pile_b);
}