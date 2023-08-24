/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsar <osarsar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:56:59 by osarsar           #+#    #+#             */
/*   Updated: 2023/05/03 21:13:30 by osarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	while (!check_index(*stack_a))
	{
		flag_stack(*stack_a);
		tmp = *stack_a;
		while (tmp->index == -1)
			tmp = tmp->next;
		while ((*stack_a)->index == -1)
		{
			if (tmp->flag > 0)
			{
				ra(stack_a);
				write(1, "ra\n", 3);
			}
			else if (tmp->flag < 0)
			{
				rra(stack_a);
				write(1, "rra\n", 4);
			}
		}
		pb(stack_b, stack_a);
		write(1, "pb\n", 3);
	}
}

void	init_norm(t_push **ptr, t_list **stack_a, t_list **stack_b)
{
	(*ptr)->a = *stack_a;
	(*ptr)->b = *stack_b;
	(*ptr)->b->min = 2147483647;
	(*ptr)->old = (*ptr)->b->min;
}

t_list	*tri_stack(t_list **stack_a, t_list **stack_b)
{
	t_push	*ptr;
	int		i;

	ptr = malloc(sizeof(t_push));
	if (!ptr)
		return (0);
	i = 0;
	ptr->size_b = size_stack(*stack_b);
	while (i < ptr->size_b)
	{
		init_norm(&ptr, stack_a, stack_b);
		best_move(&ptr, stack_a, stack_b);
		ptr->b = ptr->best;
		rotate_stack_b(&ptr, stack_b, stack_a);
		flag_stack(*stack_a);
		ptr->min = find_min(*stack_a);
		ptr->max = find_max(*stack_a);
		ptr->a = *stack_a;
		ptr->b = *stack_b;
		push_b_to_a(&ptr, stack_a, stack_b);
		i++;
	}
	free(ptr);
	return (*stack_a);
}

void	ag(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j] == ' ')
		j++;
		if (str[i][j] == '\0')
			message_error();
		i++;
	}
}

void	basic_tri(t_list **stack_a, t_list **stack_b)
{
	int	len;

	len = ft_lstsize(*stack_a);
	if (len == 2)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
		{
			sa(stack_a);
			write(1, "sa\n", 3);
			exit(0);
		}
	}
	else if (len == 3)
		case_3(stack_a, len);
	else if (len == 4)
		case_4(stack_a, len, stack_b);
	else if (len == 5)
		case_5(stack_a, len, stack_b);
}
