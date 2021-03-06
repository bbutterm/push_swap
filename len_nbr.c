/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbutterm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 19:17:23 by bbutterm          #+#    #+#             */
/*   Updated: 2020/02/13 19:17:24 by bbutterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_sort(t_lis *p)
{
	int i;
	int med;

	i = 0;
	med = p->a_size / 2;
	while (p->ari[i] != p->min)
		i++;
	if (i < med)
	{
		while (p->ari[0] != p->min)
			ra(p);
	}
	else if (i >= med)
	{
		while (p->ari[0] != p->min)
			rra(p);
	}
}

int		init(t_lis *p, int argc)
{
	if (!(p->ari = (int *)malloc(sizeof(int) * (argc))))
		exit(-1);
	if (!(p->bri = (int *)malloc(sizeof(int) * (argc))))
		exit(-1);
	if (!(p->v = (int *)malloc(sizeof(int) * (argc))))
		exit(-1);
	if (!(p->rbops = (int *)ft_memalloc(sizeof(int) * (argc + 1))))
		exit(-1);
	if (!(p->sumops = (int *)ft_memalloc(sizeof(int) * (argc + 1))))
		exit(-1);
	if (!(p->check_point = (int *)ft_memalloc(sizeof(int) * (argc + 1))))
		exit(-1);
	return (1);
}

int		len_nbr(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') || \
				(str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] && \
				((str[i] != '\n') && (str[i] != '\t') && (str[i] != '\v') && \
				(str[i] != ' ') && (str[i] != '\f') && (str[i] != '\r')))
			i++;
	}
	return (count);
}

int		setflags(char *s)
{
	if ((!(ft_strcmp(s, "-v"))) || (!(ft_strcmp(s, "-c"))))
	{
		if ((!(ft_strcmp(s, "-v"))))
			return (1);
		if ((!(ft_strcmp(s, "-c"))))
			return (2);
	}
	return (0);
}

char	*fill_str(char **argv, int i, char *str, char *space)
{
	char	*tmp;

	if (!str)
		space = "";
	while (argv[i])
	{
		if (!(validelemet(argv[i])))
		{
			if (str)
				free(str);
			write(1, "Error\n", 6);
			exit(0);
		}
		else
		{
			tmp = ft_strnew(ft_strlen(str) + ft_strlen(argv[i]) + 1);
			ft_strcat(ft_strcat(ft_strcpy(tmp, str), space), argv[i]);
			ft_strdel(&str);
			str = tmp;
		}
		space = " ";
		i++;
	}
	return (str);
}
