/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_other.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbutterm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 11:11:26 by bbutterm          #+#    #+#             */
/*   Updated: 2020/02/08 11:11:27 by bbutterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_lis *p)
{
	if (p->a_size > 0)
		sa(p);
	if (p->b_size > 0)
		sb(p);
	if (p->print == 1)
		ft_putstr("ss\n");
}

void	rr(t_lis *p)
{
	if (p->a_size > 1)
		ra(p);
	if (p->b_size > 1)
		rb(p);
	if (p->print == 1)
		ft_putstr("rr\n");
}

void	rrr(t_lis *p)
{
	if (p->a_size > 1)
		rra(p);
	if (p->b_size > 1)
		rrb(p);
	if (p->print == 1)
		ft_putstr("rrr\n");
}

int		check_digits(unsigned long long a)
{
	int i;

	i = 0;
	while (a / 10 > 1)
	{
		a = a / 10;
		i++;
	}
	return (i);
}
