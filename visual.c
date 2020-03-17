/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <jijerde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 19:18:09 by bbutterm          #+#    #+#             */
/*   Updated: 2020/03/17 14:28:56 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	visual_b(int i, t_lis *p)
{
	int x;

	x = 3;
	if (p->flags == 2)
	{
		while (i >= 0)
		{
			attron(COLOR_PAIR(8) | A_BOLD);
			move(x, COLS - COLS/4 - 7);
			addch(ACS_BULLET);
			//write(1, "\033[0;32m\xE2\x99\xBF ", 12);
			//write(1, "\033[0m", 5);
			i--;
			x++;
		}
	}
}

void	visual(int i, t_lis *p)
{
	int x;

	x = 3;
	if (p->flags == 2)
	{
		while (i >= 0)
		{
			attron(COLOR_PAIR(8) | A_BOLD);
			move(x, COLS/4);
			addch(ACS_BULLET);
			//write(1, "\033[0;32m\xE2\x99\xBF ", 12);
			//write(1, "\033[0m", 5);
			i--;
			x++;
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

/*void	pri(t_lis *p)
{
	int i;
	//int w;

	i = 0;
	ft_putstr("|[][][][]||stack  a| |[][][][]|");
	ft_putstr("      ");
	ft_putstr("|[][][][]||stack  b| |[][][][]|\n");

	while (i < p->a_size)
	{
		if (p->ari[i])
			ft_putnbr(p->ari[i]);
		if (p->ari[i] && p->bri[i])
		{
			ft_putstr("                  ");
			ft_putnbr(p->bri[i]);
		}
		else if (!p->ari[i] && p->bri[i])
		{
			ft_putstr("                                        ");
			ft_putnbr(p->bri[i]);
		}
		write(1,"\n",1);
		i++;
	}
}*/

void	pri(t_lis *p)
{
	int i;
	int w;
	int j;

	i = 0;
	j = 0;
	//ft_putstr("|[][][][]|\n|stack  a| \n|[][][][]|\n");
	/*while (i < p->a_size)
	{
		ft_putnbr(p->ari[i]);
		write(1, "\n", 1);
		w = weight(p->vis, p->ari[i]);
		visual(w, p);
		write(1, "\n", 1);
		i++;
	}
	while (i < p->b_size)
	{
		ft_putnbr(p->bri[i]);
		write(1, "\n", 1);
		w = weight(p->vis, p->bri[i]);
		visual(w, p);
		write(1, "\n", 1);
		i++;
	}*/
	mvprintw(3, COLS/4, "ya za ciklom");
	while (1)
	{
		if (i < p->a_size)
		{
			mvprintw(3, COLS/4, "priv");
			w = weight(p->vis, p->ari[i]);
			visual(w, p);
			i++;
		}
		if (j < p->b_size)
		{
			mvprintw(3, COLS - COLS/4 - 7, "pok");
			w = weight(p->vis, p->bri[j]);
			visual_b(w, p);
			j++;
		}
		if ((i >= p->a_size) && (j >= p->b_size))
			break ;
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
