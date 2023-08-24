/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils7.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsar <osarsar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 11:17:56 by osarsar           #+#    #+#             */
/*   Updated: 2023/04/30 12:40:38 by osarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_3(t_list **stack_a, int len)
{
	while (len > 0)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
		{
			sa(stack_a);
			write(1, "sa\n", 3);
			if (check_sort(*stack_a) == 1)
				return ;
		}
		rra(stack_a);
		write(1, "rra\n", 4);
		if (check_sort(*stack_a) == 1)
			return ;
		len--;
	}
}

int	check_sort(t_list *stack_a)
{
	t_list	*head;

	head = stack_a;
	while (head->next)
	{
		if (head->content > head->next->content)
			return (0);
		head = head->next;
	}
	return (1);
}

void	case_4(t_list **stack_a, int len, t_list **stack_b)
{
	t_list	*min;

	flag_stack(*stack_a);
	min = find_min(*stack_a);
	ft_temp_b(min->flag, stack_a, stack_b);
	if (check_sort(*stack_a) == 1)
		exit(0);
	pb(stack_b, stack_a);
	write(1, "pb\n", 3);
	case_3(stack_a, len);
	pa(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void	case_5(t_list **stack_a, int len, t_list **stack_b)
{
	t_list	*min;

	flag_stack(*stack_a);
	min = find_min(*stack_a);
	ft_temp_b(min->flag, stack_a, stack_b);
	if (check_sort(*stack_a) == 1)
		exit(0);
	pb(stack_b, stack_a);
	write(1, "pb\n", 3);
	case_4(stack_a, len, stack_b);
	pa(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void	condition_best(t_push **ptr)
{
	if ((*ptr)->b->min < (*ptr)->old)
	{
		(*ptr)->old = (*ptr)->b->min;
		(*ptr)->best = (*ptr)->b;
		(*ptr)->mv = (*ptr)->tmp;
	}
}
