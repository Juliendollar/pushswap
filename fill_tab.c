/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jd-halle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:57:30 by jd-halle          #+#    #+#             */
/*   Updated: 2024/08/16 16:57:31 by jd-halle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	*malloc_fill_tab(char **argv, int ac, long int *countA, char ***tab)
{
	long int	*tab_a;
	long int	i;

	if (ac == 2)
	{
		*countA = ft_count_number(argv[1], ' ');
		*tab = ft_split(argv[1], ' ');
	}
	else
	{
		*countA = ac - 1;
		*tab = &argv[1];
	}
	tab_a = malloc(sizeof(long int) * (*countA));
	if (!tab_a)
		return (0);
	i = 0;
	while (i < *countA)
	{
		tab_a[i] = ft_atol((*tab)[i]);
		i++;
	}
	return (tab_a);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
