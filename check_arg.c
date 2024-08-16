/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jd-halle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:56:58 by jd-halle          #+#    #+#             */
/*   Updated: 2024/08/16 16:56:59 by jd-halle         ###   ########.fr       */
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
			if (ft_isdigit(str[i]) && str[i + 1] == '-')
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