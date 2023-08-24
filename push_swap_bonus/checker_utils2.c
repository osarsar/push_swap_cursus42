/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsar <osarsar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:44:51 by osarsar           #+#    #+#             */
/*   Updated: 2023/04/30 20:22:17 by osarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	size_stack(t_list *stack_a)
{
	t_list	*head;
	int		i;

	i = 0;
	head = stack_a;
	while (head)
	{
		head = head->next;
		i++;
	}
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t		i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
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

void	check_ok(t_list *stack_a, t_list *stack_b)
{
	if (check_sort(stack_a) == 1 && stack_b == NULL)
	{
		write(1, "OK\n", 3);
		exit(0);
	}
	else
	{
		write(1, "KO\n", 3);
		exit(0);
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
