/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_other.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <jijerde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:12:35 by jijerde           #+#    #+#             */
/*   Updated: 2020/02/04 18:46:13 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ss(t_lis *p)
{
	sa(p);
	sb(p);
	if (p->print == 1)
		ft_putstr("ss\n");
}

void rr(t_lis *p)
{
	ra(p);
	rb(p);
	if (p->print == 1)
		ft_putstr("rr\n");
}

void rrr(t_lis *p)
{
	rra(p);
	rrb(p);
	if (p->print == 1)
		ft_putstr("rrr\n");
}
