/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:01:48 by aaudevar          #+#    #+#             */
/*   Updated: 2022/12/13 17:01:50 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void	print_pile(t_pile *a)
{
	while (a != NULL)
	{
		ft_printf("%d ", (a)->value);
		(a) = (a)->next;
	}
	ft_printf("\n");
}

int	third_value(t_pile *a)
{
	return (a->next->next->value);
}

void	handle_error(void)
{
	write(2, "Error\n", 6);
	exit(-1);
}
