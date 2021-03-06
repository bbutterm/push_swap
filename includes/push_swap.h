/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <jijerde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 11:14:07 by bbutterm          #+#    #+#             */
/*   Updated: 2020/03/17 14:48:29 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"
# include "get_next_line.h"
#include <ncurses.h>
#include <curses.h>
#include <errno.h>

typedef struct		s_vlist
{
	int				weight;
	int				num;
	struct s_vlist	*next;
}					t_lisv;

typedef struct		s_glist
{
	int				*ari;
	int				*bri;
	int				mlen;
	int				print;
	int				min;
	int				flags;
	int				*v;
	int				*rbops;
	int				*sumops;
	int				*check_point;
	int				ops;
	int				mid;
	int				max;
	int				a_size;
	int				b_size;
	int				min_op_in;
	int				argcount;
	int				curr_in;
	int				curr_min;
	t_lisv			*vis;
}					t_lis;

void				sa(t_lis *p);
void				sb(t_lis *p);
void				ss(t_lis *p);
void				ra(t_lis *p);
void				rb(t_lis *p);
void				rra(t_lis *p);
void				rrb(t_lis *p);
void				pa(t_lis *p);
void				pb(t_lis *p);
void				rr(t_lis *p);
void				rrr(t_lis *p);
void				final_sort(t_lis *p);
void				sortmid(t_lis *p);
void				sort3(t_lis *p);
void				sort5(t_lis *p);
void				ssort(int *v, int size);
void				rbcount(t_lis *p);
void				racount(t_lis *p);
int					min_operation(t_lis *p);
void				rb_ops(t_lis *p);
void				ra_ops(t_lis *p);
int					validelemet(char *stack1);
void				validate_of_stack(char *str, t_lis *p);
int					len_nbr(char *str);
int					init(t_lis *p, int argc);
int					setflags(char *s);
void				ft_error(void);

void				init_ncur(t_lis *p);
void				pushback(t_lis *p);
void				vinit(t_lis *p, int *v, int size);
void				pri(t_lis *p);
char				*fill_str(char **argv, int i, char *str, char *space);
int					check_digits(unsigned long long a);

#endif
