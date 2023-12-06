#include<stdio.h>
#include<stdlib.h>
//void accept (int , int);
//void display ( int , int);
//void bubble_sort (int , int);
void accept(int a[] , int n)
{
    int i;
    for ( i =  0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
}
void display(int a[], int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
}
void bubble_sort(int a[], int n)
{
    int i , pass ,temp , cnt = 0;
    for(pass=1 ; pass < n ; pass++)
    {
        for(i = 0 ; i <= n-pass-1 ; i++)
        {
            if(a[i] > a[i+1])
            {
               cnt++ ;
               temp = a[i];
               a[i] = a[i+1];
               a[i+1] = temp;        
            }
        }
    }
    printf("Comprision count is : %d \n",cnt++);
}
int main()
{
    int a[100],n;
    printf("How many elements\n");
    scanf("%d",&n);
    printf("Enter the Elements\n");
    accept(a,n);
    printf("The array element\n");
    display(a,n);
    //printf("Sorted array\n");
    //scanf("%d",&key);
    bubble_sort(a,n);
    display(a,n);
}