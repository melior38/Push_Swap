/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:17:34 by asouchet          #+#    #+#             */
/*   Updated: 2023/03/03 20:05:57 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include "push_swap.h"
// # include "libft.h"

void			apply_sort(t_env *env);
void			read_sort(t_env *env, char *line);

#endif