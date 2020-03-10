/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbutterm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 19:18:01 by bbutterm          #+#    #+#             */
/*   Updated: 2020/02/13 19:18:02 by bbutterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			atoi_for_ps(const char *str)
{
	int					i;
	long				nbr;
	int					negative;

	i = 0;
	nbr = 0;
	negative = 1;
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') ||
		(str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	(str[i] == '-') ? negative *= -1 : negative;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		nbr = (nbr * 10) + str[i] - 48;
		i++;
	}
	if (nbr > 2147483647 || nbr < -2147483648 ||
		i > 10 || check_digits(nbr) > 10)
		ft_error();
	nbr = nbr * negative;
	return ((int)nbr);
}

void		fill_a_v(char *str, int i, int j, t_lis *p)
{
	while (str[i] != '\0')
	{
		while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') || \
				(str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
			i++;
		if (str[i] != '\0')
		{
			p->ari[j] = atoi_for_ps(&str[i]);
			p->v[j] = atoi_for_ps(&str[i]);
			j++;
		}
		while (ft_isdigit(str[i]) || str[i] == '-')
			i++;
	}
}

void		check_double(char *str, t_lis *p)
{
	int		i;
	int		j;

	p->argcount = len_nbr(str);
	init(p, p->argcount);
	i = 0;
	j = 0;
	fill_a_v(str, i, j, p);
	ssort(p->v, p->argcount);
	p->min = p->v[0];
	p->max = p->v[p->argcount - 1];
	p->mid = p->v[(p->argcount - 1) / 2];
	i = 0;
	while (i < p->argcount - 1)
	{
		if (p->v[i] == p->v[i + 1])
		{
			write(1, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}

int			validelemet(char *stack1)
{
	int	i;

	i = 0;
	while (stack1[i])
	{
		if (stack1[i] == '-' && ft_isdigit(stack1[i + 1]))
			i++;
		if ((stack1[i] >= 48 && stack1[i] <= 57) || stack1[i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}

void		validate_of_stack(char *str, t_lis *p)
{
	int		i;

	i = 0;
	while (str[i])
	{
		while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') || \
				(str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
			i++;
		if (str[i] != '\0')
			atoi_for_ps(&str[i]);
		while (ft_isdigit(str[i]) || str[i] == '-')
		{
			if (ft_isdigit(str[i]) && str[i + 1] == '-')
			{
				write(1, "Error\n", 6);
				exit(1);
			}
			i++;
		}
	}
	check_double(str, p);
}
