#include "libft/libft.h"
#include <stdio.h>
#include "ft_printf.h"
#include "push_swap.h"
void miniinit(t_list *p)
{
	p->print = 1;
	p->mlen = p->argcount; //massive len
	p->a_size = p->mlen;
	p->b_size = 0;
}
void sorting(t_lis *p)
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
int main (int argc, char** argv)
{
	char	*str;
	t_lis	p;
	int	i;
	char	*space;
	p.flags = setflags(av[1]);
	i = 1;
	while (argv[i])
	{
		if (!(validelemet(argv[i])))
		{
			if(str)
			{
				free(str);
				str = NULL;
			}
			write(1, "Error\n", 6);
			return (0);
		}
		else
		{
			if (!str)
			{
				str = "";
				space = "";
			}
			else
				space = " ";
			str = ft_strjoin(ft_strjoin(str, space), argv[i]);
		}
		i++;
	}
	if (str)
	{
		validate_of_stack(str, &p);
	}
	miniinit(&p);
	if (p.a_size == 3)
		sort3(&p);
	if (p.a_size == 5)
		sort5(&p);
	else
		sortmid(&p);
	sorting(&p)
	final_sort(&p);
	exit(0);
}
