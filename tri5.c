/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri5.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jd-halle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:14:07 by jd-halle          #+#    #+#             */
/*   Updated: 2024/09/07 20:25:31 by jd-halle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_b_vers_cible_a(long int *tabA, long int *tabB, int countA, int countB)
{
	int		index;
	t_push	push;

	if (push_b_vers_cible_a_reduite(tabA, tabB, countA))
		return (1);
	push.j = 1;
	while (push.j++ < countA)
	{
		push.i = -1;
		while (push.i++ < countB)
		{
			index = find_cible_offset(tabA, tabB[push.i], push.j, countA);
			if (index != -1)
			{
				remonter_cible_i_dans_tab_a(tabA, index, countA);
				return (1);
			}
		}
	}
	remonter_cible_i_dans_tab_a(tabA, 0, countA);
	return (1);
}
