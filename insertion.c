#include <stdio.h>

int insertion(unsigned int *a, unsigned int len);
void print_array(char *s, unsigned int a[], unsigned int len);

int main()
{
    int a[] = {5,2,4,6,1,3} ;
    int len = sizeof(a)/sizeof(int); 
    print_array("Before:", a, len);
    insertion(a, len);
    print_array("After:", a, len);
}

int insertion(unsigned int a[], unsigned int len)
{
    int i,j,k;

    for(j=1; j<len; j++)
    {
            k = a[j] ;
            i = j - 1 ; 
            while (i >= 0 && a[i] < k) {
                a[i + 1] = a[i];
                i = i - 1;
            }
            a[i + 1] = k ;
    }
}

void print_array(char *s, unsigned int a[], unsigned int len)
{
    printf("%s\n", s);
    for(int i=0; i<len; i++)
        printf("%d,", a[i]);
    printf("\n");
}