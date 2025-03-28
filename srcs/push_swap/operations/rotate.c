/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42berlin.d>    +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:12:54 by dimachad          #+#    #+#             */
/*   Updated: 2025/03/28 13:12:54 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
// rr : ra and rb at the same time.
static void    rotate(t_node **list_head)
{
    *list_head = (*list_head)->next_node;
}

void    rotate_a(t_stacks *stacks)
{
    rotate(&stacks->a_head);
    ft_printf("ra\n");
}

void    rotate_b(t_stacks *stacks)
{
    rotate(&stacks->b_head);
    ft_printf("rb\n");
}

void    rotate_both(t_stacks *stacks)
{
    rotate(&stacks->a_head);
    rotate(&stacks->b_head);
    ft_printf("rr\n");
}

static void    rotate_reverse(t_node **list_head)
{
    *list_head = (*list_head)->prev_node;
}

void    rotate_reverse_a(t_stacks *stacks)
{
    rotate_reverse(&stacks->a_head);
    ft_printf("rra");
}

void    rotate_reverse_b(t_stacks *stacks)
{
    rotate_reverse(&stacks->b_head);
    ft_printf("rrb");
}

void    rotate_reverse_both(t_stacks *stacks)
{
    rotate_reverse(&stacks->a_head);
    rotate_reverse(&stacks->b_head);
    ft_printf("rrb");
}
