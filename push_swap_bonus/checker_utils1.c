/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsar <osarsar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:43:09 by osarsar           #+#    #+#             */
/*   Updated: 2023/05/03 20:30:04 by osarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

void	check_same_number(t_list *stack_a)
{
	t_list	*head;
	t_list	*head_1;

	head = stack_a;
	head_1 = stack_a->next;
	while (head->next)
	{
		head_1 = head->next;
		while (head_1)
		{
			if (head->content == head_1->content)
			{
				ft_putstr_fd("Error\n", 2);
				exit(1);
			}
			head_1 = head_1->next;
		}
		head = head->next;
	}
}

int	check_valid_stack(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
		{
			i++;
			if (str[i] < '0' || str[i] > '9')
				message_error();
		}
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		if (str[i] != ' ' && str[i])
			message_error();
		i++;
	}
	return (1);
}

void	modulation_stack(t_list **a, t_list **b, char *input)
{
	if (!ft_strcmp(input, "ra\n") && *a && (*a)->next)
		ra(a);
	else if (!ft_strcmp(input, "rb\n") && *b && (*b)->next)
		rb(b);
	else if (!ft_strcmp(input, "rr\n") && *b && *a && (*a)->next && (*b)->next)
		rr(a, b);
	else if (!ft_strcmp(input, "rra\n") && *a && (*a)->next)
		rra(a);
	else if (!ft_strcmp(input, "rrb\n") && *b && (*b)->next)
		rrb(b);
	else if (!ft_strcmp(input, "rrr\n") && *a && *b && (*a)->next && (*b)->next)
		rrr(a, b);
	else if (!ft_strcmp(input, "sa\n") && *a && (*a)->next)
		sa(a);
	else if (!ft_strcmp(input, "sb\n") && *b && (*b)->next)
		sb(b);
	else if (!ft_strcmp(input, "ss\n") && *a && *b && (*a)->next && (*b)->next)
		ss(a, b);
	else if (!ft_strcmp(input, "pb\n") && *a)
		pb(b, a);
	else if (!ft_strcmp(input, "pa\n") && *b)
		pa(a, b);
	else
		other_case(input, a, b);
}
