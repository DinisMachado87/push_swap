/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42berlin.d>    +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:35:09 by dimachad          #+#    #+#             */
/*   Updated: 2025/03/28 16:35:09 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void tests_operations(t_stacks *stacks)
{
    ft_printf("ORIGINAL SERIES\n");
	print_stack_a(stacks);

    ft_printf("SWAP TEST\n");
    swap_a(stacks);
	print_stack_a(stacks);

    ft_printf("PUSH TEST\n");
    push_to_b(stacks);
    push_to_b(stacks);
	print_stack_a(stacks);
	print_stack_b(stacks);

    ft_printf("ROTATE TEST\n");
    ft_printf("ROTATE_A ---\n");
	print_stack_a(stacks);
    rotate_a(stacks);
	print_stack_a(stacks);
    ft_printf("ROTATE_B\n");
	print_stack_b(stacks);
    rotate_b(stacks);
	print_stack_b(stacks);
}

static void tests_algo(t_stacks *stacks)
{
    ft_printf("FIND LIS LDS TEST\n");
    find_max_subsequences(stacks->a_head, stacks->len_a);
	print_stack_a(stacks);
}

void tests(t_stacks *stacks)
{
    tests_operations(stacks);
    tests_algo(stacks);
}

