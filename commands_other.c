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
	sa(p);
	sb(p);
	if (p->print == 1)
		ft_putstr("ss\n");
}

void	rr(t_lis *p)
{
	ra(p);
	rb(p);
	if (p->print == 1)
		ft_putstr("rr\n");
}

void	rrr(t_lis *p)
{
	rra(p);
	rrb(p);
	if (p->print == 1)
		ft_putstr("rrr\n");
}
