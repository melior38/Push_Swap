/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:12:56 by asouchet          #+#    #+#             */
/*   Updated: 2023/03/03 21:29:41 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	read_sort(t_env *env, char *line)
{
	if (!ft_strncmp(line, "sb\n", ft_strlen(line)))
		sb(env);
	else if (!ft_strncmp(line, "sa\n", ft_strlen(line)))
		sa(env);
	else if (!ft_strncmp(line, "ra\n", ft_strlen(line)))
		ra(env);
	else if (!ft_strncmp(line, "rb\n", ft_strlen(line)))
		rb(env);
	else if (!ft_strncmp(line, "rra\n", ft_strlen(line)))
		rra(env);
	else if (!ft_strncmp(line, "rrb\n", ft_strlen(line)))
		rrb(env);
	else if (!ft_strncmp(line, "ss\n", ft_strlen(line)))
		ss(env);
	else if (!ft_strncmp(line, "rr\n", ft_strlen(line)))
		rr(env);
	else if (!ft_strncmp(line, "rrr\n", ft_strlen(line)))
		rrr(env);
	else if (!ft_strncmp(line, "pa\n", ft_strlen(line)))
		pa(env);
	else if (!ft_strncmp(line, "pb\n", ft_strlen(line)))
		pb(env);
}

void	apply_sort(t_env *env)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		read_sort(env, line);
		line = get_next_line(0);
	}
	free(line);
	line = NULL;
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
	apply_sort(&env);
	if (is_sorted(&env))
		return (write(1, "KO\n", 3));
	write(1, "OK\n", 3);
	free_list(env.a);
	free_list(env.b);
	return (0);
}
