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

int	check_only_digit_and_minus_valid(char *str)
{
	int	i;
	i = 0;
	while (str[i])
	{
		if (!(ft_isdigit(str[i]) || str[i] == '-' || str[i] == ' '))
			return (-1);
		else if (str[0] == '-' && !(ft_isdigit(str[1])))
			return (-1);
		else if (str[i] == ' ' && str[i + 1] == '-' && !(ft_isdigit(str[i + 2])))
			return (-1);
		else if (i > 0)
			if (ft_isdigit(str[i]) && str[i + 1] == '-')     //si on a un chiffre et juste apres le chiffre un - sans espace
				return (-1);
		i++;
	}
	return (1);

}
long int check_duplicate_number_and_max_min_int(long int *tabA, long int countA)
{
	int	i;
	int j;

	i = 0;
	while (i < countA)
	{
		if (tabA[i] == -0)
			tabA[i] = 0;
		i++;	
	}
	i = 0;
	while (i < countA)
	{
		if (tabA[i] > 2147483647 || tabA[i] < -2147483648)
			return (-1);
		j = i +1;
		while (j < countA)
		{
			if (tabA[i] == tabA[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}
long int *malloc_tab3(char **tab, long int countA)
{
	long int i;
	long int *tabA;

	tabA = malloc(sizeof(long int) * (countA));
	if (!tabA)
		return (0);
	i = 0;
	while (i < countA)
	{
		tabA[i] = ft_atol(tab[i]);
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

int validate_arg(char **argv)
{
	int i;
	
	i = 1;
	while (argv[i])
	{
		if (check_only_digit_and_minus_valid(argv[i]) == -1)
			return (-1);
		i++;
	}
	return (1);
}
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

int tri_5(long int *tabA, int countA)
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
	pb(tabA, &countA, tabB, &countB);
	tri_3(tabA, countA);
	push_cible_A(tabA, tabB, countA);
	pa(tabA, &countA, tabB, &countB);
	push_cible_A(tabA, tabB, countA);
	pa(tabA, &countA, tabB, &countB);
	ordonner_liste(tabA, countA);
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
		tri_5(tab, countA);
	/*else if (countA > 3)
	{
		Liste *liste = fill_List(tab, countA);
		if (list_sorted(liste) == 1)
		{
			return (1);
		}
		//algo_tri(liste);         //on va creer lalgo de tri et il va check si liste is sorted
		printList(liste);
		freeList(liste);
	}*/
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
	/*if (countB == 0)
		{
			ft_printf("liste trie et stack b vide\n");
			return (1);
		}
	else
		{
			ft_printf("liste trie et stack b non vide\n");
			return (1);
		}*/
	return (1);
}
void list_simplifier_valeurs(int long *tabA, int countA)
{
	int i;
	int j;

	long int tab_temp[countA];
	i = 0;
	while (i < countA)
	{
		tab_temp[i] = tabA[i];
		i++;		
	}
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

void sa(long int *tabA)
{
	int temp;

	temp = tabA[0];
	tabA[0] = tabA[1];
	tabA[1] = temp;
	ft_printf("sa\n");
}
void ra(long int *tabA, int countA)
{
	int i;
	i = 0;
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

void rra(long int *tabA, int countA)
{
	int i;
	int last_element;

	i = countA -1;
	last_element = tabA[countA - 1];
	while ( i > 0)
	{
		tabA[i] = tabA[i - 1];
		i--;
	}
	tabA[0] = last_element;
	ft_printf("rra\n");
}

void pb(long int *tabA, int *countA, long int *tabB, int *countB)
{
	int i;
	int j;

	i = 0;
	if (*countB == 0)
	{
		tabB[0] = tabA[0];
		//ft_printf("tabB: %d\n\n", tabB[i]);
		while (i < *countA -1)
		{
			tabA[i] = tabA[i + 1];
			//ft_printf("tabA: %d\n", tabA[i]);
			i++;
		}
		(*countA)--;
		(*countB)++;
	}
	else
	{
		j = *countB;
		while (j)
		{
			tabB[j] = tabB[j - 1];
			//ft_printf("tabB: %d\n", tabB[j]);
			j--;
		}
		tabB[0] = tabA[0];
		while (i < *countA -1)
		{
			tabA[i] = tabA[i + 1];
			//ft_printf("tabA: %d\n", tabA[i]);
			i++;
		}
		(*countA)--;
		(*countB)++;
	}
	ft_printf("pb\n");
}

void pa(long int *tabA, int *countA, long int *tabB, int *countB)
{
	int i;
	int j;

	i = 0;
	j = *countA;
	while (j)
	{
		tabA[j] = tabA[j - 1];
		//ft_printf("tabA: %d\n", tabA[j]);
		j--;
	}
	tabA[0] = tabB[0];
	while (i < *countB - 1)
	{
		tabB[i] = tabB[i +1];
		//ft_printf("tabB: %d\n", tabB[i]);
		i++;
	}
	(*countA)++;
	(*countB)--;
	ft_printf("pa\n");
	/*for (int x = 0; x < *countA ; x++)
	{
		ft_printf("tabA[%d] = %d\n", x, tabA[x]);
	}*/
}

////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////

/*void freeList(Liste *liste)
{
	Node *current = liste->premier;
	Node *nextNode;
	while (current)
	{
		nextNode = current->next;
        free(current);
        current = nextNode;
	}
	free(liste);
}*/
/*int	list_sorted(Liste *liste)
{
	Node *current;

	current = liste -> premier;
	while (current->next)
	{
		if (current -> data > current -> next->data)
		{
			ft_printf("liste non trie\n");
			return (-1);
		}
		current = current ->next;
	}
	ft_printf("liste trie\n");
	return (1);	
}*/


/*int algo_tri(Liste *liste)                                    // ALGO TRI !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
{
	Liste *listeB;

	pb(liste, listeB);
	if (list_sorted(liste) == 1)
	{
		//remettre ce quon vient de push b sur sa cible dans la stack a ; le chiffre le plus grand le plus proche de lui
		while (list_sorted(liste) == -1)
		//		si le plus petit est dans la partie haute des index on fait un rotate + list_sorted? si non on refait un rotate + list_sorted?
		//		si le plus petit est dans la partie basse des index on fait un reverse rotate + list_sorted? si non on refait un reverse rotate + list_sorted?		
	}
	pb(liste, listeB);
	if (list_sorted(liste) == 1)
	{
		//compter le nombre de coup pour mettre chacun des 2 nbrs de b sur sa cible dans la stack a ; le chiffre le plus grand le plus proche de lui,
		//	prendre celui qui prend le moins de coups a ranger sur a. puis ranger l autre ensuite.
		while(list_sorted(liste) == -1)
		{
			//
		}
	}
}*/


/*Liste *initialisation()
{
	Liste *liste = malloc(sizeof(*liste));
	if (liste == NULL)
		exit(EXIT_FAILURE);
	liste ->premier = NULL;
	return (liste);
}

Node *createNode(int data)
{
	Node *New = malloc(sizeof(Node));
	if (New == NULL)
	{
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
	New -> data = data;
	New -> next = NULL;
	return (New);
}
void appendNode(Liste *liste, int data)
{
	Node *newNode = createNode(data);
	if (liste -> premier == NULL)
		liste -> premier = newNode;
	else
	{
		Node *current = liste ->premier;
		while (current -> next)
			current = current -> next;
		current->next = newNode;
	}
}
Liste *fill_List(long int *tab, int countA)
{
	int i = 0;
	Liste *liste = initialisation();
	while (i < countA)
	{
		appendNode(liste, (int)tab[i]);
		i++;
	}
	return (liste);
}
void printList(Liste *liste)
{
    Node *current = liste -> premier;
    while (current != NULL)
	{
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}*/

int main(int argc, char **argv)
{
	(void)argv;
	
	if (argc > 1)
    {
        if (check_arg(argc, argv) == -1)
            ft_printf("ERROR\n");
    }
}
