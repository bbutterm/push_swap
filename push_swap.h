#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"
# include "ft_printf.h"

typedef struct	s_vlist
{
	int				weight;
	int				num;
    struct s_vlist 	*next;
}				t_lisv;

typedef struct	s_glist
{
	int			*ari; // stack a
	int			*bri; // stack b
	int			mlen; //massive len
    int			print;
    int			min;
    int			flags;
    int			*v;
    int			*rbops;
    int			*sumops;
    int			*check_point;
    int			ops;
    int			mid;
    int			max; //mmm values
    int			a_size;
    int			b_size;
    int			min_op_in;
    int			argcount;
    t_lisv		*vis;
}				t_lis;

void			sa(t_lis *p);
void			sb(t_lis *p);
void			ss(t_lis *p);
void			ra(t_lis *p);
void			rb(t_lis *p);
void			rra(t_lis *p);
void			rrb(t_lis *p);
void			pa(t_lis *p);
void			pb(t_lis *p);
void			rrr(t_lis *p);
void			final_sort(t_lis *p);
void			sortmid(t_lis *p);
int				sort3(t_lis *p);
void			sort5(t_lis *p);
void			ssort(int *v, int size);
void			rbcount(t_lis *p);
void			racount(t_lis *p);
int				min_operation(t_lis *p);
void			rb_ops(t_lis *p);
void			ra_ops(t_lis *p);
int				validelemet(char *stack1);
void			validate_of_stack(char *str, t_lis *p);
int				len_nbr(char *str);
int				init(t_lis *p, int argc);
int             setflags(char *s);

#endif
