/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsar <osarsar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:58:45 by osarsar           #+#    #+#             */
/*   Updated: 2023/05/03 21:06:49 by osarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**split_stack(char **av)
{
	int		i;
	char	*string;
	char	**split;

	string = ft_strdup("");
	i = 1;
	while (av[i])
	{
		string = ft_strjoin1(string, av[i]);
		string = ft_strjoin1(string, " ");
		i++;
	}
	i = 0;
	split = ft_split(string, ' ');
	check_valid_stack(string);
	free(string);
	return (split);
}

int	creat_stack(t_list	*stack_a, char **split)
{
	t_list	*tab;
	int		i;

	i = 0;
	while (split[i])
	{
		tab = ft_lstnew(ft_atoi(split[i]));
		ft_lstadd_back(&stack_a, tab);
		free(split[i]);
		i++;
	}
	return (i);
}

int	check_index(t_list *stack_a)
{
	int		i;
	t_list	*head;

	i = 0;
	head = stack_a;
	while (head)
	{
		if (head->index != -1)
			return (0);
		head = head->next;
	}
	return (1);
}

void	ft_norm(t_list *head, t_list **stack_a, t_list **stack_b)
{
	int	len;

	len = max_subsequence(head);
	add_minus_one(head, len);
	push_b(stack_a, stack_b);
	tri_stack(stack_a, stack_b);
	final_tri_stack(stack_a);
}

int	main(int ac, char **av)
{
	t_list	*stack_b;
	t_list	*stack_a;
	t_list	*tmp;
	char	**split;

	stack_b = NULL;
	if (ac >= 2)
	{
		ag(av);
		stack_a = ft_lstnew(42);
		split = split_stack(av);
		creat_stack(stack_a, split);
		free(split);
		tmp = stack_a;
		stack_a = stack_a->next;
		free(tmp);
		check_same_number(stack_a);
		if (check_sort(stack_a) == 1)
			exit(0);
		basic_tri(&stack_a, &stack_b);
		longest_increasing_subsequence(stack_a);
		ft_norm(stack_a, &stack_a, &stack_b);
		free_memory(stack_a, stack_b);
	}
}
