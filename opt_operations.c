/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <jijerde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:30:35 by jijerde           #+#    #+#             */
/*   Updated: 2020/02/04 18:46:21 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int min_operation(t_lis *p)
{
	int min_op;
	int min_op_in;
	int i;

	i = 0;
	min_op = p->sumops[0];
	min_op_in = 0;
	while (i < p->b_size)
	{
		if (p->sumops[i] < min_op)
		{
			min_op = p->sumops[i];
			min_op_in = i;
		}
		i++;
	}
	return (min_op_in);
}

void	rb_ops(t_lis *p)
{
	int med;
	while (p->rbops[p->min_op_in] > 0)
	{
		med = p->b_size / 2;
		if (p->min_op_in <= med)
		{
			//write(1, "rb\n", 3);
			rb(p);
		}
		else if (p->min_op_in > med)
		{
			//write(1, "rrb\n", 4);
			rrb(p);
		}
		p->rbops[p->min_op_in]--;
		p->sumops[p->min_op_in]--;
	}
}

void	ra_ops(t_lis *p)
{
	int med;
	//int i;

	//i = p->sumops[p->min_op_in];
	while (p->sumops[p->min_op_in] > 0)
	{
		med = (p->a_size - 1) / 2;
		if (p->check_point[p->min_op_in] < med)
		{
			//write(1, "ra\n", 3);
			ra(p);
		}
		else if (p->check_point[p->min_op_in] >= med)
		{
			//write(1, "rra\n", 4);
			rra(p);
		}
		p->sumops[p->min_op_in]--;
	}
	//write(1, "pa\n", 3);
	pa(p);
}
