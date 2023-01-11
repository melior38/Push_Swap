/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:45:26 by asouchet          #+#    #+#             */
/*   Updated: 2023/01/11 18:57:52 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

# define ERROR1 "please enter the right amount of argument\n"
# define ERROR2 "make sure to input only numbers\n"
# define ERROR3 "there are 2 or more number that are the same in the chain\n"

// typedef struct s_list {
// 	char	*value;
// 	int		index;
// 	struct s_list	*next;
// }				t_list;

int		handle_error(int ac, char **av);
int		ft_is_it_unique(char **av);
int		ft_intcmp(int a, int b);
int		ft_isdigit_in_str(char **av);
int		ft_putstr(char *str);


#endif
