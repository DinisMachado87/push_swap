typedef struct s_node 
{
	int		num;
	t_node	*next_node;
} t_node;

void	add_node(t_node **node_head, int num)
{
	t_node	*new_node;

	new_node = (t_node)malloc(sizeof(t_node))
	new_node->next_node = *node_head;
	*node_head = new_node;
	new_node->num = num;
}

int	main(int argc, char **argv)
{
	t_node	*node_head;

	if (argc < 2)
		return (NULL);
	while (++*argv)
		add_node(node_head, *argv);
}

