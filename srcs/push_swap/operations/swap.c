/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42berlin.d>    +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:41:37 by dimachad          #+#    #+#             */
/*   Updated: 2025/03/27 14:41:37 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Swap_a, Swap_b
// Swap the first 2 elements at the top of a stack.
// Do nothing if there is only one element or none.
static int    swap(t_node **list_head)
{
    t_node  *one_to_two;
    t_node  *two_to_one;

    if (!(*list_head))
        return(error_handle());
    one_to_two = *list_head;
    two_to_one = (*list_head)->next_node;
    one_to_two->prev_node->next_node = two_to_one;
    two_to_one->next_node->prev_node = one_to_two;
    one_to_two->next_node = two_to_one->next_node;
    two_to_one->prev_node = one_to_two->prev_node;
    one_to_two->prev_node = two_to_one;
    two_to_one->next_node = one_to_two;
    *list_head = two_to_one;
    return (0);
}

void    swap_a(t_node **list_head)
{
    swap(list_head);
    ft_printf("sa");
}

void    swap_b(t_node **list_head)
{
    swap(list_head);
    ft_printf("sb");
}

void    swap_both(t_node **list_a_head, t_node **list_b_head)
{
    swap(list_a_head);
    swap(list_b_head);
    ft_printf("ss");
}
