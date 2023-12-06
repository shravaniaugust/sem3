#include<stdio.h>
#include<stdlib.h>
void accept (int a[], int n);
void display ( int a[], int n); 
void binary_search (int a[], int n, int key);
void accept (int a[],int n)
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
void binary_search(int a[],int n, int key);
{
    int lb=0, ub= n-1, mid, flag=0, pos;
    while(lb <= ub)
    {
        mid=(lb+ub)/2;
        if(key < a[mid])
        ub=mid-1;
        else if (key > a[mid])
        lb=mid+1;
        else
        {
            flag=1;
            pos=mid;
            break;
        }
    }
    if(flag == 1)
    {
        printf("Element %d is found at %d \n",key,(pos+1));
    }
    else
    {
        printf("Element not found");
    }
}
int main()
{
    int a[100],n,key;
    printf("How many elements\n");
    scanf("%d",&n);
    printf("Enter the Elements\n");
    accept(a,n);
    printf("The array element\n");
    display(a,n);
    printf("Enter the element you want to search\n");
    scanf("%d",&key);
    binary_search(a,n,key);
}