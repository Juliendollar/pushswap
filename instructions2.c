/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jd-halle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 02:11:48 by jd-halle          #+#    #+#             */
/*   Updated: 2024/08/16 02:11:55 by jd-halle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra(long int *tabA, int countA)
{
	int i;
	int first_element;

	first_element = tabA[0];
	i = 0;
	while (i < countA -1)
	{
		tabA[i] = tabA[i + 1];
		i++;
	}
	tabA[countA - 1] = first_element;
	ft_printf("ra\n");
}

void rb(long int *tabB, int countB)
{
	int i;
	int first_element;

	first_element = tabB[0];
	i = 0;
	while (i < countB -1)
	{
		tabB[i] = tabB[i +1];
		i++;
	}
	tabB[countB - 1] = first_element;
	ft_printf("rb");
}

void rr(long int *tabA, int countA, long int *tabB, int countB)
{
	int i;
	int first_elementA;
	int j;
	int first_elementB;

	first_elementA = tabA[0];
	i = 0;
	while (i < countA -1)
	{
		tabA[i] = tabA[i + 1];
		i++;
	}
	tabA[countA - 1] = first_elementA;
	first_elementB = tabB[0];
	j = 0;
	while (j < countB -1)
	{
		tabB[j] = tabB[j +1];
		j++;
	}
	tabB[countB - 1] = first_elementB;
	ft_printf("rr");
}