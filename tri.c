/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jd-halle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:38:30 by jd-halle          #+#    #+#             */
/*   Updated: 2024/08/16 17:38:51 by jd-halle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	tri(long int *tab_a, int count_a)
{
	long int	*tab_b;
	int			count_b;

	if (count_a == 2 || count_a == 3)
		tri_2_3(tab_a, count_a);
	count_b = 0;
	if (list_sorted_tab(tab_a, count_a, count_b) == 1)
		return (1);
	tab_b = malloc(sizeof(long int) * count_a);
	if (!tab_b)
		return (0);
	pb(tab_a, &count_a, tab_b, &count_b);
	{
		tri_big(tab_a, count_a, tab_b, count_b);
		return (free(tab_b), 1);
	}
	return (1);
}

int	tri_2_3(long int *tab_a, int count_a)
{
	if (count_a == 2)
	{
		if (tab_a[0] > tab_a[1])
			sa(tab_a);
	}
	if (count_a == 3)
	{
		if (tab_a[1] > tab_a[2] && tab_a[2] > tab_a[0])
		{
			sa(tab_a);
			ra(tab_a, count_a);
		}
		if (tab_a[2] > tab_a[0] && tab_a[0] > tab_a[1])
			sa(tab_a);
		if (tab_a[1] > tab_a[0] && tab_a[0] > tab_a[2])
			rra(tab_a, count_a);
		if (tab_a[0] > tab_a[2] && tab_a[2] > tab_a[1])
			ra(tab_a, count_a);
		if (tab_a[0] > tab_a[1] && tab_a[1] > tab_a[2])
		{
			sa(tab_a);
			rra(tab_a, count_a);
		}
	}
	return (1);
}

int	tri_big(long int *tab_a, int count_a, long int *tab_b, int count_b)
{
	int	x;
	int	y;

	pb(tab_a, &count_a, tab_b, &count_b);
	x = count_a;
	y = count_b;
	while (x > 3)
	{
		find_and_push_b(tab_a, x, tab_b, y);
		x--;
		y++;
	}
	tri_2_3(tab_a, x);
	while (y > 0)
	{
		push_b_vers_cible_a(tab_a, tab_b, x, y);
		pa(tab_a, x, tab_b, y);
		y--;
		x++;
	}
	ordonner_liste(tab_a, x);
	return (1);
}

int	find_and_push_b(long int *tab_a, int count_a, long int *tab_b, int count_b)
{
	int	best_i_a;
	int	best_i_b;

	best_i_a = find_best_move_a(tab_a, count_a, tab_b, count_b);
	best_i_b = find_best_move_b(tab_a, tab_b, count_b, best_i_a);
	remonter_cible_i_dans_tab_a(tab_a, best_i_a, count_a);
	remonter_cible_i_dans_tab_b(tab_b, best_i_b, count_b);
	pb(tab_a, &count_a, tab_b, &count_b);
	return (1);
}

int	closest_i_b(long int *tab_b, int count_b, long int value)
{
	int	j;
	int	closest_index;

	closest_index = -1;
	j = 0;
	while (j < count_b)
	{
		if (tab_b[j] < value && (closest_index == -1
				|| tab_b[j] > tab_b[closest_index]))
			closest_index = j;
		j++;
	}
	return (closest_index);
}
