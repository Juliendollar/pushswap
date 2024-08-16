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
	if (check_duplicate_number_and_max_min_int(tabA, countA) == -1)
	{
		free(tabA);
		if (argc == 2)
			free_tab(tab);
		return (-1);
	}
	list_simplifier_valeurs(tabA, countA);
	tri(tabA, countA);
	free(tabA);
	if (argc == 2)
		free_tab(tab);
	return (1);
}

int tri_2(long int *tab)
{
	if (tab[0] > tab[1])
		sa(tab);
	return (1);
}

int tri_3(long int *tabA, int countA)
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
		tri_3(tabA, countA);
		push_cible_A(tabA, tabB, countA);
		pa(tabA, &countA, tabB, &countB);
		ordonner_liste(tabA, countA);
	}
	else if (countA == 4)
	{
		pb(tabA, &countA, tabB, &countB);
		tri_3(tabA, countA);
		push_cible_A(tabA, tabB, countA);
		pa(tabA, &countA, tabB, &countB);
		push_cible_A(tabA, tabB, countA);
		pa(tabA, &countA, tabB, &countB);
		ordonner_liste(tabA, countA);
	}
	free (tabB);
	return (1);
}
void ordonner_liste(long int *tabA, int countA)
{
	int i;
	
	i = 0;
	while (tabA[i] != 0)
	{
		i++;
	}
	median(tabA, i, countA);
}

int push_cible_A(long int *tabA, long int *tabB, int countA)
{
	int i;
	int cible_trouvee;

	cible_trouvee = 0;
	i = 0;
	while (i < countA)
	{
		if (tabB[0] + 1 == tabA[i])
		{
			median(tabA, i, countA);
			cible_trouvee = 1;
			break;
		}
		i++;
	}
	if (!cible_trouvee)
	{
		while (i < countA)
		{
			if (tabB[0] == 0)
				median(tabA, i, countA);
			i++;
		}
	}
	return (1);
}

int median(long int *tabA, long int i, int countA)
{                                                                //on fait remonter la cible en haut de la stackA
	(void)tabA;
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

int tri(long int *tab, int countA)
{
	if (countA == 2)
		tri_2(tab);
	else if (countA == 3)
		tri_3(tab, countA);
	else if (countA > 3)
		tri_4_5(tab, countA);
	return (1);
}
int list_sorted_tab(long int *tabA, int countA, int countB)
{
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
void list_simplifier_valeurs(int long *tabA, int countA)
{
	int i;
	int j;

	long int tab_temp[countA];
	i = -1;
	while (++i < countA)
		tab_temp[i] = tabA[i];
	sort_tab(tab_temp, countA);
	i = 0;
	while (i  < countA)
	{
		j = 0;
		while (j < countA)
		{
			if (tabA[i] == tab_temp[j])
			{
				tabA[i] = j;
				break;
			}
			j++;
		}
		i++;
	}
}

void sort_tab(long int *tab_temp, int countA)
{
	int i;
	int j;
	long int temp;

	i = 0;
	while (i < countA -1)
	{
		j = 0;
		while (j < countA - 1)
		{
			if (tab_temp[j] > tab_temp[j + 1])
			{
				temp = tab_temp[j];
				tab_temp[j] = tab_temp[j + 1];
				tab_temp[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
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
