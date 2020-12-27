#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

unsigned int *kadd(int *x, int *y, int n);

unsigned int kmul(char *x, char *y, int n); 

char *x_str = "5678";
char *y_str = "1234";
void print_array(char *s, unsigned char a[], unsigned int len)
{
    printf("%s ", s);
    for(int i=0; i<len; i++)
        printf("%d,", a[i]);
    printf("\n");
}
int main()
{
    unsigned char *x, *y, *xy;
    unsigned int i;
    unsigned int nx = strlen(x_str);
    unsigned int ny = strlen(y_str);
    unsigned int n_xy;


    x = malloc(n);
    y = malloc(n);
    xy = malloc(2 * n);

    for(i=0; i<n; i++)
    {
        x[i] = x_str[n-i-1] - '0';
        y[i] = y_str[n-i-1] - '0';

    }
    print_array("x:", x, n);
    print_array("y:", y, n);

    kmul(x,nx, y,ny,xy, &n_xy);
    //print_array("xy:", xy, 2*n);


}

#if 1
unsigned int *kadd(int *x, int *y, int n)
{
    int i;
    int xay[128];

    for(i=0;i<n; i--)
    {
        xay[i] = x[i] + y[i] 
    }
    return xay;
}

int dec2arr(unsigned int d,  int *darr)
{
        unsigned char tmp_xy_str[128] = {0};
        int n = sprintf(tmp_xy_str, "%d",d);  
        printf("dec2arr: %d, %s %d\n", d, tmp_xy_str, n) ;
        for(int i=0; i<=n; i++)
            darr[i] = tmp_xy_str[n-i-1] - '0';
        return n;
}

unsigned int kmul(int *x, int nx, int *y, int ny)
{
    char *a, *b; 
    char *c, *d; 
    char ac[128], bd[128];
    char ad[128], bc[128];
    char ac_bc[128];
    unsigned int n_ac, n_bd, n_ad, n_bc;
    int n = min(nx,ny);
    int n1 = n/2;

    if(nx < 2 && ny < 2)
        return(x[0] * y[0]);

  
    b = x; a = x + (n1);
    d = y; c = y + (n1);

    u = kmul(a, nx-n1,  c, ny-n1); 
    w = kmul(b,n1, d, n1);
    v = kmul(kadd(a,b, n1), n1, kadd(c,d,n1), n1) - u - w;


    //printf("n: %d -- xy: %d\n", n, x[0]*y[0]); 
    //print_array("ac:",ac,n1);
    return (u * pow(10.0,n) + v * pow(10.0,n/2) + w);
}
#endif


unsigned int  mul(unsigned int a[], unsigned int b[])
{
    unsigned int u,v,w;
    u = a[0] * b[0];
    w = a[1] * b[1];
    v = (a[1]-a[0]) * (b[1]-b[0]); 

    return (u * 100 + (u+w-v) * 10 + w);
}