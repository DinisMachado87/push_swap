/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_max_subsequences.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42berlin.d>    +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:01:51 by dimachad          #+#    #+#             */
/*   Updated: 2025/03/26 18:01:51 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

// Finds the longuest increasing subsequence
// and the longuest decreasing subsequence in the remainder
static int    find_lis_lds(t_node *init_stack, int len)
{
    int max_lis;
    int max_lds;

    max_lis = find_lis(init_stack, len, 0, 1);
    ft_printf("lis = %d\n", max_lis);
	print_stack(init_stack, len);
    max_lds = find_lis(init_stack, len, 1, 0);
    ft_printf("lds = %d\n", max_lds);
	print_stack(init_stack, len);
    return (max_lis + max_lds);
}

// Finds the longuest decreasing subsequence
// and the longuest increasing subsequence in the remainder
static int    find_lds_lis(t_node *init_stack, int len)
{
    int max_lis;
    int max_lds;

    max_lds = find_lis(init_stack, len, 1, 1);
    ft_printf("lds = %d\n", max_lds);
	print_stack(init_stack, len);
    max_lis = find_lis(init_stack, len, 0, 0);
    ft_printf("lis = %d\n", max_lis);
	print_stack(init_stack, len);
    return (max_lis + max_lds);
}

// Checks if doing lis or lds first gets the best result
// and executes that option
int find_max_subsequences(t_node *init_stack, int len)
{
    int max_lis_lds;
    int max_lds_lis;

    max_lis_lds = find_lis_lds(init_stack, len);
    ft_printf("lis_lds = %d\n", max_lis_lds);
    max_lds_lis = find_lds_lis(init_stack, len);
    ft_printf("lds_lis = %d\n", max_lds_lis);
    if (max_lis_lds > (max_lds_lis * 2))
    {
        find_lis_lds(init_stack, len);
        return (max_lis_lds);
    }
    return (max_lds_lis);
}
