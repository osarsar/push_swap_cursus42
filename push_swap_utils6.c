/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils6.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsar <osarsar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 09:40:50 by osarsar           #+#    #+#             */
/*   Updated: 2023/04/30 12:40:46 by osarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	number_no_flaged(t_list *stack_a)
{
	t_list	*head;
	int		i;

	i = 0;
	head = stack_a;
	while (head)
	{
		if (head->index != -1)
			i++;
		head = head->next;
	}
	return (i);
}

void	ft_temp(int temp, t_list **stack_a, t_list **stack_b)
{
	flag_stack(*stack_b);
	if (temp > 0)
	{
		while (temp > 1)
		{
			ra(stack_a);
			write(1, "ra\n", 3);
			temp--;
		}
		pa(stack_a, stack_b);
		write(1, "pa\n", 3);
	}
	else if (temp < 0)
	{
		temp = temp * -1;
		while (temp >= 1)
		{
			rra(stack_a);
			write(1, "rra\n", 4);
			temp--;
		}
		pa(stack_a, stack_b);
		write(1, "pa\n", 3);
	}
}

void	ft_temp_b(int temp, t_list **stack_a, t_list **stack_b)
{
	(void)stack_b;
	if (temp > 0)
	{
		while (temp > 1)
		{
			ra(stack_a);
			write(1, "ra\n", 3);
			temp--;
		}
	}
	else if (temp < 0)
	{
		temp = temp * -1;
		while (temp >= 1)
		{
			rra(stack_a);
			write(1, "rra\n", 4);
			temp--;
		}
	}
}

t_list	*place_node(t_list **head, t_list **max, t_list **b, t_list **a)
{
	while (*head)
	{
		flag_stack(*a);
		if ((*head)->content > (*b)->content
			&& (*head)->content < (*max)->content)
			*max = *head;
		*head = (*head)->next;
	}
	return (*a);
}
