/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <jijerde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:17:38 by jijerde           #+#    #+#             */
/*   Updated: 2020/02/04 18:46:29 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ssort(int *v, int size)
{
	int i;
	int tmp;
	i = 0;

	while (i < size - 1)
	{
		if (v[i] > v[i + 1])
		{
			tmp = v[i];
			v[i] = v[i + 1];
			v[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
}

int sort3(t_lis *p)
{
	if ((p->ari[0] > p->ari[1]) && (p->ari[1] < p->ari[2]) &&
	(p->ari[0] < p->ari[2]))
	{
		sa(p);
		return(1);
	}
	else if ((p->ari[0] > p->ari[1]) && (p->ari[1] > p->ari[2]) &&
	(p->ari[2]<p->ari[0]))
	{
		sa(p);
		rra(p);
		return(2);
	}
	else if ((p->ari[0] > p->ari[1]) && (p->ari[1] < p->ari[2]) &&
	(p->ari[0] > p->ari[2]))
	{
		ra(p);
		return(1);
	}
	else if ((p->ari[0] < p->ari[1]) && (p->ari[1] > p->ari[2]) &&
	(p->ari[0] < p->ari[2]))
	{
		sa(p);
		ra(p);
		return(2);
	}
	else if ((p->ari[0] < p->ari[1]) && (p->ari[1] > p->ari[2]) &&
	(p->ari[0] > p->ari[2]))
	{
		rra(p);
		return(1);
	}
	return(0);
}

void sortmid(t_lis *p)
{
	int i;
	i = 0;
	while (i < p->mlen)
	{
		if ((p->ari[0] == p->min) || (p->ari[0] == p->max))
			ra(p);
		else
		{
			pb(p);
			if (p->bri[0] > p->mid)
				rb(p);
		}
		i++;
	}
	if (p->ari[0] < p->ari[1])
		ra(p);
	pa(p);
	return ;
}

void sort5(t_lis *p)
{
	while (p->b_size < 2)
	{
		if (p->ari[0] == p->min || p->ari[0] == p->max)
			pb(p);
		else
			ra(p);
	}
	sort3(p);
	pa(p);
	pa(p);
	if (p->ari[0] == p->max)
		ra(p);
	else
	{
		sa(p);
		ra(p);
	}
}
