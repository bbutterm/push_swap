/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <jijerde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:07:40 by jijerde           #+#    #+#             */
/*   Updated: 2020/02/04 18:46:06 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sb(t_lis *p)
{
	int b;
	b = p->bri[0];
	p->bri[0] = p->bri[1];
	p->bri[1] = b;
	if (p->print == 1)
		ft_putstr("sb\n");
}

void rb(t_lis *p)
{
	int i;
	int k;
	k = p->bri[0];
	i = 0;
	while (i < p->b_size - 1)
	{
		p->bri[i] = p->bri[i + 1];
		i++;
	}
	p->bri[p->b_size - 1] = k;
	if (p->print == 1)
		ft_putstr("rb\n");
}

void pb(t_lis *p)
{
	int i;
	i = p->b_size;
	if (p->a_size == 0)
		return;
	else
	{
		while (i >= 1)
		{
			p->bri[i] = p->bri[i - 1];
			i--;
		}
		p->bri[0] = p->ari[0];
		p->print = 0;
		ra(p);
		p->print = 1;
		p->ari[p->mlen-1] = (int)NULL;
		p->b_size+=1;
		p->a_size-=1;
	}
	if (p->print == 1)
		ft_putstr("pb\n");
}

void rrb(t_lis *p)
{
	int i;
	int k;
	k = p->bri[p->b_size - 1];
	i = p->b_size;
	while (i > 0)
	{
		p->bri[i] = p->bri[i - 1];
		i--;
	}
	p->bri[0] = k;
	if (p->print == 1)
		ft_putstr("rrb\n");
}
