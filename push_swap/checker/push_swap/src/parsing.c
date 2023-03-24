/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:39:32 by asouchet          #+#    #+#             */
/*   Updated: 2023/03/03 18:16:16 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (1);
}

int	ft_isdigit_in_str(char **av)
{
	int	i;
	int	k;

	i = 1;
	k = 0;
	while (av[i])
	{
		if (av[i][k] == '-')
			k++;
		while (av[i][k])
		{
			if (av[i][k] <= '9' && av[i][k] >= '0')
				k++;
			else
				return (1);
		}
		k = 0;
		i++;
	}
	return (0);
}

int	ft_intcmp(int a, int b)
{
	if (a == b)
		return (1);
	return (0);
}

int	ft_is_it_unique(char **av)
{
	int	k;
	int	i;
	int	l;

	i = 1;
	k = 1;
	l = 0;
	while (av[1 + l])
	{
		while (av[1 + l] && av[k + i])
		{
			if (ft_intcmp(ft_atoi(av[1 + l]), ft_atoi(av[k + i])))
				return (1);
			else
				i++;
		}
		l++;
		k++;
		i = 1;
	}
	return (0);
}

void	error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
