#include "libft/libft.h"
#include <stdio.h>
#include "ft_printf.h"
#include "push_swap.h"
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
    while (i < p->a_size-1)
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
    while (i < p->b_size-1)
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
            p->print = 0;
            ra(p);
            p->print = 1;
            p->ari[p->mlen-1] = (int)NULL;
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
            p->print = 0;
            rb(p);
            p->print = 1;
            p->bri[p->mlen-1] = (int)NULL;
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
int checkerv(int *v, int size)
{
    int i;
    i = 0;
    while (v[i] < v[i + 1])
    {
        i++;
        if (i == size)
        {
                return(1);
        }
    }
    return(0);
}

int checker(p_list *p)
{
    int i;
    i = 0;
    while (p->ari[i] < p->ari[i + 1])
    {
        i++;
        if (i == p->a_size)
        {
                return(1);
        }
    }
    return(0);
}
              
void pri(p_list *p)
{
    int i;
    i = 0;
	printf("stack a \n");
    while (i < p->a_size)
    {
		printf("%d\n", p->ari[i]);
        i++;
    }
    i = 0;
	printf("stack b \n");
    while (i < p->b_size)
    {
		printf("%d\n", p->bri[i]);
        i++;
    }
    checker(p);
    return;
}
void priv(int *v, int size)
{   
    int i;
    i = 0;
    while (i < size)
    {
        printf("%d\n",v[i]);
        i++;
    }
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

void mmmvalues(int *v,p_list *p)    
{
    int b;
    b = p->mlen;
    p->min = v[0];
    p->mid = v[b/2];
    p->max = v[p->mlen-1];
    return;
}
int sort3(p_list *p)
{
    if ((p->ari[0] > p->ari[1]) && (p->ari[1] < p->ari[2]) && (p->ari[0] < p->ari[2])){
        sa(p);
        return(1);}
    else if ((p->ari[0] > p->ari[1]) && (p->ari[1] > p->ari[2]) && (p->ari[2]<p->ari[0])) {
        sa(p);
        rra(p);
        return(2);
    }
    else if ((p->ari[0] > p->ari[1]) && (p->ari[1] < p->ari[2]) && (p->ari[0] > p->ari[2])){
        ra(p);
        return(1);
        }
    else if ((p->ari[0] < p->ari[1]) && (p->ari[1] > p->ari[2]) && (p->ari[0] < p->ari[2])){
        sa(p);
        ra(p);
        return(2);}
    else if ((p->ari[0] < p->ari[1]) && (p->ari[1] > p->ari[2]) && (p->ari[0] > p->ari[2])){
        rra(p);
        return(1);
    }
    return(0);
}
int primal_algorithm(p_list *p)
{  
    int i;
    int k;
    i = 0;
    while (p->a_size > 1)
    {
        k = p->ari[0];
        while (i != p->a_size)
        {
            if (k > p->ari[i])
            {
                k = p->ari[i];
                continue;
            }
            i++;
        }
        i = 0;
        if (p->ari[0] == k)
            pb(p);
        else
            ra(p);
        if (p->a_size == 1)
            break;
    }
    while (p->b_size > 0)
    {
        pa(p);
    }
    return(1);
}
void sortmid(p_list *p)
{
    int i;
    i = 0;
    while (i < p->mlen)
    {
        if ((p->ari[0] == p->min) || (p->ari[0] == p->max))
            ra(p);
        else
        {
            pb(p);
            if (p->bri[0] > p->mid)
                rb(p);
        }
        i++;
    }
    if (p->ari[0] < p->ari[1])
        ra(p);
    pa(p);
    printf("sortmidok\n");
    return;
}
 void rbcount(p_list *p)
 {
     int c;
     int b;
     c = 0;

     while (c < (p->b_size/2))
     {
         p->rbops[c] = c;
         c++;
     }
     b = c;
     if (p->b_size % 2 != 0)
     {
         p->rbops[b++] = c;
     }
     while (c >= 1)
     {
         p->rbops[b] = c;
         b++;
         c--;
     }
 }

 void racount(p_list *p)
 {
	int curr_min;
	int i;
	int j;
	int med;
	int curr_in;
	int n;

	j = 0;
	n = 0;
    while (j < p->b_size)
    {
		curr_min = p->min;
    	i = 0;
    	while (i < p->a_size)
		{
    		if (p->ari[i] < p->bri[j])
			{
    			if (p->ari[i] >= curr_min)
    			{
					curr_min = p->ari[i];
					curr_in = i;
					p->check_point[n] = i;
				}
			}
    		i++;
		}
    	med = (p->a_size - 1) / 2;
    	if (curr_in < med)
    		p->sumops[n] = curr_in + 1 + p->rbops[n];
    	else if (curr_in >= med)
    		p->sumops[n] = (i - 1) - curr_in + p->rbops[n];
//    	else if (curr_in == med)
//		{
//    		if ((i - 1) % 2 == 0)
//				p->sumops[n] = curr_in + 1 + p->rbops[n];
//			else
//				p->sumops[n] = (i - 1) - curr_in + p->rbops[n];
//		}
		n++;
    	j++;
    }
 }

 int min_operation(p_list *p)
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

void	rb_ops(p_list *p)
{
	int med;
	//int i;
	//int j;

	//i = p->rbops[p->min_op_in];
	//j = p->sumops[p->min_op_in];
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
void	final_sort(p_list *p)
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
void	ra_ops(p_list *p)
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
int sort5(p_list *p)
{
    pb(p);
    pb(p);
    sort3(p);
    return 1;
}
int main (int argc, char** argv)
{
    p_list p;
    int i;
    int *iters;
    int iter;
    int *v;
    int *mmm;
    int n = 0; //FOR TEST
    p.print = 1;
    i = 1;
    if(!(iters = (int*)malloc(sizeof(int) * (argc-1))))
        return(0);
    if(!(p.ari = (int *)malloc(sizeof(int) * (argc-1))))
        return(0);
    if(!(p.bri = (int *)malloc(sizeof(int) * (argc-1))))
        return(0);
    if(!(v = (int *)malloc(sizeof(int) * (argc - 1))))
        return(0);
    if (!(p.rbops = (int *)ft_memalloc(sizeof(int)*(argc + 1))))
        return(0);
    if (!(p.sumops = (int *)ft_memalloc(sizeof(int)*(argc + 1))))
        return(0);
	if (!(p.check_point = (int *)ft_memalloc(sizeof(int)*(argc + 1))))
		return(0);
    p.mlen = (argc-1); //massive len
    p.a_size = p.mlen;
    p.b_size = 0;
    while (i < argc)
    {
        v[i-1] = atoi(argv[i]);
        p.ari[i-1] = atoi(argv[i]);
        i++;
    }
    ssort(v,p.mlen);
    p.min = v[0];
    p.max = v[p.a_size-1];
    p.mid = v[(p.a_size-1)/2];
    //priv(v,p.mlen);
    if (p.a_size == 3)
    {
        sort3(&p);
    }
    if (p.a_size == 5)
    {
        sort5(&p);
    }
    sortmid(&p);
    while (p.b_size > 0)
	{
		rbcount(&p);
		racount(&p);
		p.min_op_in = min_operation(&p);
    	rb_ops(&p);
    	ra_ops(&p);
	}
    final_sort(&p);
//    printf("bsize = %d \n", p.b_size);
//    while (n < 5)
//    {
//        printf("%d",p.sumops[n]);
//        n++;
//    }
    return(0);
} 