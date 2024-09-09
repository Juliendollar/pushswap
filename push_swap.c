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

long int	check_arg(int argc, char **argv)
{
	long int	count_a;
	long int	*tab_a;
	char		**tab;

	if (validate_arg(argv) == -1)
		return (-1);
	tab_a = malloc_fill_tab(argv, argc, &count_a, &tab);
	if (!tab_a)
	{
		if (argc == 2)
			free_tab(tab);
		return (-1);
	}
	if (check_dup_limit_simplify_num(tab_a, count_a) == -1)
	{
		free(tab_a);
		if (argc == 2)
			free_tab(tab);
		return (-1);
	}
	tri(tab_a, count_a);
	free(tab_a);
	if (argc == 2)
		free_tab(tab);
	return (1);
}

void	ordonner_liste(long int *tab_a, int count_a)
{
	int	i;

	i = 0;
	while (i < count_a && tab_a[i] != 0)
		i++;
	if (i == count_a)
		return ;
	if (i < count_a / 2)
	{
		while (i > 0)
		{
			ra(tab_a, count_a);
			i--;
		}
	}
	else
	{
		while (i < count_a)
		{
			rra(tab_a, count_a);
			i++;
		}
	}
}

int	list_sorted_tab(long int *tab_a, int count_a, int countB)
{
	int	i;

	(void)countB;
	i = 0;
	while (i < count_a -1)
	{
		if (tab_a[i] < tab_a[i + 1])
			i++;
		else
			return (-1);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		if (check_arg(argc, argv) == -1)
			ft_printf("ERROR\n");
	}
}
