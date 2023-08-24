/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsar <osarsar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:47:14 by osarsar           #+#    #+#             */
/*   Updated: 2023/05/03 21:12:47 by osarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	free_tmp(t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	free(tmp);
}

void	free_memory(t_list *stack_a, t_list *stack_b)
{
	free (stack_b);
	while (stack_a)
	{
		free(stack_a);
		stack_a = stack_a->next;
	}
}

void	parssing(char **av, t_list *stack_a)
{
	char	**split;

	split = split_stack(av);
	creat_stack(stack_a, split);
	free(split);
}

void	quit(t_list *stack_a, t_list *stack_b, char *input)
{
	ft_putstr_fd("Error\n", 2);
	free(input);
	free_memory(stack_a, stack_b);
	exit(1);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*input;

	input = NULL;
	stack_b = NULL;
	if (ac > 1)
	{
		ag(av);
		stack_a = ft_lstnew(42);
		parssing(av, stack_a);
		free_tmp(&stack_a);
		check_same_number(stack_a);
		input = get_next_line(0);
		while (input)
		{
			modulation_stack(&stack_a, &stack_b, input);
			free(input);
			input = get_next_line(0);
		}
		free(input);
		check_ok(stack_a, stack_b);
		free_memory(stack_a, stack_b);
	}
}
