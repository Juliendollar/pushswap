/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jd-halle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 02:11:36 by jd-halle          #+#    #+#             */
/*   Updated: 2024/08/16 02:11:42 by jd-halle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(long int *tabA)
{
	int temp;

	temp = tabA[0];
	tabA[0] = tabA[1];
	tabA[1] = temp;
	ft_printf("sa\n");
}
void sb(long int *tabB)
{
	int temp;

	temp = tabB[0];
	tabB[0] = tabB[1];
	tabB[1] = temp;
	ft_printf("sb\n");
}
void ss(long int *tabA, long int *tabB)
{
	int tempA;
	int tempB;

	tempA = tabA[0];
	tabA[0] = tabA[1];
	tabA[1] = tempA;
	tempB = tabB[0];
	tabB[0] = tabB[1];
	tabB[1] = tempB;
	ft_printf("ss\n");
}

void pb(long int *tabA, int *countA, long int *tabB, int *countB)
{
	int i;
	int j;

	i = 0;
	j = *countB;
	while (j)
	{
		tabB[j] = tabB[j - 1];	
		j--;
	}
	tabB[0] = tabA[0];
	while (i < *countA -1)
	{
		tabA[i] = tabA[i + 1];
		i++;
	}
	(*countA)--;
	(*countB)++;
	ft_printf("pb\n");
}

/*void pa(long int *tabA, int *countA, long int *tabB, int *countB)
{
	int i;
	int j;

	i = 0;
	j = *countA;
	while (j)
	{
		tabA[j] = tabA[j - 1];
		j--;
	}
	tabA[0] = tabB[0];
	while (i < *countB - 1)
	{
		tabB[i] = tabB[i +1];
		i++;
	}
	(*countA)++;
	(*countB)--;
	ft_printf("pa\n");
}*/

void pa(long int *tabA, int countA, long int *tabB, int countB)
{
	int i;
	int j;

	i = 0;
	j = countA;
	while (j)
	{
		tabA[j] = tabA[j - 1];
		j--;
	}
	tabA[0] = tabB[0];
	while (i < countB - 1)
	{
		tabB[i] = tabB[i +1];
		i++;
	}
	ft_printf("pa\n");
}
