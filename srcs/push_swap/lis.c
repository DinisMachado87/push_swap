/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:38:43 by dimachad          #+#    #+#             */
/*   Updated: 2025/03/25 13:33:46 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_len_and_prev(t_node *curr_node, int len, int init_move)
{
	while (0 < len--)
	{
        if (init_move)
		    curr_node->to_move = 0;
        if (!(curr_node->to_move))
        {
            curr_node->sub_len = 1;
            curr_node->prov_prev = NULL;
        }
		curr_node = curr_node->next_node;
	}
}

// takes list head as first comparison node
static void	find_num_sub_len_and_prev(t_node *comp_node, t_node *curr_node, int decreasing)
{
	while (comp_node != curr_node)
	{
        if (((comp_node->sub_len + 1) > curr_node->sub_len)
            && ((decreasing && (comp_node->num >= curr_node->num))
		    || (!decreasing && (comp_node->num <= curr_node->num))))
		{
			curr_node->sub_len = comp_node->sub_len + 1;
			curr_node->prov_prev = comp_node;
		}
		comp_node = comp_node->next_node;
        while (comp_node->to_move)
		    comp_node = comp_node->next_node;
	}
}

// Finds the longest increasing subsequence
int	find_lis(t_node *list_head, int len, int decreasing, int init_move)
{
	t_node			*curr_node;
	t_node			*last_num;
	int 			max_len;

	curr_node = list_head;
    last_num = NULL;
    max_len = 0;
	init_len_and_prev(curr_node, len, init_move);
	while (0 < len--)
	{
		curr_node = curr_node->next_node;
        while (curr_node->to_move)
        {
		    curr_node = curr_node->next_node;
            len--;
        }
		find_num_sub_len_and_prev(list_head, curr_node, decreasing);
		if (curr_node->sub_len > max_len)
		{
			max_len = curr_node->sub_len;
			last_num = curr_node;
		}
	}
	while (last_num->prov_prev)
	{
		last_num->to_move = decreasing + 1;
		last_num = last_num->prov_prev;
	}
    last_num->to_move = decreasing + 1;
    return (max_len);
}

