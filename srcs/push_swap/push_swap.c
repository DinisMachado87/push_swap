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

int	error_handle(void)
{
	ft_putstr_fd("Error\n", 2);
	return (-1);
}

int	main(int argc, char **argv)
{
    t_stacks    *stacks;

    stacks = (t_stacks *)malloc(sizeof(t_stacks));
    if (!stacks)
        return (-1);
    init_stacks(argc, argv, stacks);
	if (!stacks)
		return (error_handle());	
	if (stacks->len_a == 0)
		return (0);	
    tests(stacks);
	return (0);
}

