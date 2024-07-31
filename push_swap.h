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

long int *malloc_tab1(char **tab, long int count_nombre_dans_arg_guillemets);
long int *malloc_tab_multiple_arg(char **argv, long int arc);

void free_tab1(char **tab);

int	check_arg1(char *str, long int count_arg);
int check_arg2(char **argv, long int count);

long int     check_duplicate_number(long int *tab1, long int count);
long int	    check_max_min_int(long int *tab1);


int tri_small (long int *tab1, int count);
int tri_2 (long int *tab);
int tri_3 (long int *tab, int count);

long int *malloc_tab3(char **tab, long int count);
long int check_arg(int argc, char **argv);

int validate_arg(char **argv);

void sa(long int *tab1);
void ra(long int *tab1, int count);
void rra(long int *tab1, int count);
int tri(long int *tab1, int count);

#endif