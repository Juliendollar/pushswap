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

int	tri(long int *tabA, int countA)
{
	long int	*tabB;
	int			countB;

	if (countA == 2 || countA == 3)
		tri_2_3(tabA, countA);
	countB = 0;
	if (list_sorted_tab(tabA, countA, countB) == 1)
		return (1);
	tabB = malloc(sizeof(long int) * countA);
	if (!tabB)
		return (0);
	pb(tabA, &countA, tabB, &countB);
	{
		tri_big(tabA, countA, tabB, countB);
		return (free(tabB), 1);
	}
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

int tri_big(long int *tabA, int countA, long int *tabB, int countB)
{	
	int x;
	int y;

	pb(tabA, &countA, tabB, &countB);
	x = countA;
	y = countB;
	while  (x > 3)
	{
		find_and_push_b(tabA, x, tabB, y);
		x--;
		y++;
	}
	tri_2_3(tabA, x);
	while (y > 0)
	{
		push_b_vers_cible_a(tabA, tabB, x, y);
		pa(tabA, x, tabB, y);
		y--;
		x++;
	}
	ordonner_liste(tabA, x);
	return (1);
}
int find_and_push_b(long int *tabA, int countA, long int *tabB, int countB)
{
    int best_index_in_a;
	int best_index_in_b;

	best_index_in_a = find_optimal_move_return_best_index_in_a(tabA, countA, tabB, countB);
    best_index_in_b = return_best_index_in_b(tabA, countA,tabB, countB, best_index_in_a);
	remonter_en_haut_de_tabA_la_cible_i(tabA, best_index_in_a, countA);
	remonter_en_haut_de_tabB_la_cible_i(tabB, best_index_in_b, countB);
   	pb(tabA, &countA, tabB, &countB);
    return (1);
}

int find_optimal_move_return_best_index_in_a(long int *tabA, int countA, long int *tabB, int countB)
{
    int i;
	int j;
	int min_moves = INT_MAX;
	int best_index_in_a = 0;
	int current_moves;
	int count_moves_in_A;
	int count_moves_in_B;
	int max_b = find_max_in_b(tabB, countB);
	int min_b = find_min_in_b(tabB, countB);
	int max_index_in_b;
	int closest_index;
	
	i = 0;
	while (i < countA)
	{
		count_moves_in_A = calculate_moves(countA, i);
		if (tabA[i] > max_b || tabA[i] < min_b)
		{
			max_index_in_b = find_max_index_in_b(tabB, countB);
			count_moves_in_B = calculate_moves(countB, max_index_in_b);
		}
		else
		{
			j = 0;
			closest_index = -1;
			while (j < countB)
			{
				if (tabB[j] < tabA[i] && (closest_index == -1 || tabB[j] > tabB[closest_index]))
					closest_index = j;
				j++;
			}
			count_moves_in_B = calculate_moves(countB, closest_index);
		}
		current_moves = count_moves_in_A + count_moves_in_B;
		if (current_moves < min_moves)
		{
			min_moves = current_moves;
            best_index_in_a = i;
		}
		if (min_moves == 0)
			break;
		i++;
	}
	return (best_index_in_a);
}
int return_best_index_in_b(long int *tabA, int countA, long int *tabB, int countB, int i)
{
	int j;
	int best_index_in_b;
	int closest_index;
	int max_b = find_max_in_b(tabB, countB);
	int min_b = find_min_in_b(tabB, countB);
	(void) countA;


	best_index_in_b = 0;
	closest_index = -1;
	j = 0;

	if (tabA[i] > max_b || tabA[i] < min_b)
		best_index_in_b = find_max_index_in_b(tabB, countB);
	else
	{
	while (j < countB)
	{
		if (tabB[j] < tabA[i] && (closest_index == -1 || tabB[j] > tabB[closest_index]))
			closest_index = j;
		j++;
	}
	best_index_in_b = closest_index;
	}
	return (best_index_in_b);
}

int calculate_moves(int count, int index)
{
	if (index <= count / 2)
        return index;
    else
        return count - index;
}

int find_max_in_b(long int *tabB,  int countB)
{
	int max_value;
	int i;
	max_value = tabB[0];
	i = 1;
	while (i < countB)
	{
		if (tabB[i] > max_value)
			max_value = tabB[i];
		i++;
	}
	return (max_value);
}

int find_max_index_in_b(long int *tabB,  int countB)
{
	int max_value;
	int i;
	max_value = tabB[0];
	int max_index_in_b;
	max_index_in_b = 0;
	i = 1;
	while (i < countB)
	{
		if (tabB[i] > max_value)
		{
			max_value = tabB[i];
			max_index_in_b = i;
		}
		i++;
	}
	return (max_index_in_b);
}

int find_min_in_b(long int *tabB, int countB)
{
	int min_value_in_b;
	min_value_in_b = tabB[0];
	int i = 1;
	while (i < countB)
	{
		if (tabB[i] < min_value_in_b)
			min_value_in_b = tabB[i];
		i++;
	}
	return (min_value_in_b);
}



int find_min_index_in_b(long int *tabB, int countB)
{
	int min_value;
	min_value = tabB[0];
	int i = 1;
	int min_index_in_b;
	min_index_in_b = 0;
	while (i < countB)
	{
		if (tabB[i] < min_value)
		{
			min_value = tabB[i];
			min_index_in_b = i;
		}
		i++;
	}
	return (min_index_in_b);
}
int find_max_in_a(long int *tabA,  int countA)
{
	int max_value;
	int i;
	max_value = tabA[0];
	i = 1;
	while (i < countA)
	{
		if (tabA[i] > max_value)
			max_value = tabA[i];
		i++;
	}
	return (max_value);
}
int find_min_index_in_a(long int *tabA,  int countA)
{
	int min_value;
	int i;
	min_value = tabA[0];
	int min_index_in_a;
	min_index_in_a = 0;
	i = 1;
	while (i < countA)
	{
		if (tabA[i] < min_value)
		{
			min_value = tabA[i];
			min_index_in_a = i;
		}
		i++;
	}
	return (min_index_in_a);
}

int	remonter_en_haut_de_tabA_la_cible_i(long int *tabA, long int i, int countA)
{                                                         //on fait remonter la cible en haut de la stackAAAAAAAAAAAAAAAAAAAAAA      
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
int	remonter_en_haut_de_tabB_la_cible_i(long int *tabB, long int i, int countB)
{    
	
	if (i > countB / 2)
	{
		while (i < countB)
		{
			rrb(tabB, countB);
			i++;
		}
	}
	else
	{
		while (i > 0)
		{
			rb(tabB, countB);
			i--;
		}
	}
	return (1);
}

int	push_b_vers_cible_a_reduite(long int *tabA, long int *tabB, int countA, int countB)
{
	int cible_trouvee;
	int index_min;
	int i;
	int max_a;
	max_a = find_max_in_a(tabA, countA);
	long int closest_value;
	int index_cible;
	(void) countB;

	closest_value = LONG_MAX;
	cible_trouvee = 0;
	index_min = 0;
	if (tabB[0] > max_a)
		{
			cible_trouvee = 3;
		}
	else 
	{
		i = 0;
		while (i < countA)
		{
			if (tabA[i] > tabB[0] && tabA[i] < closest_value)
			{
				closest_value = tabA[i];
				index_cible = i;
				cible_trouvee = 1;
			}
			if (tabA[i] < tabA[index_min])
			{
					index_min = i;
			}
			i++;
		}	
		if (cible_trouvee == 1)
		{
			remonter_en_haut_de_tabA_la_cible_i(tabA, index_cible, countA);
			return(1);
		}
	}
	return (cible_trouvee);
}

int push_b_vers_cible_a(long int *tabA, long int *tabB, int countA, int countB)  
{                                                         
	int i;                                                 
	int cible_trouvee;
	int index_min;
	int j;
	int k;
	(void) index_min;

	index_min = 0;
	cible_trouvee = push_b_vers_cible_a_reduite(tabA, tabB, countA, countB);
	if (!cible_trouvee)          
	{
		j = 2;
		while (j < countA)
		{
			i = 0;
			while (i < countB)
			{
				k = 0;
				while (k < countA)
				{
					if (tabB[i] + j == tabA[k])            // si tabB[0] ne trouve pas le tabA[i] == tabB[0] +1 on cherche le tabA[i] == tabB[0] + 2
					{
						remonter_en_haut_de_tabA_la_cible_i(tabA, k, countA);
						return (1);
					}
					k++;
				}
				i++;
			}
			j++;
		}
		remonter_en_haut_de_tabA_la_cible_i(tabA, index_min, countA);
	}
	else if (cible_trouvee == 3)
	{
		remonter_en_haut_de_tabA_la_cible_i(tabA, find_min_index_in_a(tabA, countA), countA);
	}
	return (1);
}


int	push_a_vers_cible_b_reduite(long int *tabB, long int *tabA, int countB)             //a --> b
{
	int cible_trouvee;
	int index_min;
	int i;

	cible_trouvee = 0;
	index_min = 0;
	i = 0;
	while (i < countB)
	{
		if (tabA[0] - 1 == tabB[i])
		{
			remonter_en_haut_de_tabB_la_cible_i(tabB, i, countB);
			cible_trouvee = 1;
			break;
		}
		if (tabB[i] < tabB[index_min])
			index_min = i;
		i++;
	}
	return (cible_trouvee);
}

int push_a_vers_cible_b(long int *tabA, long int *tabB, int countB)              //a -->b
{                                                           //
	int i;                                                  //
	int cible_trouvee;
	int index_min;
	int j;
	j = 2;

	index_min = 0;
	cible_trouvee = push_a_vers_cible_b_reduite(tabB, tabA, countB);
	if (!cible_trouvee)          
		{
			while (j < countB)
			{
				i = 0;
				while (i < countB)
				{
					if (tabA[0] - j == tabB[i])            // si tabB[0] ne trouve pas le tabA[i] == tabB[0] +1 on cherche le tabA[i] == tabB[0] + 2
					{
						remonter_en_haut_de_tabB_la_cible_i(tabB, i, countB);
						cible_trouvee = 1;
						break;
					}
					if (tabB[i] < tabB[index_min])
						index_min = i;
					i++;
				}
				if (cible_trouvee)
					break;
				j++;
			}
			if (!cible_trouvee)
				remonter_en_haut_de_tabB_la_cible_i(tabB, index_min, countB);             // si tab[0] est plus grand que tous les elements de tabA, on le met sur la plus petite valeur
		}
	return (1);
}




































/*// Fonction pour calculer le coût de rotation pour amener un élément au sommet de tabA
int calculate_cost_a(int i, int countA)
{
    if (i <= countA / 2)
        return i;  // Nombre de rotations via `ra`
    else
        return countA - i;  // Nombre de rotations via `rra`
}
// Fonction pour calculer le coût de rotation pour amener un élément au sommet de tabA}
int calculate_cost_b(int target_position, int countB)
{
    if (target_position <= countB / 2)
        return target_position;  // Nombre de rotations via `rb`
    else
        return countB - target_position;  // Nombre de rotations via `rrb`
}

// Fonction pour calculer le coût de rotation pour positionner un élément correctement dans tabB
int find_target_position(long int value, long int *tabB, int countB)
{
    int i;
    
	i = 0;
	if (countB == 0) {
        ft_printf("tabB is empty, returning 0\n");
        return 0;  // Cas où tabB est vide
    }
    // Trouve la position dans tabB où value doit être inséré
    while (i < countB)
	{
		printf("Comparing value %ld with tabB[%d] = %ld\n", value, i, tabB[i]);
        if (value < tabB[i])
            return i;
		i++;
    }
    ft_printf("Value %ld is the largest, returning %d\n", value, countB);
    return countB;  // Si value est le plus grand, il va à la fin
}
  

// Fonction principale pour trouver le meilleur élément à pousser sur tabB
int find_a_to_push_to_b(long int *tabA, int countA, long int *tabB, int countB)
{
    int i;
    int min_cost = INT_MAX;
    int best_index = -1;
    int cost_a, cost_b, total_cost;
    int target_position;

	i = 0;
	while (i< countA)
	{
		ft_printf("countA %d\n", countA);
		ft_printf("int i %d\n", i);
        target_position = find_target_position(tabA[i], tabB, countB);           // Calcule la position cible dans tabB pour tabA[i]
		cost_a = calculate_cost_a(i, countA);                                    // Calcule le coût pour amener tabA[i] au sommet de tabA
        cost_b = calculate_cost_b(target_position, countB);						// Calcule le coût pour insérer tabA[i] dans tabB
        total_cost = cost_a + cost_b;												  // Coût total
        if (total_cost < min_cost)													// Si ce coût est le plus bas jusqu'à présent, on le garde
		{											
            min_cost = total_cost;
            best_index = i;
        }
		i++;
    }
    if (best_index != -1)
	{		
		ft_printf("dans le countA %d\n", countA);
		ft_printf("dans le int i %d\n", i);												// Si un meilleur élément a été trouvé, on le déplace au sommet de tabA et on l'envoie à tabB
        remonter_en_haut_de_la_pileA(tabA, best_index, countA); 
		ft_printf("pour le countA %d\n", countA);
		ft_printf("pour le int i %d\n", i); 									// Amène tabA[best_index] au sommet
        pb(tabA, &countA, tabB, &countB);  										// Pousse l'élément en haut de tabA vers tabB
    }
    return 1;
}*/


/*int	remonter_en_haut_de_la_pileAB(long int *tabB, long int i, int countB)
{     
	int count_cost;
	
	count_cost = 0;                                                           //on fait remonter la cible en haut de la stackB                                                 // soit par rb soit par rrb
	if (i > countA / 2)
	{
		while (i < countB)
		{
			rrb(tabB, countB);
			count_cost++;                // il faut une version de rra qui print pas (lui donner un param qui empeche de print sil est donne)
			i++;
		}
	}
	else
	{
		while (i > 0)
		{
			ra(tabB, countB);                       //  il faut une version de rra qui print pas (lui donner un param qui empeche de print sil est donne)
			count_cost++;
			i--;
		}
	}
	return (count_cost);
}
int	push_cible_a_reduite(long int *tabA, long int *tabB, int countA)
{
	int cible_trouvee;
	int index_min;
	int i;

	cible_trouvee = 0;
	index_min = 0;
	i = 0;
	while (i < countA)
	{
		if (tabB[0] + 1 == tabA[i])
		{
			remonter_en_haut_de_la_pileA(tabA, i, countA);
			cible_trouvee = 1;
			break;
		}
		if (tabA[i] < tabA[index_min])
			index_min = i;
		i++;
	}
	return (cible_trouvee);
}
int push_cible_A(long int *tabA, long int *tabB, int countA)
{                                                           //on fait remonter la cible de tabB[0] en haut de la stack A
	int i;                                                  //puis on pa
	int cible_trouvee;
	int index_min;

	index_min = 0;
	cible_trouvee = push_cible_a_reduite(tabA, tabB, countA);
	if (!cible_trouvee)          
		{
			while (i < countA)
			{
				if (tabB[0] + 2 == tabA[i])            // si tabB[0] ne trouve pas le tabA[i] == tabB[0] +1 on cherche le tabA[i] == tabB[0] + 2
				{
					remonter_en_haut_de_la_pileA(tabA, i, countA);
					cible_trouvee = 1;
					break;
				}
				if (tabA[i] < tabA[index_min])
					index_min = i;
				i++;
			}
			if (!cible_trouvee)
				remonter_en_haut_de_la_pileA(tabA, index_min, countA);             // si tab[0] est plus grand que tous les elements de tabA, on le met sur la plus petite valeur
		}
	return (1);
}*/

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

/*int	push_b_vers_cible_a_reduite(long int *tabA, long int *tabB, int countA)             //b --> a
{
	int cible_trouvee;
	int index_min;
	int i;

	cible_trouvee = 0;
	index_min = 0;
	i = 0;

	while (i < countA)
	{
		if (tabB[i] + 1 == tabA[i])
		{
			for (int o = 0; o < countA; o++)
			{
			printf("ici ordonner liste tabA[%d] = %ld\n", o, tabA[o]);
			}
			remonter_en_haut_de_tabA_la_cible_i(tabA, i, countA);
				cible_trouvee = 1;
				break;
		}
		if (tabB[i] < tabB[index_min])
			index_min = i;
		i++;
	}*/
	/*ft_printf("cible valeur : %d\n", cible_trouvee);
	return (cible_trouvee);
}
int push_b_vers_cible_a(long int *tabA, long int *tabB, int countA)              //b -->a
{                                                           //on fait remonter la cible de tabB[0] en haut de la stack A
	int i;                                                  //puis on pa
	int cible_trouvee;
	int index_min;
	int j;
	j = 2;

	index_min = 0;
	cible_trouvee = push_b_vers_cible_a_reduite(tabA, tabB, countA);
	if (!cible_trouvee)          
		{
			while (j < countA)
			{
				i = 0;
				while (i < countA)
				{
					if (tabB[i] + j == tabA[i])            // si tabB[0] ne trouve pas le tabA[i] == tabB[0] +1 on cherche le tabA[i] == tabB[0] + 2
					{
						remonter_en_haut_de_tabA_la_cible_i(tabA, i, countA);
						cible_trouvee = 1;
						break;
					}
					if (tabA[i] < tabA[index_min])
						index_min = i;
					i++;
				}
				if(cible_trouvee)
					break;
				j++;
			}
			if (!cible_trouvee)
				remonter_en_haut_de_tabA_la_cible_i(tabA, index_min, countA);             // si tab[0] est plus grand que tous les elements de tabA, on le met sur la plus petite valeur
		}
	return (1);
}*/