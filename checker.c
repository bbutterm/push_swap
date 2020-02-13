/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbutterm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 19:16:36 by bbutterm          #+#    #+#             */
/*   Updated: 2020/02/13 19:16:38 by bbutterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker(t_lis *p)
{
	int i;

	i = 0;
	while (i < p->a_size - 1)
	{
		if (p->ari[i] > p->ari[i + 1])
		{
			return (ft_putstr("KO\n"));
		}
		i++;
	}
	if (p->b_size == 0)
		return (ft_putstr("OK\n"));
	else
		return (ft_putstr("KO\n"));
}

void	ifswap(t_lis *p, char *line)
{
	if (!ft_strcmp(line, "sa"))
		sa(p);
	else if (!ft_strcmp(line, "sb"))
		sb(p);
	else if (!ft_strcmp(line, "ss"))
		ss(p);
	else if (!ft_strcmp(line, "pa"))
		pa(p);
	else if (!ft_strcmp(line, "pb"))
		pb(p);
	else if (!ft_strcmp(line, "ra"))
		ra(p);
	else if (!ft_strcmp(line, "rb"))
		rb(p);
	else if (!ft_strcmp(line, "rra"))
		rra(p);
	else if (!ft_strcmp(line, "rrb"))
		rrb(p);
	else if (!ft_strcmp(line, "rrr"))
		rrr(p);
	else
	{
		write(1, "Error\n", 6);
		exit(0);
	}
}

void	swap(t_lis *p)
{
	char *line;

	while (get_next_line(0, &line))
	{
		ifswap(p, line);
		if (p->flags > 0)
		{
			pri(p);
		}
		p->ops++;
		ft_strdel(&line);
	}
	checker(p);
}

void	push_backs(t_lis *p)
{
	int		k;

	k = p->argcount;
	while (--k >= 0)
		pushback(p);
	p->mlen = p->argcount;
	p->a_size = p->mlen;
	p->b_size = 0;
}

int		main(int argc, char **argv)
{
	char	*space;
	char	*str;
	int		i;
	t_lis	p;

	space = NULL;
	if (argc < 2)
		exit(0);
	ft_bzero(&p, sizeof(p));
	str = NULL;
	p.print = 0;
	i = 2;
	if (!(p.flags = setflags(argv[1])))
		i = 1;
	str = fill_str(argv, i, str, space);
	if (str && (str[0] != '\0'))
		validate_of_stack(str, &p);
	else
		ft_error();
	push_backs(&p);
	vinit(&p, p.v, p.mlen);
	swap(&p);
	exit(0);
}
