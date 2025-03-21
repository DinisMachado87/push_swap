/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:30:48 by dimachad          #+#    #+#             */
/*   Updated: 2025/03/21 18:26:45 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_list(t_node **arr_head)
{
	t_node	*curr_node;
	t_node	*prev_node;

	curr_node = (*arr_head)->prev_node;
	prev_node = (*arr_head)->prev_node->prev_node;
	(*arr_head)->prev_node = NULL;
	while (curr_node->prev_node)
	{
		free(curr_node);
		curr_node = prev_node;
		prev_node = curr_node->prev_node;
	}
	*arr_head = NULL;
	return (0);
}

int	add_node(t_node **arr_head, int num, int i)
{
	t_node	*new_node;
	
	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
	{
		free_list(arr_head);
		return (error_handle());
	}
	if (*arr_head)
	{
		new_node->next_node = *arr_head;
		new_node->prev_node = (*arr_head)->prev_node;
		(*arr_head)->prev_node = new_node;
	}
	else
	{
		new_node->next_node = new_node;
		new_node->prev_node = new_node;
	}
	*arr_head = new_node;
	new_node->num = num;
	new_node->i = i;
	return (i);
}

int	create_init_arr(int argc, char **argv, t_node **init_arr_head)
{
	char	**splitted_arr;
	int		i;
	int		len;

	i = 0;
	if (argc < 2)
		return (-1);
	if (argc == 2)
		splitted_arr = ft_split(argv[1], ' ');
	else
		splitted_arr = argv++;
	while (splitted_arr[i])
		i++;
	len = i;
	while (--i >= 0)
	{
		i = add_node(init_arr_head, ft_atoi(splitted_arr[i]), i);
		if (i < 0)
			return (free_list(init_arr_head));
	}
	return (len);
}

