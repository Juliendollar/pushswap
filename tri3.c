/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jd-halle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 13:47:28 by jd-halle          #+#    #+#             */
/*   Updated: 2024/09/07 20:04:35 by jd-halle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_index_in_b(long int *tab_b, int count_b)
{
	int	max_value;
	int	i;
	int	max_index_in_b;

	max_value = tab_b[0];
	max_index_in_b = 0;
	i = 1;
	while (i < count_b)
	{
		if (tab_b[i] > max_value)
		{
			max_value = tab_b[i];
			max_index_in_b = i;
		}
		i++;
	}
	return (max_index_in_b);
}

int	find_min_in_b(long int *tab_b, int count_b)
{
	int	min_value_in_b;
	int	i;

	i = 1;
	min_value_in_b = tab_b[0];
	while (i < count_b)
	{
		if (tab_b[i] < min_value_in_b)
			min_value_in_b = tab_b[i];
		i++;
	}
	return (min_value_in_b);
}

int	find_max_in_a(long int *tab_a, int count_a)
{
	int	max_value;
	int	i;

	max_value = tab_a[0];
	i = 1;
	while (i < count_a)
	{
		if (tab_a[i] > max_value)
			max_value = tab_a[i];
		i++;
	}
	return (max_value);
}

int	find_min_index_in_a(long int *tab_a, int count_a)
{
	int	min_value;
	int	i;
	int	min_index_in_a;

	min_value = tab_a[0];
	min_index_in_a = 0;
	i = 1;
	while (i < count_a)
	{
		if (tab_a[i] < min_value)
		{
			min_value = tab_a[i];
			min_index_in_a = i;
		}
		i++;
	}
	return (min_index_in_a);
}

int	remonter_cible_i_dans_tab_a(long int *tab_a, long int i, int count_a)
{
	if (i > count_a / 2)
	{
		while (i < count_a)
		{
			rra(tab_a, count_a);
			i++;
		}
	}
	else
	{
		while (i > 0)
		{
			ra(tab_a, count_a);
			i--;
		}
	}
	return (1);
}
