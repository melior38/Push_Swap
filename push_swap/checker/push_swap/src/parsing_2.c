/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:42:12 by asouchet          #+#    #+#             */
/*   Updated: 2023/03/03 18:18:40 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	tester(char **av)
{
	if (ft_isdigit_in_str(av))
		error();
	if (ft_is_it_unique(av))
		error();
	return (0);
}

int	handle_error(int ac, char **av)
{
	char	*tmp;

	if (ac == 1)
		error();
	else if (ac == 2)
	{
		if (!av[1][0])
			error();
		tmp = ft_strjoin("./pushswap ", av[1]);
		tester(ft_split(tmp, ' '));
	}
	else if (ac > 2)
		tester(av);
	return (0);
}
