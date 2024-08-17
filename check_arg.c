/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jd-halle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:56:58 by jd-halle          #+#    #+#             */
/*   Updated: 2024/08/17 03:51:15 by jd-halle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate_arg(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (check_only_digit_and_minus_valid(argv[i]) == -1)
			return (-1);
		i++;
	}
	return (1);
}

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
		else if (str[i] == ' ' && str[i + 1] == '-'
			&& !(ft_isdigit(str[i + 2])))
			return (-1);
		else if (i > 0)
			if (ft_isdigit(str[i]) && str[i + 1] == '-')
				return (-1);
		i++;
	}
	return (1);
}

long int	check_dup_limit_simplify_num(long int *tabA, long int countA)
{
	int	i;
	int	j;

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
	simplify_numbers(tabA, countA);
	return (1);
}

void	simplify_numbers(int long *tabA, int countA)
{
	long int	*tab_temp;
	int	i;
	int	j;

	tab_temp = malloc (sizeof(long int) * countA);
	if(!tab_temp)
		return;
	i = -1;
	while (++i < countA)
		tab_temp[i] = tabA[i];
	sort_tab(tab_temp, countA);
	i = -1;
	while (++i < countA)
	{
		j = -1;
		while (++j < countA)
		{
			if (tabA[i] == tab_temp[j])
			{
				tabA[i] = j;
				break;
			}
		}
	}
	free(tab_temp);
}

void	sort_tab(long int *tab_temp, int countA)
{
	int	i;
	int	j;
	long int	temp;

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
