/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:54:21 by dimachad          #+#    #+#             */
/*   Updated: 2025/03/24 18:15:16 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_arr(t_node *list_head, int len)
{
	t_node	*curr;

	curr = list_head;
	while (len--)
	{
		ft_printf("Num: %d - toMove: %d", curr->num, curr->to_move);
		if (len > 0)
			ft_printf(",\n");
		if (len == 0)
			ft_printf("\n-----\n");
		curr = curr->next_node;
	}
}

int	error_handle(void)
{
	ft_putstr_fd("Error", 2);
	return (-1);
}

int	main(int argc, char **argv)
{
	t_node	*a_stack_head;
	t_node	*b_stack_head;
	int		len;

	a_stack_head = NULL;
	b_stack_head = NULL;
	len = create_init_arr(argc, argv, &a_stack_head);
	if (len < 1)
		return (error_handle());	
    ft_printf("ORIGINAL SERIES\n");
	print_arr(a_stack_head, len);
    ft_printf("SWAP TEST\n");
    swap_a(&a_stack_head);
	print_arr(a_stack_head, len);
    ft_printf("PUSH TEST\n");
    ft_push(&a_stack_head, &b_stack_head, a);
	print_arr(a_stack_head, len);
	print_arr(b_stack_head, len);
    ft_printf("FIND LIS LDS TEST\n");
    find_max_subsequences(a_stack_head, len);
	print_arr(a_stack_head, len);
	return (0);
}

