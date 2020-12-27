#include <stdio.h>

void merge_sort(unsigned int a[], int p, int r);
void print_array(char *s, unsigned int a[], unsigned int len);

int main()
{
    int a[] = {5,2,4,6,1,3} ;
    int len = sizeof(a)/sizeof(int); 
    print_array("Before:", a, len);
    merge_sort(a, 0, len+1);
    print_array("After:", a, len);
}

void print_array(char *s, unsigned int a[], unsigned int len)
{
    printf("%s ", s);
    for(int i=0; i<len; i++)
        printf("%d,", a[i]);
    printf("\n");
}

void merge(unsigned int a[], int p, int q, int r)
{
    unsigned int L[20], R[20];
    int n1 = q - p ;
    int n2 = r - q;
    int i,j,k;
    printf("pqr: %d %d %d\n", p, q, r); 
    print_array("AFTER --> in merge: ", a,r+1);

    //print_array("BEFORE --> in merge: ", a,r);
    for(i=0; i<n1; i++)
        L[i] = a[p+i]; 
    L[n1] = 0xFFFFFFFF;

    for(i=0; i<n2; i++)
        R[i] = a[q+i]; 
    R[n2] = 0xFFFFFFFF;
    print_array("IN --> in merge: ", L,n1);
    print_array("IN --> in merge: ", R,n2);

    i = j = 0;
    for(k=p; k<r; k++)
    {
        if(L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
    }
    print_array("AFTER --> in merge: ", a,r+1);
}

void _merge_sort(unsigned int a[], int p, int r)
{

            merge(a,4,5,6);

}
void merge_sort(unsigned int a[], int p, int r)
{
    int q; 
    if(p < r)
    {
        q = (p + r)/2;
        //printf("m_sort  LEFT: %d %d %d\n", p,q,r);
        merge_sort(a,p,q);
        //printf("m_sort RIGHT: %d %d %d\n", p,q,r);
        merge_sort(a,q+1,r);
        printf("m_sort BACK: %d %d %d\n", p,q,r);
        print_array("-->",a,6);
        merge(a,p,q,r);
    }
}