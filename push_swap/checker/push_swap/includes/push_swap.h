/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:45:26 by asouchet          #+#    #+#             */
/*   Updated: 2023/03/03 18:30:15 by asouchet         ###   ########.fr       */
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

# define RRA 2134
# define RA 3212

typedef struct s_list_nb {
	int					data;
	struct s_list_nb	*next;
}				t_list_nb;

typedef struct s_setup {
	int	chunk_data;
	int	pivot;
	int	chunk_size;
}				t_setup;

typedef struct s_env {
	t_list_nb	*a;
	t_list_nb	*b;
	int			action;
	t_setup		set;
}				t_env;

typedef struct s_cringe {
	int	save;
	int	count;
}				t_cringe;

int					handle_error(int ac, char **av);
int					ft_is_it_unique(char **av);
int					ft_intcmp(int a, int b);
int					ft_isdigit_in_str(char **av);
int					ft_putstr(char *str);
int					min_max_check(char **av);
void				error(void);
int					tester(char **av);
void				free_tab(char **split);
int					is_sorted(t_env *env);

// LES LISTES DE L'ENFER
t_list_nb			*add_at(t_list_nb *l, int data, int pos);
t_list_nb			*empty_list(void);
void				free_list(t_list_nb *l);
int					is_empty_list(t_list_nb *l);
t_list_nb			*create_list(int data);
void				print_list(t_list_nb *l);

// CREE LA PILE A ET B
t_list_nb			*create_pile(char **av, int a);
t_list_nb			*ft_lst_new(int content);
void				ft_lst_add_back(t_list_nb **lst, t_list_nb *new);
t_list_nb			*ft_lst_last(t_list_nb *lst);
void				ft_lst_add_front(t_list_nb **lst, t_list_nb *new);
int					lst_len(t_list_nb *list);

// SORT UTILS
void				sa(t_env *env);
void				sb(t_env *env);
void				ss(t_env *env);
void				pa(t_env *env);
void				pb(t_env *env);
void				rrr(t_env *env);
void				rr(t_env *env);
void				ra(t_env *env);
void				rra(t_env *env);
void				rb(t_env *env);
void				rrb(t_env *env);

// ALGORYTHME UTILS
int					x_min(t_list_nb *list, int x);
int					secund_min(t_list_nb *pile, int first_min);
int					data_min(t_list_nb *pile, int min);
void				mid_upper_chunk(t_env *env, t_list_nb *l, int range);
void				r_data(t_env *env, int data, int type);
void				set_t_setup(t_env *env, t_setup chunk_size);
int					data_max(t_list_nb *pile);
int					data_max_utils(t_list_nb *pile, int data);
int					lst_len_modified(t_list_nb *list);
int					up_or_down(t_list_nb *pile);
int					under_data(t_list_nb *pile);
void				push_to_a(t_env *env);
int					sort_opti(t_env *env);

// ALGO
void				sort(t_env *env);
int					sort_case(t_env *env);
void				sort_3(t_env *env);
void				sort_5(t_env *env);
void				sort_100(t_env *env);
void				sort_500(t_env *env);

#endif
