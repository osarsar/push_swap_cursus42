/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsar <osarsar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 08:39:14 by osarsar           #+#    #+#             */
/*   Updated: 2023/04/29 10:44:30 by osarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	best_move(t_push **ptr, t_list **a, t_list **b)
{
	while ((*ptr)->b)
	{
		flag_stack(*a);
		flag_stack(*b);
		(*ptr)->min = find_min(*a);
		(*ptr)->max = find_max(*a);
		if ((*ptr)->b->content > (*ptr)->max->content)
			(*ptr)->tmp = (*ptr)->min;
		else if ((*ptr)->b->content < (*ptr)->max->content)
		{
			(*ptr)->min = (*ptr)->max;
			(*ptr)->a = place_node(&(*ptr)->a, &(*ptr)->min, &(*ptr)->b, a);
			(*ptr)->tmp = (*ptr)->min;
		}
		if ((*ptr)->b->flag < 0)
			(*ptr)->b->min = abs((*ptr)->b->flag) + abs((*ptr)->tmp->flag) - 1;
		else
			(*ptr)->b->min = abs((*ptr)->b->flag) + abs((*ptr)->tmp->flag) - 2;
		condition_best(ptr);
		(*ptr)->b = (*ptr)->b->next;
	}
}

void	rotate_stack_b(t_push **ptr, t_list **stack_b, t_list **stack_a)
{
	if ((*ptr)->b->flag > 0)
		check_rr(ptr, stack_b, stack_a);
	if ((*ptr)->b->flag < 0)
		check_rrr(ptr, stack_b, stack_a);
}

void	push_b_to_a(t_push **ptr, t_list **stack_a, t_list **stack_b)
{
	if ((*ptr)->b->content > (*ptr)->max->content)
		(*ptr)->tmp = (*ptr)->min;
	else if ((*ptr)->b->content < (*ptr)->max->content)
	{
		(*ptr)->min = (*ptr)->max;
		place_node(&(*ptr)->a, &(*ptr)->min, &(*ptr)->b, stack_a);
		(*ptr)->tmp = (*ptr)->min;
	}
	ft_temp((*ptr)->tmp->flag, stack_a, stack_b);
}

void	check_rr(t_push **ptr, t_list **stack_b, t_list **stack_a)
{
	while ((*ptr)->b->flag > 1)
	{
		if ((*ptr)->mv->flag > 0)
		{
			rr(stack_a, stack_b);
			write(1, "rr\n", 3);
		}
		else
		{
			rb(stack_b);
			write(1, "rb\n", 3);
		}
		(*ptr)->b->flag--;
		(*ptr)->mv->flag--;
	}
}

void	check_rrr(t_push **ptr, t_list **stack_b, t_list **stack_a)
{
	(*ptr)->b->flag = (*ptr)->b->flag * -1;
	while ((*ptr)->b->flag >= 1)
	{
		if ((*ptr)->mv->flag < 0)
		{
			rrr(stack_a, stack_b);
			write(1, "rrr\n", 4);
		}
		else
		{
			rrb(stack_b);
			write(1, "rrb\n", 4);
		}
		(*ptr)->b->flag--;
		(*ptr)->mv->flag++;
	}
}
