/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbutterm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 11:11:15 by bbutterm          #+#    #+#             */
/*   Updated: 2020/02/08 11:11:16 by bbutterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_lis *p)
{
	int b;

	if (p->b_size < 1)
		return ;
	b = p->bri[0];
	p->bri[0] = p->bri[1];
	p->bri[1] = b;
	if (p->print == 1)
		ft_putstr("sb\n");
}

void	rb(t_lis *p)
{
	int i;
	int k;

	if (p->b_size < 1)
		return ;
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

void	pb(t_lis *p)
{
	int k;
	int i;

	i = p->b_size;
	if (p->a_size == 0)
		return ;
	else
	{
		while (i >= 1)
		{
			p->bri[i] = p->bri[i - 1];
			i--;
		}
		p->bri[0] = p->ari[0];
		k = p->print;
		p->print = 0;
		ra(p);
		p->print = k;
		p->ari[p->mlen - 1] = (int)NULL;
		p->b_size += 1;
		p->a_size -= 1;
	}
	if (p->print == 1)
		ft_putstr("pb\n");
}

void	rrb(t_lis *p)
{
	int i;
	int k;

	if (p->b_size < 1)
		return ;
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
