/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:30:44 by dimachad          #+#    #+#             */
/*   Updated: 2025/03/24 19:10:28 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../../libft/libft.h"

typedef struct s_node 
{
	int				i;
	int				num;
	int				sub_len;
	t_prov_lis_node	prov_lis_head;
	struct s_node	*next_node;
	struct s_node	*prev_node;
} t_node;

typedef struct s_prov_lis_node
{
	int						i;
	struct s_prov_lis_node	*next_node;
	struct s_prov_lis_node	*prev_node;
} t_prov_lis_node

int		create_init_arr(int argc, char **argv, t_node **init_arr_head);
int		add_node(t_node **init_arr_head, int num, int i);
int		free_list(t_node **arr_head);
void	print_arr(t_node *list_head, int len);
int		error_handle(void);

#endif

