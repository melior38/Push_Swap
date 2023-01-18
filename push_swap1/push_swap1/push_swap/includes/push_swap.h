/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:45:26 by asouchet          #+#    #+#             */
/*   Updated: 2023/01/18 15:43:59 by asouchet         ###   ########.fr       */
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
# define ERROR3 "there are 2 or more numbers that are the same in the chain\n"
# define ERROR4 "make sure to be in range of integer\n"

typedef struct s_list_nb {
	int		data;
	int		index;
	struct s_list_nb	*next;
}				t_list_nb;

int					handle_error(int ac, char **av);
int					ft_is_it_unique(char **av);
int					ft_intcmp(int a, int b);
int					ft_isdigit_in_str(char **av);
int					ft_putstr(char *str);
int					min_max_check(char **av);
void				error(void);
int					tester(char **av);

// LES LISTES DE L'ENFER
t_list_nb			*add_at(t_list_nb *l, int data, int pos);
t_list_nb			*empty_list(void);
t_list_nb			*free_list(t_list_nb *l);
int 				is_empty_list(t_list_nb *l);
t_list_nb 			*create_list(int data);
void 				print_list(t_list_nb *l);

// CREE LA PILE A ET B
t_list_nb			*create_pile_a(char **av);


#endif
