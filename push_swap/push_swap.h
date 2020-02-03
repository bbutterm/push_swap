//header

#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"
#include "ft_printf.h"
typedef struct s_vlist
{
    int weight;
    int num;
    struct s_vlist *next;
}              v_list;
typedef struct s_glist
{
    int *ari; // stack a
    int *bri; // stack b
    int mlen; //massive len
    int print;
    int min;
    int flags;
    int *v;
    int *rbops;
    int *sumops;
    int *check_point;
    int ops;
    int mid;
    int max; //mmm values
    int a_size;
    int b_size;
    int min_op_in;
    v_list *vis;
}               p_list;
