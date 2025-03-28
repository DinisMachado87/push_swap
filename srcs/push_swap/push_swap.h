/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:30:44 by dimachad          #+#    #+#             */
/*   Updated: 2025/03/25 13:18:00 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../../libft/libft.h"

typedef struct s_node 
{
	int				i;
	int				num;
	int				to_move;
	int				sub_len;
	struct s_node	*prov_prev;
	struct s_node	*next_node;
	struct s_node	*prev_node;
}	t_node;

typedef struct s_stacks
{
	t_node	*a_head;
	t_node	*b_head;
	int		len_a;
    int     len_b;
}   t_stacks;

void     tests(t_stacks *stacks);
int		error_handle(void);

int     init_stacks(int argc, char **argv, t_stacks *stacks);
int		free_list(t_node **arr_head);

void	print_stack(t_node *stack_head, int len);
void    print_stack_a(t_stacks *stacks);
void    print_stack_b(t_stacks *stacks);

int 	find_lis(t_node *list_head, int len, int decreasing, int init_move);
int     find_max_subsequences(t_node *init_stack, int len);

void    push_to_a(t_stacks *stacks);
void    push_to_b(t_stacks *stacks);

void    rotate_a(t_stacks *stacks);
void    rotate_b(t_stacks *stacks);
void    rotate_both(t_stacks *stacks);
void    rotate_reverse_a(t_stacks *stacks);
void    rotate_reverse_b(t_stacks *stacks);
void    rotate_reverse_both(t_stacks *stacks);

void    swap_a(t_stacks *stacks);
void    swap_b(t_stacks *stacks);
void    swap_both(t_stacks *stacks);


#endif

