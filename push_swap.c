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
        *countA = ft_countA_number(argv[1], ' ');
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
	tri(tabA, countA);
	free(tabA);
	if (argc == 2)
		free_tab(tab);
	return (1);
}


int main(int argc, char **argv)
{
	if (argc > 1)
    {
        if (check_arg(argc, argv) == -1)
            ft_printf("ERROR\n");
    }
	return (0);
}
/*int tri_small(long int *tabA, int countA)
{
	if (countA == 2)
		tri_2(tabA);
	if (countA == 3)
		tri_3(tabA);
	return (1);
}*/

int tri_2(long int *tab)
{
	if (tab[0] > tab[1])
		sa(tab);
	return (1);
}

int tri_3 (long int *tab, int countA)
{
	if (tab[1] > tab[2] && tab[2] > tab[0])
	{
		sa(tab);
		ra(tab, countA);
	}
	if (tab[2] > tab[0] && tab[0] > tab[1])
		sa(tab);
	if (tab[1] > tab[0] && tab[0] > tab[2])
		rra(tab, countA);
	if (tab[0] > tab[2] && tab[2] > tab[1])
		ra(tab, countA);
	if (tab[0] > tab[1] && tab[1] > tab[2])
	{
		sa(tab);
		rra(tab, countA);
	}
	return (1);
}
int tri(long int *tab, int countA)
{
	if (countA == 2)
		tri_2(tab);
	if (countA == 3)
		tri_3(tab, countA);
	return (1);
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
		//ft_printf("%d\n", tabA[i]);
		i++;
	}
	tabA[countA - 1] = first_element;
	//ft_printf("%d\n", tabA[i]);
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
void pb(long int *tabA, long int *tabB, int countA, int countB)
{

}


//valgrind --leak-check=full --track-origins=yes ./push_swap 12 13 1 2 5 64 15


/*typedef struct Node {
    int data;
	struct Node* next;
} Node;

Node *createNode(int data);

Node *createNode(int data)
{
	Node *New;
	New = malloc(sizeof(Node));
	New -> data = data;
	New -> next = NULL;
	printf("%d\n", New->data);
	return (New);
}

int main()
{
	Node *node1;
	node1 = createNode(0);
	printf("%d", node1->data);
	free (node1);
}*/