/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jd-halle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 13:45:08 by jd-halle          #+#    #+#             */
/*   Updated: 2024/09/06 17:31:50 by jd-halle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_moves_in_b(long int *tab_b, int count_b, long int value)
{
	int	max_b;
	int	min_b;
	int	move_in_b;

	max_b = find_max_in_b(tab_b, count_b);
	min_b = find_min_in_b(tab_b, count_b);
	if (value > max_b || value < min_b)
		move_in_b = calcul_move(count_b, find_max_index_in_b(tab_b, count_b));
	else
		move_in_b = calcul_move(count_b, closest_i_b(tab_b, count_b, value));
	return (move_in_b);
}

int	find_best_move_a(long int *tab_a, int c_a, long int *tab_b, int c_b)
{
	t_moves		moves;
	int			i;
	int			best_i_a;
	int			min_moves;
	int			current_moves;

	i = 0;
	best_i_a = 0;
	min_moves = INT_MAX;
	while (i < c_a)
	{
		moves.moves_in_a = calcul_move(c_a, i);
		moves.moves_in_b = get_moves_in_b(tab_b, c_b, tab_a[i]);
		current_moves = moves.moves_in_a + moves.moves_in_b;
		if (current_moves < min_moves)
		{
			min_moves = current_moves;
			best_i_a = i;
		}
		if (min_moves == 0)
			break ;
		i++;
	}
	return (best_i_a);
}

int	find_best_move_b(long int *tab_a, long int *tab_b, int count_b, int i)
{
	int	j;
	int	best_index_in_b;
	int	closest_index;
	int	max_b;
	int	min_b;

	max_b = find_max_in_b(tab_b, count_b);
	min_b = find_min_in_b(tab_b, count_b);
	best_index_in_b = 0;
	closest_index = -1;
	j = 0;
	if (tab_a[i] > max_b || tab_a[i] < min_b)
		best_index_in_b = find_max_index_in_b(tab_b, count_b);
	else
	{
		while (j < count_b)
		{
			if (tab_b[j] < tab_a[i] && (closest_index == -1
					|| tab_b[j] > tab_b[closest_index]))
				closest_index = j;
			j++;
		}
		best_index_in_b = closest_index;
	}
	return (best_index_in_b);
}

int	calcul_move(int count, int index)
{
	if (index <= count / 2)
		return (index);
	else
		return (count - index);
}

int	find_max_in_b(long int *tab_b, int count_b)
{
	int	max_value;
	int	i;

	max_value = tab_b[0];
	i = 1;
	while (i < count_b)
	{
		if (tab_b[i] > max_value)
			max_value = tab_b[i];
		i++;
	}
	return (max_value);
}
