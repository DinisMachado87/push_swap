/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42berlin.d>    +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 19:28:32 by dimachad          #+#    #+#             */
/*   Updated: 2025/03/27 19:28:32 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//pa (push a): Take the first element at the top of b and put it at the top of a.
//Do nothing if b is empty.
//pb (push b): Take the first element at the top of a and put it at the top of b.
//Do nothing if a is empty.

static void push(t_node **head_move, t_node **head_host, char print_chr)
{
    t_node  *new_head_move;

    if (!(head_move))
        return ;
    new_head_move = (*head_move)->next_node;
    (*head_move)->prev_node->next_node = (*head_move)->next_node;
    (*head_move)->next_node->prev_node = (*head_move)->prev_node;
    if (*head_host)
    {
        (*head_host)->prev_node->next_node = *head_move;
        (*head_move)->next_node = *head_host;
        (*head_move)->prev_node = (*head_host)->prev_node;
        (*head_host)->prev_node = *head_move;
        *head_host = *head_move;
    }
    else
    {
        *head_host = *head_move;
        (*head_host)->next_node = *head_host;
        (*head_host)->prev_node = *head_host;
    }
    *head_host = *head_move;
    *head_move = new_head_move;
    ft_printf("s%c\n", print_chr);
}

void    push_to_a(t_stacks *stacks)
{
    push(&stacks->b_head, &stacks->a_head, 'a');
}

void    push_to_b(t_stacks *stacks)
{
    push(&stacks->a_head, &stacks->b_head, 'b');
}
