/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbutterm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 19:18:09 by bbutterm          #+#    #+#             */
/*   Updated: 2020/02/13 19:18:10 by bbutterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	visual(int i, t_lis *p)
{
	if (p->flags == 2)
	{
		while (i >= 0)
		{
			write(1, "\033[0;32m\xE2\x99\xBF ", 12);
			write(1, "\033[0m", 5);
			i--;
		}
	}
}

int		weight(t_lisv *vis, int num)
{
	while (vis->num != num)
	{
		vis = vis->next;
	}
	return (vis->weight);
}

void	pri(t_lis *p)
{
	int i;
	int w;

	i = 0;
	ft_putstr("|[][][][]|\n|stack  a| \n|[][][][]|\n");
	while (i < p->a_size)
	{
		ft_putnbr(p->ari[i]);
		write(1, "\n", 1);
		w = weight(p->vis, p->ari[i]);
		visual(w, p);
		write(1, "\n", 1);
		i++;
	}
	i = 0;
	ft_putstr("|[][][][]|\n|stack  b| \n|[][][][]|\n");
	while (i < p->b_size)
	{
		ft_putnbr(p->bri[i]);
		write(1, "\n", 1);
		w = weight(p->vis, p->bri[i]);
		visual(w, p);
		write(1, "\n", 1);
		i++;
	}
}

void	vinit(t_lis *p, int *v, int size)
{
	int		i;
	t_lisv	*tmp;

	tmp = p->vis;
	i = 0;
	while (--size >= 0)
	{
		tmp->num = v[i];
		tmp->weight = i;
		tmp = tmp->next;
		i++;
	}
}

void	pushback(t_lis *p)
{
	t_lisv *tmp;

	if (!p)
		return ;
	if (!p->vis)
		p->vis = (t_lisv *)ft_memalloc(sizeof(t_lisv));
	else
	{
		tmp = p->vis;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = (t_lisv *)ft_memalloc(sizeof(t_lisv));
	}
}
