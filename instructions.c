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

void	sa(long int *tab_a)
{
	int	temp;

	temp = tab_a[0];
	tab_a[0] = tab_a[1];
	tab_a[1] = temp;
	ft_printf("sa\n");
}

void	sb(long int *tab_b)
{
	int	temp;

	temp = tab_b[0];
	tab_b[0] = tab_b[1];
	tab_b[1] = temp;
	ft_printf("sb\n");
}

void	ss(long int *tab_a, long int *tab_b)
{
	int	temp_a;
	int	temp_b;

	temp_a = tab_a[0];
	tab_a[0] = tab_a[1];
	tab_a[1] = temp_a;
	temp_b = tab_b[0];
	tab_b[0] = tab_b[1];
	tab_b[1] = temp_b;
	ft_printf("ss\n");
}

void	pb(long int *tab_a, int *countA, long int *tab_b, int *countB)
{
	int	i;
	int	j;

	i = 0;
	j = *countB;
	while (j)
	{
		tab_b[j] = tab_b[j - 1];
		j--;
	}
	tab_b[0] = tab_a[0];
	while (i < *countA -1)
	{
		tab_a[i] = tab_a[i + 1];
		i++;
	}
	(*countA)--;
	(*countB)++;
	ft_printf("pb\n");
}

void	pa(long int *tab_a, int countA, long int *tab_b, int countB)
{
	int	i;
	int	j;

	i = 0;
	j = countA;
	while (j)
	{
		tab_a[j] = tab_a[j - 1];
		j--;
	}
	tab_a[0] = tab_b[0];
	while (i < countB - 1)
	{
		tab_b[i] = tab_b[i +1];
		i++;
	}
	ft_printf("pa\n");
}
