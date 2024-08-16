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

long int *allocate_and_fill_tab(char **argv, int argc, long int *countA, char ***tab)
{
	long int i;
    long int *tabA;
	
    if (argc == 2)
    {
        *countA = ft_count_number(argv[1], ' ');
        *tab = ft_split(argv[1], ' ');
    }
    else
    {
        *countA = argc - 1;
        *tab = &argv[1];
    }
	tabA = malloc(sizeof(long int) * (*countA));
	if (!tabA)
		return (0);
	i = 0;
	while (i < *countA)
	{
		tabA[i] = ft_atol((*tab)[i]);
		i++;
	}
	return (tabA);
}

void free_tab(char **tab)  
{
	int i;
	i = 0;

	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

