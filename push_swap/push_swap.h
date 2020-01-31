//header

#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"
#include "ft_printf.h"
typedef struct s_glist
{
    int *ari; // stack a
    int *bri; // stack b
    int mlen; //massive len
    int print;
    int min;
    int *rbops;
    int *sumops;
    int mid;
    int max; //mmm values
    int a_size;
    int b_size;
}               p_list;
