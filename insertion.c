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
void insertion_sort(int a[], int n)
{
    int i , j, temp ;
    for(i=0 ; i < n ; i++)
    {
        temp = a[i];
        for(j=i-1 ; j >= 0 ; j--)
        {
            if(temp < a[j])
            {
               a[j+1]=a[j];
            }   
            else
            {
               break;   
            }  
        }
        a[j+1]=temp;
    }
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
    printf("Sorted array\n");
    //scanf("%d",&key);
    insertion_sort(a,n);
    display(a,n);
}