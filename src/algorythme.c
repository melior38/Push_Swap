/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:08:26 by asouchet          #+#    #+#             */
/*   Updated: 2023/03/02 17:09:09 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	sort(t_env *env)
// {
// 	int	model;

// 	model = sort_case(env);
// 	if (model == 0)
// 		sort_3(env);
// 	if (model == 1)
// 		sort_100(env);
// 	if (model == 2)
// 		sort_300(env);
// 	if (model == 3)
// 		sort_500(env);
// }

int	sort_case(t_env *env)
{
	int	size;
	int sort_case;

	size = lst_len(env->a);
	if (size >= 4 && size <= 15)
		sort_case = 1;
	else if (size >= 16 && size <= 100)
		sort_case = 2;
	else if (size >= 101 && size <= 300)
		sort_case = 3;
	else if (size >= 301)
		sort_case = 4;
	else if (size >= 501)
		sort_case = 5;
	else 
		sort_case = 0;
	return (sort_case);
}

void	sort_3(t_env *env)
{
	int	max;
	int min;

	min = x_min(env->a, 0);
	// printf("%d\n", min);
	max = x_min(env->a, 3);
	// printf("%d\n", max);
	if (env->a->data == max)
	{
		ra(env);
		if (env->a->next->data == min)
			sa(env);
	}
	else if (env->a->data == min)
	{
		if (env->a->next->data == max)
		{
			rra(env);
			sa(env);
		}
	}
	else
	{
		if (env->a->next->data == min)
			sa(env);
		else
			rra(env);
	}
}

int	up_or_down(t_list_nb *pile)
{
	int			mid;
	int			count;
	t_list_nb	*head;

	if (!pile)
		return (-1);
	head = pile;
	count = 0;
	mid = lst_len(pile) / 2;
	while (pile && pile->data != data_max(pile))
	{
		count++;
		pile = pile->next;
	}
	// printf("this is the current count {%d}\n", count);
	pile = head;
	if (count > mid)
		return (1);
	else
		return (0);
}

int	under_data(t_list_nb *pile)
{
	int	res;

	if (!pile)
		return (2147483647);
	while (pile->next)
		pile = pile->next;
	// printf("lol\n\n");
	res = pile->data;
	// printf("lol\n\n");
	return (res);
}

int	sort_opti(t_env *env, int data)
{
    // je dois checker en premier si le fond de ma liste a contient le chiffre rechercher
    // ensuite je check si le chiffre en fond de ma list c le data_max de a si oui je push le premier element de b no matter what
    // ensuite je check si l'element en bas de ma pile a est plus grand que l'element que je check dans la pile b
    // si oui je le pb puis rotate / si non il se passe rien
	(void)	data;

	if (env->b->data == data_max(env->b))
		return (0);
    if (data_max(env->a) == under_data(env->a) && lst_len(env->b) != 2) // check le plus grand
    {
        pa(env);
        ra(env);
    }
	if (under_data(env->a) < env->b->data && lst_len(env->b) != 2)
    {
		pa(env);
		ra(env);
	}
	// if (under_data(env->a) >= data_max(env->b)) 
	// 	rra(env);
	return (1);
}

void	push_to_a(t_env *env)
{
	while (env->b)
	{
		// write(1, "error2\n", 7);
		while (env->b->data != data_max(env->b) && lst_len(env->b) != 0)
		{
			// write(1, "error\n", 6);
			sort_opti(env, env->b->data);
			// write(1, "error3\n", 6);
			if (up_or_down(env->b) == 1)
				rrb(env);
			else if (up_or_down(env->b) == 0)
				rb(env);
			// write(1, "error4\n", 6);

		}
	 	if (lst_len(env->b) >= 1)
			sort_opti(env, env->b->data);
		while (under_data(env->a) > env->b->data && under_data(env->a) != 2147483647 && under_data(env->a) != data_max(env->a))
			rra(env);
		pa(env);
	}
	while (under_data(env->a) != data_max(env->a))
		rra(env);
}

int	lst_len_modified(t_list_nb *list)
{
		t_list_nb	*tmp;
	int			i;

	i = 0;
	tmp = list;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void    sort_100(t_env *env)
{
	int			loop;
	int			i;
	t_setup		tmp;

	tmp.chunk_size = lst_len(env->a) / 4;
    loop = 0;
	i = 1;
	while (loop < 4)
	{
		set_t_setup(env, tmp);
		while (env->set.chunk_size >= i)
		{
			mid_upper_chunk(env, env->a, env->set.chunk_data);
			i++;
		}
		loop++;
		i = 1;
	}
	if (lst_len(env->a) == 3)
		sort_3(env);
	else if (lst_len(env->a) == 2)
		if (env->a->data > env->a->next->data)
			sa(env);
	push_to_a(env);
}

void    sort_500(t_env *env)
{
	int			loop;
	int			i;
	t_setup		tmp;

    loop = 0;
	i = 1;
	while (lst_len_modified(env->a) > 3)
	{
		if (loop < 5)
			tmp.chunk_size = lst_len(env->a) / (10 - loop);
		set_t_setup(env, tmp);
		while (env->set.chunk_size >= i)
		{
			mid_upper_chunk(env, env->a, env->set.chunk_data);
			i++;
		}
		loop++;
		i = 1;
	}
	if (lst_len(env->a) == 3)
		sort_3(env);
	else if (lst_len(env->a) == 2)
		if (env->a->data < env->a->next->data)
			sa(env);
	push_to_a(env);
}
// void	sort_300(t_env *env)
// {}

// void	sort_500(t_env *env)
// {}

//https://www.calculatorsoup.com/calculators/statistics/random-number-generator.php
// 50 numbers 33 39 15 50 23 47 22 20 6 9 24 40 29 7 3 31 27 21 12 38 30 45 41 48 19 36 4 32 26 17 14 37 13 5 11 49 25 28 1 34 35 44 43 10 42 8 2 18 46 16 
// 500 numbers -1000 1281 987 291 543 1902 -1845 -437 -267 -1320 1373 -1905 727 260 -44 -1963 1227 943 -1060 1003 176 1 -163 737 -1415 1474 1987 -1814 1507 -1525 1034 -1621 -1921 1091 -810 125 -1913 1609 -1977 -621 1429 764 -156 -1062 1537 -964 -389 -1452 -517 -1915 -566 -1384 -64 1518 -110 -103 1844 -1180 -940 23 44 -908 -591 -75 -1002 1190 -1066 2029 -1906 367 770 -1353 102 -89 74 -1625 1261 214 916 -21 370 -890 803 830 -698 -154 -588 -844 1944 -901 -728 -1112 -1041 -939 -1891 -1511 -967 1063 -2126 -1630 479 -1949 1850 -1975 -1998 1028 -664 -1947 1650 1773 -1826 -2100 2017 1410 1864 -102 -257 911 252 -319 831 2026 61 231 -2015 582 -2086 1847 1102 -1022 695 1252 -982 1240 -1974 -670 -1448 -1287 -204 -32 -1817 1047 -137 1362 -1877 -1219 -152 918 1726 320 -236 1804 -558 2030 -1737 -1873 1365 2010 -1467 -399 382 19 1801 -326 1723 -971 1759 -1969 709 -1347 -536 -242 -327 1248 1805 -277 36 -1668 -1740 -798 1969 -1293 968 1338 296 462 -2133 816 1621 -1943 1690 -1709 -401 806 677 1679 1835 -284 1713 1018 -1115 -2020 -713 2119 -599 1278 -83 -1228 -1836 1938 -646 -336 358 -55 -1443 199 -685 1684 193 1176 -256 -1744 -1269 -1798 973 153 1403 495 863 -618 1301 15 -970 -1368 -754 -1132 -113 927 -309 738 459 2007 1037 1178 1573 -1279 -400 929 -1175 -390 1369 1574 -1361 -150 205 -1515 1825 -1828 -1409 -1765 -1465 1813 1905 300 2094 -1028 -1962 -1863 -405 1055 -710 377 -2089 773 -1751 -1020 -2125 -888 1051 1770 1388 -2 -662 -305 -1540 -1570 1255 840 -1521 -86 43 1947 -410 -288 -1268 1877 277 1536 -1542 789 1469 -2008 574 1126 1083 -1248 -2044 -909 -1613 545 -938 -56 956 -252 900 1238 552 -1601 625 1046 690 -668 1584 -1939 -1811 1917 218 622 -1827 -436 -895 732 -2062 94 485 -1138 1407 1366 -240 -1325 -144 -1758 2105 -1292 715 2130 -494 -1796 301 -648 1053 1542 1499 -1208 -2037 1834 -676 1812 -1694 1620 1896 -2093 688 -1897 -799 -1676 -874 -944 -997 -702 -111 18 -750 1309 -193 1096 1865 -672 -1774 289 -2112 -764 -1849 1952 -1916 -876 1367 -429 669 -1934 283 1908 1109 -1693 -1380 -1001 -1874 -2120 -1720 -47 -1360 -582 998 121 -6 -497 -258 -481 -1605 1478 1676 -2084 1750 -298 60 -1033 270 -1841 -1473 -760 -237 1427 -147 1010 1302 -789 730 -1450 852 1142 -1810 975 1778 -1543 621 -415 -2031 -160 1598 1016 172 2066 10 -433 -1330 -198 -2006 -1375 -133 -1351 458 -684 2075 -864 -423 1082 1490 851 1337 521 145 1949 1347 778 120 234 -332 1011 663 867 1026 -1410 1668 -194 -482 -1136 -10 -1993 -471 1168 -1839 -1652 903 -509 -1063 -703 -1129 -218 713 1045 1164 1188 1036 1993 1970 1955 -1955 -105 1254 1909

// ./visualizer/build/bin/visualizer