/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sum_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbutterm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 11:12:40 by bbutterm          #+#    #+#             */
/*   Updated: 2020/02/08 11:12:41 by bbutterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rbcount(t_lis *p)
{
	int c;
	int b;

	c = 0;
	while (c < (p->b_size / 2))
	{
		p->rbops[c] = c;
		c++;
	}
	b = c;
	if (p->b_size % 2 != 0)
	{
		p->rbops[b++] = c;
	}
	while (c >= 1)
	{
		p->rbops[b] = c;
		b++;
		c--;
	}
}

void	find_curr_in(t_lis *p, int i, int j, int n)
{
	if (p->ari[i] < p->bri[j])
	{
		if (p->ari[i] >= p->curr_min)
		{
			p->curr_min = p->ari[i];
			p->curr_in = i;
			p->check_point[n] = i;
		}
	}
}

void	racount(t_lis *p)
{
	int i;
	int j;
	int med;
	int n;

	j = 0;
	n = 0;
	while (j < p->b_size)
	{
		p->curr_min = p->min;
		i = 0;
		while (i < p->a_size)
		{
			find_curr_in(p, i, j, n);
			i++;
		}
		med = (p->a_size - 1) / 2;
		if (p->curr_in < med)
			p->sumops[n] = p->curr_in + 1 + p->rbops[n];
		else if (p->curr_in >= med)
			p->sumops[n] = (i - 1) - p->curr_in + p->rbops[n];
		n++;
		j++;
	}
}
