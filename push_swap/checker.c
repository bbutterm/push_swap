#include "libft/libft.h"
#include <stdio.h>
#include "ft_printf.h"
#include "push_swap.h"
#include "get_next_line.h"
void checker(p_list *p)
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
void visual(int i,p_list *p) {
    if (p->flags == 2) {
        while (i >= 0) {
            write(1, "\033[0;32m\xE2\x99\xBF ", 12);
            i--;
            //write(1, "\033[0m", 4);
        }
    }
}
int weight(v_list *vis,int num)
{
    while (vis->num != num)
    {
        vis = vis->next;
    }
    return vis->weight;
}
void pri(p_list *p)
{
    int i;
    int w;
    i = 0;
	printf("stack a \n");
    while (i < p->a_size)
    {
		printf("%d\n", p->ari[i]);
		w = weight(p->vis,p->ari[i]);
		visual(w,p);
        write(1,"\n",1);
        i++;
    }
    i = 0;
	printf("stack b \n");
    while (i < p->b_size)
    {
		printf("%d\n", p->bri[i]);
        w = weight(p->vis,p->bri[i]);
        visual(w,p);
        write(1,"\n",1);
        i++;
    }
    //checker(p);
}
void sa(p_list *p)
{
    int b;
    b = p->ari[0];
    p->ari[0] = p->ari[1];
    p->ari[1] = b;
    if (p->print == 1)
		printf("sa\n");

}
void sb(p_list *p)
{
    int b;
    b = p->bri[0];
    p->bri[0] = p->bri[1];
    p->bri[1] = b;
    if (p->print == 1)
		printf("sb\n");
}
void ss(p_list *p)
{
    sa(p);
    sb(p);
    if (p->print == 1)
		printf("ss\n");
}
void ra(p_list *p)
{
    int i;
    int k;
    k = p->ari[0];
    i = 0;
    while (i <= p->a_size-1)
    {
        p->ari[i] = p->ari[i+1];
        i++;
    }
    p->ari[p->a_size-1] = k;
    if (p->print == 1)
		printf("ra\n");
}
void rb(p_list *p)
{
    int i;
    int k;
    k = p->bri[0];
    i = 0;
    while (i <= p->b_size-1)
    {
        p->bri[i] = p->bri[i+1];
        i++;
    }
    p->bri[p->b_size-1] = k;
    if (p->print == 1)
		printf("rb\n");
}
void rr(p_list *p)
{
    ra(p);
    rb(p);
    if (p->print == 1)
		printf("rr\n");
}
void pb(p_list *p)
{
    int i;
    i = p->b_size;
    if (p->a_size == 0)
        return;
    else
        {
            while (i >= 1)
            {
                p->bri[i] = p->bri[i-1];
                i--;
            }
            p->bri[0] = p->ari[0];
            ra(p);
            // p->ari[p->mlen-1] = (int)NULL;
            p->b_size+=1;
            p->a_size-=1;
        }
        if (p->print == 1)
			printf("pb\n");
}
void pa(p_list *p)
{
    int i;
    i = p->a_size;
    if (p->b_size == 0)
        return;
    else
        {
            while (i >= 1)
            {
                p->ari[i] = p->ari[i-1];
                i--;
            }
            p->ari[0] = p->bri[0];
            rb(p);
            // p->bri[p->mlen-1] = (int)NULL;
            p->a_size+=1;
            p->b_size-=1;
        }
        if (p->print == 1)
			printf("pa\n");
}
void rra(p_list *p)
{
    int i;
    int k;
    k = p->ari[p->a_size-1];
    i = p->a_size;
    while (i > 0)
    {
        p->ari[i] = p->ari[i-1];
        i--;
    }
    p->ari[0] = k;
    if (p->print == 1)
		printf("rra\n");
}
void rrb(p_list *p)
{
    int i;
    int k;
    k = p->bri[p->b_size-1];
    i = p->b_size;
    while (i > 0)
    {
        p->bri[i] = p->bri[i-1];
        i--;
    }
    p->bri[0] = k;
    if (p->print == 1)
		printf("rrb\n");
}
void rrr(p_list *p)
{
    rra(p);
    rrb(p);
    if (p->print == 1)
		printf("rrr\n");
}
void ssort(int *v, int size)
{
    int i;
    int tmp;
    i = 0;

    while (i < size - 1)
    {
        if (v[i] > v[i+1])
        {
            tmp = v[i];
            v[i] = v[i+1];
            v[i+1] = tmp;
            i = -1;
        }
        i++;
    }
}
void ifswap(p_list *p,char *line)
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
void swap(p_list *p)
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
void vinit(p_list *p, int *v,int size)
{
    int i;
    v_list *tmp;

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
void pushback(p_list *p)
{
    v_list *tmp;

    if (!p->vis)
        p->vis = (v_list *)ft_memalloc(sizeof(v_list));
    else{
        tmp = p->vis;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = (v_list *) ft_memalloc(sizeof(v_list));
    }
}
int init_checker(p_list *p, int argc)
{
    if(!(p->ari = (int *)ft_memalloc(sizeof(int) * (argc-1))))
        return(0);
    if(!(p->bri = (int *)ft_memalloc(sizeof(int) * (argc-1))))
        return(0);
    return (1);
}
int main (int argc, char** argv)
{
    p_list p;
    p.flags = 2;
    int i;
    int k;
    init_checker(&p,argc);
    k = argc -1;
    p.print = 0;
    i = 1;

    while (k >= 0)
    {
        pushback(&p);
        k--;
    }
    if(!(p.v = (int *)ft_memalloc(sizeof(int) * (argc-1))))
        return(0);
    p.mlen = argc-1; //massive len
    p.a_size = p.mlen;
    p.b_size = 0;
    while (i < argc)
    {
        p.ari[i-1] = atoi(argv[i]);
        p.v[i-1] = atoi(argv[i]);
        i++;
    }
    ssort(p.v,p.mlen);
    vinit(&p,p.v,p.mlen-1);
    swap(&p);
    //pri(&p);
    // sa(p.ari);
    return(0);
}
