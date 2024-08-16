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
long int check_duplicate_number_and_max_min_int(long int *tabA, long int countA);
int validate_arg(char **argv);

long int check_arg(int argc, char **argv);

long int *allocate_and_fill_tab(char **argv, int argc, long int *countA, char ***tab);
void free_tab(char **tab);

int tri(long int *tab1, int countA);
int tri_2 (long int *tab);
int tri_3 (long int *tab, int countA);
int tri_4_5(long int *tabA, int countA);


void sa(long int *tab1);
void ra(long int *tab1, int countA);
void rra(long int *tab1, int countA);

void pb(long int *tabA, int *countA, long int *tabB, int *countB);
int list_sorted_tab(long int *tabA, int countA, int countB);

void sort_tab(long int *tab_temp, int countA);
void list_simplifier_valeurs(int long *tabA, int countA);

int push_cible_A(long int *tabA, long int *tabB, int countA);
int median(long int *tabA, long int i, int countA);

void pa(long int *tabA, int *countA, long int *tabB, int *countB);
void ordonner_liste(long int *tabA, int countA);
void ss(long int *tabA, long int *tabB);
void rr(long int *tabA, int countA, long int *tabB, int countB);
void rrr(long int *tabA, int countA, long int *tabB, int countB);

#endif