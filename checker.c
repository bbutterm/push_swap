#include "libft/libft.h"
#include <stdio.h>
#include "ft_printf.h"
#include "push_swap.h"
#include "get_next_line.h"
void checker(t_lis *p)
{
    int i;
    i = 0;
    while (i < p->a_size - 1)
    {
        if (p->ari[i] > p->ari[i + 1])
            return (ft_putstr("KO\n"));
        i++;
    }
    return (ft_putstr("OK\n"));
}
void visual(int i,t_lis *p)
{
    if (p->flags == 2)
    {
        while (i >= 0)
        {
            write(1, "\033[0;32m\xE2\x99\xBF ", 12);
            i--;
            //write(1, "\033[0m", 4);
        }
    }
}
int weight(t_lisv *vis,int num)
{
    while (vis->num != num)
    {
        vis = vis->next;
    }
    return vis->weight;
}
void pri(t_lis *p)
{
    int i;
    int w;
    i = 0;
    ft_putstr("stack a \n");
    while (i < p->a_size)
    {
        ft_putnbr(p->ari[i]);
        write(1, "\n", 1);
		w = weight(p->vis,p->ari[i]);
		visual(w,p);
        write(1,"\n",1);
        i++;
    }
    i = 0;
    ft_putstr("stack b \n");
    while (i < p->b_size)
    {
        ft_putnbr(p->bri[i]);
        write(1, "\n", 1);
        w = weight(p->vis,p->bri[i]);
        visual(w,p);
        write(1,"\n",1);
        i++;
    }
    //checker(p);
}

void ifswap(t_lis *p,char *line)
{
    if (!ft_strcmp(line,"sa"))
        sa(p);
    if (!ft_strcmp(line,"sb"))
        sb(p);
    if (!ft_strcmp(line,"ss"))
        ss(p);
    if (!ft_strcmp(line,"pa"))
        pa(p);
    if (!ft_strcmp(line,"pb"))
        pb(p);
    if (!ft_strcmp(line,"ra"))
        ra(p);
    if (!ft_strcmp(line,"rb"))
        rb(p);
    if (!ft_strcmp(line,"rra"))
        rra(p);
    if (!ft_strcmp(line,"rrb"))
        rrb(p);
    if (!ft_strcmp(line,"rrr"))
        rrr(p);
}
void swap(t_lis *p)
{
    char *line;
    while(get_next_line(0,&line))
    {
        ifswap(p, line);
        if (p->flags > 0) {
            pri(p);
        }
        checker(p);
        p->ops++;
        //printf("operations = %d \n",p->ops);
    }
}
void vinit(t_lis *p, int *v,int size)
{
    int i;
    t_lisv *tmp;

    tmp = p->vis;
    i = 0;
    while (size >= 0)
    {
        tmp->num = v[i];
        tmp->weight = i;
        tmp = tmp->next;
        i++;
        size--;
    }
}
void pushback(t_lis *p)
{
    t_lisv *tmp;

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
//int init_checker(t_lis *p, int argc)
//{
//    if(!(p->ari = (int *)ft_memalloc(sizeof(int) * (argc-1))))
//        return(0);
//    if(!(p->bri = (int *)ft_memalloc(sizeof(int) * (argc-1))))
//        return(0);
//    return (1);
//}
int main (int argc, char** argv)
{
    char	*space;
    char	*str;
    int i;
    int k;
    t_lis p;
    p.flags = setflags(av[1]);
//    init_checker(&p,argc);
    p.print = 0;
    i = 1;
    //if(!(p.v = (int *)ft_memalloc(sizeof(int) * (argc-1))))
    //    return(0);
    while (argv[i])
    {
        if (!(validelemet(argv[i])))
        {
            if (str)
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
    k = p.argcount;
    while (k >= 0)
    {
        pushback(&p);
        k--;
    }
    p.mlen = p.argcount; //massive len
    p.a_size = p.mlen;
    p.b_size = 0;
//    while (i < argc)
//    {
//        p.ari[i-1] = atoi(argv[i]);
//        p.v[i-1] = atoi(argv[i]);
//        i++;
//    }
//    ssort(p.v,p.mlen);
    vinit(&p,p.v,p.mlen);
    swap(&p);
    //pri(&p);
    // sa(p.ari);
    exit(0);
}
