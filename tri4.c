/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jd-halle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 13:48:13 by jd-halle          #+#    #+#             */
/*   Updated: 2024/09/07 20:10:58 by jd-halle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	remonter_cible_i_dans_tab_b(long int *tab_b, long int i, int count_b)
{
	if (i > count_b / 2)
	{
		while (i < count_b)
		{
			rrb(tab_b, count_b);
			i++;
		}
	}
	else
	{
		while (i > 0)
		{
			rb(tab_b, count_b);
			i--;
		}
	}
	return (1);
}

int	find_min_index(long int *tabA, int countA)
{
	int	min_index;
	int	i;

	i = 1;
	min_index = 0;
	while (i < countA)
	{
		if (tabA[i] < tabA[min_index])
		{
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

int	find_insert_index(long int *tabA, int countA, long int target)
{
	int	closest_index;
	int	i;

	closest_index = -1;
	i = 0;
	while (i < countA)
	{
		if (tabA[i] > target)
		{
			if (closest_index == -1 || tabA[i] < tabA[closest_index])
				closest_index = i;
		}
		i++;
	}
	return (closest_index);
}

int	push_b_vers_cible_a_reduite(long int *tab_a, long int *tab_b, int count_a)
{
	int	index_cible;
	int	max_a;
	int	min_index;

	max_a = find_max_in_a(tab_a, count_a);
	if (tab_b[0] > max_a)
	{
		min_index = find_min_index(tab_a, count_a);
		remonter_cible_i_dans_tab_a(tab_a, min_index, count_a);
		return (1);
	}
	index_cible = find_insert_index(tab_a, count_a, tab_b[0]);
	if (index_cible == -1)
		index_cible = 0;
	remonter_cible_i_dans_tab_a(tab_a, index_cible, count_a);
	return (1);
}

int	find_cible_offset(long int *tab_a, long int target, int offset, int c_a)
{
	int	k;

	k = 0;
	while (k < c_a)
	{
		if (tab_a[k] == target + offset)
			return (k);
		k++;
	}
	return (-1);
}
