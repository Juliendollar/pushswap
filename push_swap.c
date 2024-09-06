/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jd-halle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 23:17:52 by jd-halle          #+#    #+#             */
/*   Updated: 2024/07/21 00:51:43 by jd-halle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int check_arg(int argc, char **argv)
{
	long int	countA;
	long int	*tabA;
	char **tab;

	if (validate_arg(argv) == -1)
		return (-1);
	tabA = allocate_and_fill_tab(argv, argc, &countA, &tab);
	if (!tabA)
	{
		if (argc == 2)
			free_tab(tab);
		return (-1);
	}
	if (check_dup_limit_simplify_num(tabA, countA) == -1)
	{
		free(tabA);
		if (argc == 2)
			free_tab(tab);
		return (-1);
	}
	tri(tabA, countA);
	free(tabA);
	if (argc == 2)
		free_tab(tab);
	return (1);
}



void ordonner_liste(long int *tabA, int countA)
{                                                        //une fois la stack A triee, on fait ra ou rra pour avoir le 0 en haut
	int i;

	i = 0;
	while (i < countA && tabA[i] != 0)
		i++;
	if (i == countA)
		return;
	if (i < countA / 2)
	{
		while (i > 0)
		{
			ra(tabA, countA);
			i--;
		}
	}
	else
		while(i < countA)
		{
			rra(tabA, countA);
			i++;
		}
}

int list_sorted_tab(long int *tabA, int countA, int countB)
{                                                         //verifier si la stack A est triee
	int i;

	(void)countB;
	i = 0;
	while (i < countA -1)
	{
		if(tabA[i] < tabA[i + 1])
			i++;
		else
			return (-1);
	}
	return (1);
}

int main(int argc, char **argv)
{
	(void)argv;
	
	if (argc > 1)
    {
        if (check_arg(argc, argv) == -1)
            ft_printf("ERROR\n");
    }
}

/*void rra(long int *tabA, int countA)
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
}*/
