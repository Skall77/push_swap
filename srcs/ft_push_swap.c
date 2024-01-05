/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skall <skall@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:14:39 by aaudevar          #+#    #+#             */
/*   Updated: 2022/12/14 19:01:43 by skall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

int	is_dup(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_strcmp(av[i], av[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_int(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (av[i])
	{
		while (av[i][j])
		{
			if (av[i][j] == '-')
				j++;
			if ((av[i][j] >= 0 && av[i][j] < '0') ||
				(av[i][j] > '9'))
				return (0);
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

int	good_arguments(char **av)
{
	if (is_dup(av) == 0)
		return (0);
	if (is_int(av) == 0)
		return (0);
	else
		return (1);
}

void	clear_pile(t_pile **a, t_pile **b)
{
	t_pile	*temp;

	while (*a)
	{
		temp = (*a)->next;
		free(*a);
		*a = temp;
	}
	*a = NULL;
	while (*b)
	{
		temp = (*b)->next;
		free(*b);
		*b = temp;
	}
	*b = NULL;
}

int	main(int argc, char **argv)
{
	t_pile	*a;
	t_pile	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (-1);
	if (!good_arguments(argv))
		handle_error();
	if (!(not_int(argv)))
		handle_error();
	a = init_pile(a, b, argv, argc);
	if (sorted(a))
	{
		clear_pile(&a, &b);
		return (0);
	}
	init_index(&a);
	sort(&a, &b);
	clear_pile(&a, &b);
}
