/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sum_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <jijerde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:26:29 by jijerde           #+#    #+#             */
/*   Updated: 2020/02/04 18:46:36 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rbcount(t_lis *p)
{
	int c;
	int b;
	c = 0;

	while (c < (p->b_size/2))
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

void racount(t_lis *p)
{
	int curr_min;
	int i;
	int j;
	int med;
	int curr_in;
	int n;

	j = 0;
	n = 0;
	while (j < p->b_size)
	{
		curr_min = p->min;
		i = 0;
		while (i < p->a_size)
		{
			if (p->ari[i] < p->bri[j])
			{
				if (p->ari[i] >= curr_min)
				{
					curr_min = p->ari[i];
					curr_in = i;
					p->check_point[n] = i;
				}
			}
			i++;
		}
		med = (p->a_size - 1) / 2;
		if (curr_in < med)
			p->sumops[n] = curr_in + 1 + p->rbops[n];
		else if (curr_in >= med)
			p->sumops[n] = (i - 1) - curr_in + p->rbops[n];
		n++;
		j++;
	}
}
