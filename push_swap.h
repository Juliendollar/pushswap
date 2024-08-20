/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jd-halle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 23:18:14 by jd-halle          #+#    #+#             */
/*   Updated: 2024/07/18 23:18:25 by jd-halle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
#include <limits.h>
#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int     check_only_digit_and_minus_valid(char *str);
long int	check_dup_limit_simplify_num(long int *tabA, long int countA);
int validate_arg(char **argv);
void simplify_numbers(int long *tabA, int countA);

long int check_arg(int argc, char **argv);

long int *allocate_and_fill_tab(char **argv, int argc, long int *countA, char ***tab);
void free_tab(char **tab);

int tri(long int *tab1, int countA);
int tri_2_3 (long int *tab, int countA);
int tri_4_5(long int *tabA, int countA);


void sa(long int *tab1);
void sb(long int *tabB);
void ss(long int *tabA, long int *tabB);
void pb(long int *tabA, int *countA, long int *tabB, int *countB);
void pa(long int *tabA, int countA, long int *tabB, int countB);
//void pa(long int *tabA, int *countA, long int *tabB, int *countB);

void ra(long int *tab1, int countA);
void rb(long int *tabB, int countB);
void rr(long int *tabA, int countA, long int *tabB, int countB);

void rra(long int *tab1, int countA);
void rrb(long int *tabB, int countB);
void rrr(long int *tabA, int countA, long int *tabB, int countB);

int list_sorted_tab(long int *tabA, int countA, int countB);

void sort_tab(long int *tab_temp, int countA);

int push_cible_A(long int *tabA, long int *tabB, int countA);
int	push_cible_a_reduite(long int *tabA, long int *tabB, int countA);
int median(long int *tabA, long int i, int countA);

void ordonner_liste(long int *tabA, int countA);

int tri_big(long int *tabA, int countA, long int *tabB, int countB);
int find_and_push_b(long int *tabA, int countA, long int *tabB, int countB);
int calculate_cost_b(int target_position, int countB);
int calculate_cost_a(int i, int countA);
int find_target_position(long int value, long int *tabB, int countB);
int find_max_in_b(long int *tabB,  int countB);

int push_a_vers_cible_b(long int *tabA, long int *tabB, int countB);
int	push_a_vers_cible_b_reduite(long int *tabB, long int *tabA, int countB);
int push_b_vers_cible_a(long int *tabA, long int *tabB, int countA, int countB);
int	push_b_vers_cible_a_reduite(long int *tabA, long int *tabB, int countA, int countB);
int	remonter_en_haut_de_tabB_la_cible_i(long int *tabB, long int i, int countB);
int	remonter_en_haut_de_tabA_la_cible_i(long int *tabA, long int i, int countA);

int calculate_moves(int count, int index);
int find_optimal_move_return_best_index_in_a(long int *tabA, int countA, long int *tabB, int countB);
int return_best_index_in_b(long int *tabA, int countA, long int *tabB, int countB, int i);
int find_and_push_b(long int *tabA, int countA, long int *tabB, int countB);
int find_a_to_push_to_b(long int *tabA, int countA, long int *tabB, int countB);

int find_min_in_b(long int *tabB, int countB);
int find_min_index_in_b(long int *tabB, int countB);

int find_max_in_b(long int *tabB, int countB);
int find_max_index_in_b(long int *tabB, int countB);
int find_max_in_a(long int *tabA,  int countA);



#endif