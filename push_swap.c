/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbutterm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 11:12:22 by bbutterm          #+#    #+#             */
/*   Updated: 2020/02/08 11:12:25 by bbutterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	miniinit(t_lis *p)
{
	p->mlen = p->argcount;
	p->a_size = p->mlen;
	p->b_size = 0;
}

void	sorting(t_lis *p)
{
	while (p->b_size > 0)
	{
		rbcount(p);
		racount(p);
		p->min_op_in = min_operation(p);
		rb_ops(p);
		ra_ops(p);
	}
}

void	van_sort(t_lis *p)
{
	if (p->a_size == 3)
		sort3(p);
	else if (p->a_size == 5)
		sort5(p);
	else
	{
		sortmid(p);
		sorting(p);
		final_sort(p);
	}
}

void	check_a(t_lis *p)
{
	int i;

	i = 0;
	while (i < p->a_size - 1)
	{
		if (p->ari[i] < p->ari[i + 1])
		{
			i++;
			continue;
		}
		return ;
	}
	exit(0);
}

int		main(int argc, char **argv)
{
	char	*str;
	t_lis	p;
	int		i;
	char	*space;

	if (argc < 2)
		exit(0);
	str = NULL;
	space = NULL;
	p.print = 1;
	i = 2;
	if (!(p.flags = setflags(argv[1])))
		i = 1;
	str = fill_str(argv, i, str, space);
	if (str && (str[0] != '\0'))
		validate_of_stack(str, &p);
	else
		ft_error();
	miniinit(&p);
	if (p.a_size == 1)
		exit(0);
	check_a(&p);
	van_sort(&p);
	exit(0);
}
