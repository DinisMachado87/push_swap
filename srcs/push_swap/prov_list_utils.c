/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prov_list_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:51:31 by dimachad          #+#    #+#             */
/*   Updated: 2025/03/24 20:16:46 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	add_prov_node(t_prov_lis_node *arr_head, int i)
{
	t_prov_lis_node	*new_node;

	new_node = (t_prov_lis_node *)malloc(sizeof(t_prov_lis_node));
	if (!new_node)
	{
		// CREATE THIS FUNCTION free_list_prov(arr_head);
		return (error_handle());
	}
	if (!(*arr_head))
	{
		*arr_head = new_node;
		new_node->next_node = new_node;
		new_node->prev_node = new_node;
	}
	else
	{
		new_node->next_node = *arr_head;
		new_node->prev_node = (*arr_head)->prev_node;
		(*arr_head)->prev_node = new_node;
		new_node->prev_node->next_node = new_node; 
		*arr_head = new_node;
	}
	new_node->i = i;
	return (i)
}
