/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jd-halle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 02:12:01 by jd-halle          #+#    #+#             */
/*   Updated: 2024/08/16 02:12:05 by jd-halle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rra(long int *tabA, int countA)
{
	int i;
	int last_element;

	i = countA -1;
	last_element = tabA[countA -1];
	while (i > 0)
	{
		tabA[i] = tabA[i - 1];
		i--;
	}
	tabA[0] = last_element;
	ft_printf("rra\n");
}

void rrb(long int *tabB, int countB)
{
	int i;
	int last_element;

	i = countB - 1;
	last_element = tabB[countB -1];
	while (i > 0)
	{
		tabB[i] = tabB[i -1];
		i--;
	}
	tabB[0] = last_element;
	ft_printf("rrb\n");
}

void rrr(long int *tabA, int countA, long int *tabB, int countB)
{
	int i;
	int last_elementA;
	int j;
	int last_elementB;

	i = countA -1;
	last_elementA = tabA[countA - 1];
	while (i > 0)
	{
		tabA[i] = tabA[i - 1];
		i--;
	}
	tabA[0] = last_elementA;
	j = countB - 1;
	last_elementB = tabB[countB - 1];
	while (j > 0)
	{
		tabB[j] = tabB[j -1];
		j--;
	}
	tabB[0] = last_elementB;
	ft_printf("rrr");
}
