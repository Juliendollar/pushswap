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

int	median(long int *tabA, long int i, int countA)
{                                                                //on fait remonter la cible en haut de la stackA
	(void)tabA;                                                  // soit par ra soit par rra
	if (i > countA / 2)
	{
		while (i < countA)
		{
			rra(tabA, countA);
			i++;
		}
	}
	else
	{
		while (i > 0)
		{
			ra(tabA, countA);
			i--;
		}
	}
	return (1);
}

int push_cible_A(long int *tabA, long int *tabB, int countA)
{                                                           //on fait remonter la cible de tabB[0] en haut de la stack A
	int i;                                                  //puis on pa
	int cible_trouvee;
	int index_min;
	
	i = 0;
	cible_trouvee = 0;
	index_min = 0;
	while (i < countA)
	{
		if (tabB[0] + 1 == tabA[i])
		{
			median(tabA, i, countA);
			cible_trouvee = 1;
			break;
		}
		if (tabA[i] < tabA[index_min])
			index_min = i;
		i++;
	}
	i = 0;
	if (!cible_trouvee)          
		{
			while (i < countA)
			{
				if (tabB[0] + 2 == tabA[i])            // si tabB[0] ne trouve pas le tabA[i] == tabB[0] +1 on cherche le tabA[i] == tabB[0] + 2
				{
					median(tabA, i, countA);
					cible_trouvee = 1;
					break;
				}
				i++;
			}
			if (!cible_trouvee)
				median(tabA, index_min, countA);             // si tab[0] est plus grand que tous les elements de tabA, on le met sur la plus petite valeur
		}
	return (1);
}

void ordonner_liste(long int *tabA, int countA)
{                                                        //une fois la stack A triee, on fait ra ou rra pour avoir le 0 en haut
	int i;
	
	i = 0;
	while (tabA[i] != 0)
		i++;
	median(tabA, i, countA);
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
	ft_printf("t");
}
