/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skall <skall@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:15:49 by aaudevar          #+#    #+#             */
/*   Updated: 2022/12/14 18:59:02 by skall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

t_pile	*ft_pilenew(int n)
{
	t_pile	*new;

	new = malloc(sizeof(t_pile));
	if (new == NULL)
		return (NULL);
	new->value = n;
	new->index = -1;
	new->next = NULL;
	return (new);
}

void	ft_pileadd_front(t_pile **pile, t_pile *new)
{
	if (!*pile)
	{
		*pile = new;
		return ;
	}
	if (!new)
		return ;
	new->next = *pile;
	*pile = new;
}

int	sorted(t_pile *a)
{
	if (a)
	{
		while (a->next)
		{
			if (a->value > a->next->value)
				return (0);
			a = a->next;
		}
	}
	return (1);
}

int	pile_size(t_pile *a)
{
	int	i;

	i = 0;
	if (a)
	{
		while (a)
		{
			a = a->next;
			i++;
		}
	}
	return (i);
}
