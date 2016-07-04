#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//0 sa 1 sb 2 ss 3 pa 4 pb 5 ra 6 rb 7 rr 8 rra 9 rrb 10 rrr
void    rra(int *a, int t);//rra rrb


void	ft_sa(int *a, int y, int x)//sa sb
{//0 1
	int		t;

    if (a[0] == 3)
    {
        t = a[y];
        a[y] = a[x];
        a[x] = t;
    }
}

void	ft_ss(int *b, int *a)//ss
{//0 1
    ft_sa(a, 1, 2);
    ft_sa(b, 1, 2);
}
void    ft_pa(int *a, int *b)
{
    int     x;
    int     t;

    if (a[0] != 1)
    {
        t = a[1];
        x = 0;
        b[0] += 0;
        while (++x < a[0])
            a[x] = a[x + 1];
        a[0] -= 1;
        b[0] += 1;
        b[b[0] - 1] = t;
        rra(b, b[b[0] - 1]);
    }
}

void    ra(int *a, int t)//ra rb
{
    int     x;

    x = 1;
    while (++x < a[0])
        a[x - 1] = a[x];
    a[x - 1] = t;
}

void    rr(int *a, int *b)
{
    ra(a, a[1]);
    ra(b, b[1]);
}

void    rra(int *a, int t)//rra rrb
{
    int     x;

    x = a[0];
    while (--x > 0)
        a[x] = a[x - 1];
    a[1] = t;
}

void    rrr(int *a, int *b)//rrr
{
    rra(a, a[a[0] - 1]);
    rra(b, b[b[0] - 1]);
}

void    ft_st(int *b, int *a, int n)
{
    if (n == 0)
    {
        ft_sa(a, 1, 2);
        printf("sa ");
    }
    if (n == 1)
    {
        ft_sa(b, 1, 2);//sb
        printf("sb ");
    }
    if (n == 2)
    {
        ft_ss(a, b);
        printf("ss ");
    }
    if (n == 3)
    {
        ft_pa(b, a);//pa
        printf("pa ");
    }
    if (n == 4)
    {
        ft_pa(a, b);//pb
        printf("pb ");
    }
    if (n == 5)
    {
        ra(a, a[1]);
        printf("ra ");
    }
    if (n == 6)
    {
        ra(b, b[1]);//rb
        printf("rb ");
    }
    if (n == 7)
    {
        rr(a, b);
        printf("rr ");
    }
    if (n == 8)
    {
        rra(a, a[a[0] - 1]);
        printf("rra ");
    }
    if (n == 9)
    {
        rra(b, b[b[0] - 1]);//rrb
        printf("rrb ");
    }
    if (n == 10)
    {
        rrr(a, b);
        printf("rrr ");
    }
}

void	ft_sort(int c, int *a, int x, int y)
{
    while (++y != c || (++x != c - 1 && (y = x)))
    	ft_sa(a, y, x);
}

int     ft_combcheck(int *comb, int c)
{
    static int  ac;
    int         a[ac];
    int         b[ac];
    static int  *t;
    int         x;
    
    if (c < -1)
        ac = -c;
    if (c == -1)
        t = comb;
    if (c > -1 && (x = -1))
    {
        while (++x < t[0] && (a[x] = t[x]) >= 0)
            b[x] = 0;
        b[0] = 1;
        x = -1;
        while (++x < c)
            ft_st(b, a, comb[x]);
        x = 1;
        while (++x != a[0] && a[0] == ac && a[x - 1] < a[x])
            ;
        if (x == ac)
        {
            printf("\na:\n");
            x = -1;
            while (++x != a[0])
                printf("%d ", a[x]);
            printf("\n");
            exit(0);
        }
        printf("\n");
    }
    return (0);
}

int     ft_comb(int *comb, int c)
{
    int     g;
    int     b;
    int     x;
    int     y;
    int     p;

    g = 0;
    x = 0;
    while (g == 0 && (y = -1))
    {
        b = 0;
        p = c - 1;
        while (comb[p] < 10 && g == 0)
        {
           g = ft_combcheck(comb, c);
            ++comb[p];
        }
        g = ft_combcheck(comb, c);
        while (comb[p] == 10 && (--p > -1) && g == 0)
            ;
        while (++y != c && (comb[y] == 10))//max check
            ;
        if(y == c || g == 1)
            return (0);
        while (p > -1 && b == 0 && (comb[p] += ++b * (comb[p] < 10)))
            p -= 1;
        p += 1;
        while (++p != c && g == 0)
            comb[p] = 0;
    }
    return (g);//g later
}

int    comb_reset(int c)
{
    int     comb[c];
    int     n;

    n = -1;
    while (++n != c)
        comb[n] = 0;
    n = ft_comb(comb, c);
    return (n);
}

void    ft_bruteforce(void)
{
    int     g;
    int     c;

    g = 0;
    c = 0;
    while (g != 1)
    {
        g = comb_reset(++c);
        printf("%d\n", c);
    }
}

int		main(int ac, char **av)
{
	int     x;
	int		n[ac];
    int     b[ac];
    float   o;
    
    x = -1;
    while (++x != 20)
    {
        o = x / 11;
        printf("%f\n", (float)o);
    }
	x = 0;
    n[0] = ac;
	n[1] = atoi(av[1]);
	while (++x * 2 < ac && (n[x * 2] = atoi(av[x * 2])))
		if (x * 2 + 1 < ac && (av[x * 2 + 1]))
			n[x * 2 + 1] = atoi(av[x * 2 + 1]);
    ft_combcheck(n, -1);
    ft_combcheck(0, -ac);
    //ft_bruteforce();//10 current solution
    //ft_sort(ac, n, 1, 1);
    x = -1;
    while (++x != ac)
        b[x] = 0;
    b[0] = 1;
    //ft_st(b, n, 4);ft_st(b, n, 4);ft_st(b, n, 4);//sa
    //ft_st(b, n, 4);
    //ft_st(b, n, 4);
    //ft_st(b, n, 0);
    //ft_st(b, n, 3);//rra
    //ft_st(b, n, 8);//rra
    //ft_st(b, n, 5);//sa
    //ft_st(b, n, 5);//rra
    x = -1;
    while (++x < b[0])
        printf("%d\n", b[x]);
    printf("\na:\n");
    x = -1;
    while (++x < n[0])
		printf("%d\n", n[x]);
	return (0);
}
