/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42berlin.d>    +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:55:23 by dimachad          #+#    #+#             */
/*   Updated: 2025/03/28 15:55:23 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_node *stack_head, int len)
{
	t_node	*curr;

	curr = stack_head;
	while (len--)
	{
		ft_printf("%d(%d),\t", curr->num, curr->to_move);
		if (len == 0)
			ft_printf("\n-----\n");
		curr = curr->next_node;
	}
}

void    print_stack_a(t_stacks *stacks)
{
    ft_printf("// _a:\t ");
	print_stack(stacks->a_head, stacks->len_a);
}

void    print_stack_b(t_stacks *stacks)
{
    ft_printf("// _b:\t");
	print_stack(stacks->b_head, stacks->len_b);
}

