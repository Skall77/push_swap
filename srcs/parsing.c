/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skall <skall@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:51:38 by aaudevar          #+#    #+#             */
/*   Updated: 2022/12/14 18:28:50 by skall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"
#include <limits.h>

int	not_int(char **av)
{
	long long	n;
	int			i;

	i = 1;
	while (av[i])
	{
		n = ft_atoil(av[i]);
		if (n > INT_MAX || n < INT_MIN)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

t_pile	*init_pile(t_pile *s, t_pile *b, char **av, int argc)
{
	int			n;
	t_pile		*new;

	argc--;
	while (argc > 0)
	{
		n = ft_atoi(av[argc]);
		new = ft_pilenew(n);
		if (new == NULL)
		{
			clear_pile(&s, &b);
			exit(-1);
		}
		ft_pileadd_front(&s, new);
		argc--;
	}
	return (s);
}

long long	ft_atoil(const char *nptr)
{
	int			i;
	long long	sign;
	long long	atoi;

	i = 0;
	sign = 1;
	atoi = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		atoi = atoi * 10 + nptr[i] - '0';
		i++;
	}
	return (atoi * sign);
}

t_pile	*get_min(t_pile **a)
{
	t_pile	*head;
	t_pile	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	head = *a;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (!has_min || head->value < min->value))
			{
				min = head;
				has_min = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

void	init_index(t_pile **a)
{
	t_pile	*head;
	int		index;

	index = 0;
	head = get_min(a);
	while (head)
	{
		head->index = index++;
		head = get_min(a);
	}
}
