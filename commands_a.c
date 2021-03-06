/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbutterm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 19:16:49 by bbutterm          #+#    #+#             */
/*   Updated: 2020/02/13 19:16:50 by bbutterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_lis *p)
{
	int b;

	if (p->a_size < 1)
		return ;
	b = p->ari[0];
	p->ari[0] = p->ari[1];
	p->ari[1] = b;
	if (p->print == 1)
		ft_putstr("sa\n");
}

void	ra(t_lis *p)
{
	int i;
	int k;

	if (p->a_size < 1)
		return ;
	k = p->ari[0];
	i = 0;
	while (i < p->a_size - 1)
	{
		p->ari[i] = p->ari[i + 1];
		i++;
	}
	p->ari[p->a_size - 1] = k;
	if (p->print == 1)
		ft_putstr("ra\n");
}

void	pa(t_lis *p)
{
	int i;
	int k;

	i = p->a_size;
	if (p->b_size == 0)
		return ;
	else
	{
		while (i >= 1)
		{
			p->ari[i] = p->ari[i - 1];
			i--;
		}
		p->ari[0] = p->bri[0];
		k = p->print;
		p->print = 0;
		rb(p);
		p->print = k;
		p->bri[p->mlen - 1] = (int)NULL;
		p->a_size += 1;
		p->b_size -= 1;
	}
	if (p->print == 1)
		ft_putstr("pa\n");
}

void	rra(t_lis *p)
{
	int i;
	int k;

	if (p->a_size < 1)
		return ;
	k = p->ari[p->a_size - 1];
	i = p->a_size;
	while (--i > 0)
		p->ari[i] = p->ari[i - 1];
	p->ari[0] = k;
	if (p->print == 1)
		ft_putstr("rra\n");
}
