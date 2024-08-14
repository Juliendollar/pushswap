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

typedef struct Node {
    int data;
	struct Node* next;
} Node;

typedef struct Liste Liste;
struct Liste
{
    Node *premier;
};

int     check_only_digit_and_minus_valid(char *str);

long int *malloc_tab1(char **tab, long int countA_nombre_dans_arg_guillemets);
long int *malloc_tab_multiple_arg(char **argv, long int arc);

void free_tab1(char **tab);

int	check_arg1(char *str, long int countA_arg);
int check_arg2(char **argv, long int countA);

long int     check_duplicate_number(long int *tab1, long int countA);
long int	    check_max_min_int(long int *tab1);


int tri_small (long int *tab1, int countA);
int tri_2 (long int *tab);
int tri_3 (long int *tab, int countA);

long int *malloc_tab3(char **tab, long int countA);
long int check_arg(int argc, char **argv);

int validate_arg(char **argv);

void sa(long int *tab1);
void ra(long int *tab1, int countA);
void rra(long int *tab1, int countA);
int tri(long int *tab1, int countA);

Node *createNode(int data);
void printList(Liste *liste);
void appendNode(Liste *liste, int data);
Liste *initialisation();
void freeList(Liste *liste);
Liste *fill_List(long int *tab, int countA);

int tri_5(long int *tabA, int countA);
void pb(long int *tabA, int *countA, long int *tabB, int *countB);
int list_sorted_tab(long int *tabA, int countA, int countB);

void sort_tab(long int *tab_temp, int countA);
void list_simplifier_valeurs(int long *tabA, int countA);

int push_cible_A(long int *tabA, long int *tabB, int countA);
int median(long int *tabA, long int i, int countA);

void pa(long int *tabA, int *countA, long int *tabB, int *countB);
void ordonner_liste(long int *tabA, int countA);

#endif