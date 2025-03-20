/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:54:21 by dimachad          #+#    #+#             */
/*   Updated: 2025/03/20 21:48:46 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"

typedef struct s_node 
{
	int				i;
	int				num;
	struct s_node	*next_node;
} t_node;

void	add_node(t_node **init_arr_head, int num, int i)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->next_node = *init_arr_head;
	*init_arr_head = new_node;
	new_node->num = num;
	new_node->i = i;
}

int	create_init_arr(int argc, char **argv, t_node **init_arr_head)
{
	char	**splitted_arr;
	int		i;

	i = 0;
	if (argc < 2)
		return (-1);
	if (argc == 2)
	{
		splitted_arr = ft_split(argv[1], ' ');
		while (splitted_arr[i])
		{
			add_node(init_arr_head, ft_atoi(splitted_arr[i]), i);
			i++;
		}
	}
	else
	{
		while (argv[i++])
			add_node(init_arr_head, ft_atoi(argv[i]), (i - 1));
	}
	return (i);
}

void	print_arr(t_node *node_head, int len)
{
	t_node	*curr_node;

	curr_node = node_head;
	while (len--)
	{
		ft_printf("%d, ", curr_node->num);	
		curr_node = curr_node->next_node;
	}
}

void	error_handle(void)
{
	ft_putstr_fd("Error", 2);
}

int	main(int argc, char **argv)
{
	t_node	*init_arr_head;
	int		len;

	len = create_init_arr(argc, argv, &init_arr_head);	
	if (len < 1)
	{
		error_handle();
		return (1);	
	}
	print_arr(init_arr_head, len);
	return (0);
}

