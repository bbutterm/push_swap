#include "libft/libft.h"
#include <stdio.h>
#include "ft_printf.h"
#include "push_swap.h"


/*int init(t_lis *p, int argc)
{
	if (!(p->ari = (int *)malloc(sizeof(int) * (argc-1))))
		exit(-1);
	if (!(p->bri = (int *)malloc(sizeof(int) * (argc-1))))
		exit(-1);
	if (!(p->v = (int *)malloc(sizeof(int) * (argc - 1))))
		exit(-1);
	if (!(p->rbops = (int *)ft_memalloc(sizeof(int)*(argc + 1))))
		exit(-1);
	if (!(p->sumops = (int *)ft_memalloc(sizeof(int)*(argc + 1))))
		exit(-1);
	if (!(p->check_point = (int *)ft_memalloc(sizeof(int)*(argc + 1))))
		exit(-1);
	return (1);
}*/

int main (int argc, char** argv)
{
	char	*str;
	t_lis	p;
	int		i;
	char	*space;
	p.flags = 0;
	//int *v;
	p.print = 1;
	i = 1;
	//init(&p,argc);
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
	p.mlen = p.argcount; //massive len
	p.a_size = p.mlen;
	p.b_size = 0;
	/*while (i < argc)
	{
		p.v[i-1] = atoi(argv[i]);
		p.ari[i-1] = atoi(argv[i]);
		i++;
	}*/
	//ssort(p.v,p.mlen);
	//p.min = p.v[0];
	//p.max = p.v[p.a_size-1];
	//p.mid = p.v[(p.a_size-1)/2];
	//priv(v,p.mlen);
	if (p.a_size == 3)
		sort3(&p);
	if (p.a_size == 5)
		sort5(&p);
	else{
		sortmid(&p);
	}
	while (p.b_size > 0)
	{
		rbcount(&p);
		racount(&p);
		p.min_op_in = min_operation(&p);
		rb_ops(&p);
		ra_ops(&p);
	}
	final_sort(&p);
	exit(0);
}
