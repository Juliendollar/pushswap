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

int tri(long int *tab, int countA)
{
	if (countA == 2 || countA == 3)
		tri_2_3(tab, countA);
	else if (countA > 3)
		tri_4_5(tab, countA);
	return (1);
}

int tri_2_3(long int *tabA, int countA)
{
    if (countA == 2)
    {
        if (tabA[0] > tabA[1])
		sa(tabA);
    }
	if (countA == 3)
    {
        if (tabA[1] > tabA[2] && tabA[2] > tabA[0])
	    {
	    	sa(tabA);
		    ra(tabA, countA);
	    }
	    if (tabA[2] > tabA[0] && tabA[0] > tabA[1])
			sa(tabA);
	    if (tabA[1] > tabA[0] && tabA[0] > tabA[2])
	    	rra(tabA, countA);
	    if (tabA[0] > tabA[2] && tabA[2] > tabA[1])
	    	ra(tabA, countA);
	    if (tabA[0] > tabA[1] && tabA[1] > tabA[2])
	    {
	    	sa(tabA);
	    	rra(tabA, countA);
	    }
    }
	return (1);
}

int tri_4_5(long int *tabA, int countA)
{
	long int *tabB;
	int countB;

	countB = 0;
	tabB = malloc(sizeof(long int) * countA);
	if (!tabB)
		return (0);
	if (list_sorted_tab(tabA, countA, countB) == 1)
	{
		free(tabB);
		return(1);
	}
	pb(tabA, &countA, tabB, &countB);
	if (list_sorted_tab(tabA, countA, countB) == 1)
	{
		push_cible_A(tabA, tabB, countA);
		pa(tabA, &countA, tabB, &countB);
		ordonner_liste(tabA, countA);
		free(tabB);
		return (1);
	}
	if (countA == 3)
	{
		tri_2_3(tabA, countA);
		push_cible_A(tabA, tabB, countA);
		pa(tabA, &countA, tabB, &countB);
		ordonner_liste(tabA, countA);
	}
	else if (countA == 4)
	{
		pb(tabA, &countA, tabB, &countB);
		tri_2_3(tabA, countA);
		push_cible_A(tabA, tabB, countA);
		pa(tabA, &countA, tabB, &countB);
		push_cible_A(tabA, tabB, countA);
		pa(tabA, &countA, tabB, &countB);
		ordonner_liste(tabA, countA);
	}
	/*for (int j = 0; j < countA ; j++)
			ft_printf("tabA[%d] = %d\n", j, tabA[j]);*/
	free (tabB);
	return (1);
}

/*void traiter_tabB(long int *tabA, int *countA, long int *tabB, int *countB)
{
	push_cible_A(tabA, tabB, countA, countB);
	for (int h = 0; h < *countA ; h++)
		{
			ft_printf("tabA[%d] apres le pb = %d\n", h, tabA[h]);
		}
	ordonner_liste(tabA, *countA);
}

void tri_si_non_triee(long int *tabA, int *countA, long int *tabB, int *countB)
{
	for (int x = 0; x < *countA ; x++)
	{
		ft_printf("tabA[%d] = %d\n", x, tabA[x]);
	}
	int test = *countB;
	if (*countA == 3)
		tri_2_3(tabA, *countA);
	else if (*countA == 4)
	{
		pb(tabA, countA, tabB, countB);
		test = *countB;
		tri_2_3(tabA, *countA);
	}
	ft_printf("test ; %d\n", test);
	ft_printf("*countB = %d\n", *countB);
	while (test > 0)
	{
		traiter_tabB(tabA, countA, tabB, countB);
		test--;
	}
	for (int h = 0; h < *countA ; h++)
		{
			ft_printf("tabA[%d] apres le pb = %d\n", h, tabA[h]);
		}
}

int tri_4_5(long int *tabA, int countA)
{
	long int *tabB;
    int countB;
	
	for (int x = 0; x < countA ; x++)
	{
		ft_printf("tabA[%d] = %d\n", x, tabA[x]);
	}
	countB = 0;
    tabB = malloc(sizeof(long int) * countA);
	if (!tabB)
		return (0);
	if (list_sorted_tab(tabA, countA, countB) == 1)
	{
		free(tabB);
		return (1);
	}
	pb(tabA, &countA, tabB, &countB);
	if (list_sorted_tab(tabA, countA, countB) == 1)
	{
		traiter_tabB(tabA, &countA, tabB, &countB);
		free(tabB);
		return (1);
	}
	tri_si_non_triee(tabA, &countA, tabB, &countB);
	free(tabB);
	return (1);
}*/

