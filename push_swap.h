/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jd-halle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 23:18:14 by jd-halle          #+#    #+#             */
/*   Updated: 2024/09/09 20:45:59 by jd-halle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "ft_printf.h"
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_moves
{
	int	moves_in_a;
	int	moves_in_b;
}	t_moves;

typedef struct s_push
{
	int	index;
	int	cible_trouvee;
	int	j;
	int	i;
}	t_push;

int			check_only_digit_and_minus_valid(char *str);
long int	check_dup_limit_simplify_num(long int *tab_a, long int countA);
int			validate_arg(char **argv);
void		simplify_numbers(int long *tab_a, int countA);

long int	check_arg(int argc, char **argv);

long int	*malloc_fill_tab(char **argv, int argc, long int *c_a, char ***tab);
void		free_tab(char **tab);
int			tri(long int *tab1, int countA);
int			tri_2_3(long int *tab, int countA);

void		sa(long int *tab1);
void		sb(long int *tab_b);
void		ss(long int *tab_a, long int *tab_b);
void		pb(long int *tab_a, int *countA, long int *tab_b, int *countB);
void		pa(long int *tab_a, int countA, long int *tab_b, int countB);

void		ra(long int *tab1, int countA);
void		rb(long int *tab_b, int count_b);
void		rr(long int *tab_a, int count_a, long int *tab_b, int count_b);

void		rra(long int *tab1, int count_a);
void		rrb(long int *tab_b, int count_b);
void		rrr(long int *tab_a, int count_a, long int *tab_b, int count_b);

int			list_sorted_tab(long int *tab_a, int countA, int count_b);

void		sort_tab(long int *tab_temp, int count_a);

void		ordonner_liste(long int *tab_a, int count_a);

int			tri_big(long int *tab_a, int c_a, long int *tab_b, int c_b);
int			find_and_push_b(long int *tab_a, int c_A, long int *tab_b, int c_b);

int			push_b_vers_cible_a(long int *t_a, long int *t_b, int c_a, int c_b);
int			push_b_vers_cible_a_reduite(long int *t_a, long int *t_b, int c_a);

int			remonter_cible_i_dans_tab_b(long int *tab_b, long int i, int c_b);
int			remonter_cible_i_dans_tab_a(long int *tab_a, long int i, int c_a);

int			calcul_move(int count, int index);

int			find_min_index_in_a(long int *tab_a, int count_a);
int			find_min_in_b(long int *tab_b, int countB);
int			find_max_in_a(long int *tab_a, int countA);
int			find_max_in_b(long int *tab_b, int countB);
int			find_max_index_in_b(long int *tab_b, int countB);

int			closest_i_b(long int *tab_b, int count_b, long int value);

int			get_moves_in_b(long int *tab_b, int count_b, long int value);
int			find_best_move_b(long int *tab_a, long int *tab_b, int c_b, int i);
int			find_best_move_a(long int *tab_a, int c_a, long int *t_b, int c_b);

int			find_cible_offset(long int *t_a, long int trgt, int ofset, int c_a);
int			find_min_index(long int *tabA, int countA);

#endif
