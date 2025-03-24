/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:38:43 by dimachad          #+#    #+#             */
/*   Updated: 2025/03/24 19:37:29 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Finds the longest increasing subsequence
int	*find_lis(t_node *list_head, int start, int len)
{
	t_node	*curr_node;
	t_node	*comp_node;
	int		i_num;
	int		prov_max_lis;


	curr_node = list_head;
	i_num = 0;
	prov_max_lis = 0;
	while (i_num <= len)
	{
		*comp_node = list_head;
		while (comp_node != curr_node)
		{
			prov_max_lis = 0;
			if (comp_node->num <= curr_node->num && comp_node->sub_len > prov_max_lis)
			{
				curr_node->sub_len = prov_max_lis;
				// curr_node->prov_prev = comp_node;
				add_prov_node(comp_node->prov_lis_head, comp_node->i)
				prov_max_lis = comp_node->sub_len;
			}
			comp_node = comp_node->next_node;
		}
		i_num++;
		curr_node = curr_node->next_node;
	}
}

