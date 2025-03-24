/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:54:21 by dimachad          #+#    #+#             */
/*   Updated: 2025/03/24 16:57:29 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_arr(t_node *node_head, int len)
{
	t_node	*curr_node;

	curr_node = node_head;
	while (len--)
	{
		ft_printf("%d", curr_node->num);	
		if (len > 0)
			ft_printf(", ");
		if (len == 0)
			ft_printf("\n");
		curr_node = curr_node->next_node;
	}
}

int	error_handle(void)
{
	ft_putstr_fd("Error", 2);
	return (-1);
}

int	main(int argc, char **argv)
{
	t_node	*init_arr_head;
	int		len;

	init_arr_head = NULL;
	len = create_init_arr(argc, argv, &init_arr_head);	
	if (len < 1)
	{
		error_handle();
		return (1);	
	}
	print_arr(init_arr_head, len);
	return (0);
}

