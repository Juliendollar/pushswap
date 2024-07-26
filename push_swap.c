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
long int check_duplicate_number_and_max_min_int(long int *tab1, long int count)
{
	int	i;
	int j;

	i = 0;
	while (i < count)
	{
		if (tab1[i] == -0)
			tab1[i] = 0;
		i++;	
	}
	i = 0;
	while (i < count)
	{
		if (tab1[i] > 2147483647 || tab1[i] < -2147483648)
			return (-1);
		j = i +1;
		while (j < count)
		{
			if (tab1[i] == tab1[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}
long int *malloc_tab3(char **tab, long int count)
{
	long int i;
	long int *tab1;

	tab1 = malloc(sizeof(long int) * (count));
	if (!tab1)
		return (0);
	i = 0;
	while (i < count)
	{
		tab1[i] = ft_atol(tab[i]);
		i++;
	}
	return (tab1);
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

int validate_args(int argc, char **argv)
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
long int *allocate_and_fill_tab(char **argv, int argc, long int *count, char ***tab)
{
    if (argc == 2)
    {
        *count = ft_count_number(argv[1], ' ');
        *tab = ft_split(argv[1], ' ');
    }
    else
    {
        *count = argc - 1;
        *tab = &argv[1];
    }
    return malloc_tab3(*tab, *count);
}


long int check_arg(int argc, char **argv)
{
	long int	count;
	long int	*tab1;
	char **tab;
	int i;
	i = 1;

	if (validate_arg(argc, argv) == -1)
		return (-1);
	
	tab1 = malloc_tab3(tab, count);
	if (!tab1)
	{
		if (argc == 2)
			free_tab(tab);
		return (-1);
	}
	if (check_duplicate_number_and_max_min_int(tab1, count) == -1)
	{
		free(tab1);
		if (argc == 2)
			free_tab(tab);
		return (-1);
	}
	tri_small(tab1, count);
	free(tab1);
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
int tri_small(long int *tab1, int count)
{
	if (count == 2)
		tri_2(tab1);
	if (count == 3)
		tri_3(tab1);
	return (1);
}

int tri_2(long int *tab1)
{
	if (tab1[0] > tab1[1])
		ft_printf ("sa\n");
	return (1);
}

int tri_3 (long int *tab)
{
	if (tab[1] > tab[2] && tab[2] > tab[0])
	{
		ft_printf("sa\n");
		ft_printf("ra\n");
	}
	if (tab[2] > tab[0] && tab[0] > tab[1])
		ft_printf("sa");
	if (tab[1] > tab[0] && tab[0] > tab[2])
		ft_printf("rra");
	if (tab[0] > tab[2] && tab[2] > tab[1])
		ft_printf("ra");
	if (tab[0] > tab[1] && tab[1] > tab[2])
	{
		ft_printf("sa\n");
		ft_printf("rra\n");
	}
	return (1);
}




//valgrind --leak-check=full --track-origins=yes ./push_swap 12 13 1 2 5 64 15
