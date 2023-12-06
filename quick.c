#include <stdio.h>
#include <stdlib.h>

void accept(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}
void display(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)

    {
        printf("%d\t", a[i]);
    }
    printf("\n");
}
int partition(int a[], int lb, int ub)
{
    int up, dn, temp, pivot;
    up = ub;
    dn = lb + 1;
    pivot = a[lb];
    do
    {
        while ((a[dn] < pivot) && (dn <= ub))
        {
            dn++;
        }
        while ((a[up] > pivot) && (dn > lb))
        {
            up--;
        }
        if (dn < up)
        {
            temp = a[dn];
            a[dn] = a[up];
            a[up] = temp;
        }
    } while (dn < up);
    a[lb] = a[up];
    a[up] = pivot;

    return up;
}
void quick_sort(int a[], int lb, int ub)
{
    int j;
    if (lb < ub)
    {
        j = partition(a, lb, ub);
        quick_sort(a, lb, j - 1);
        quick_sort(a, j + 1, ub);
    }
}
int main()
{
    int a[20], n;
    printf("How many elements\n");
    scanf("%d", &n);
    printf("Enter the Elements\n");
    accept(a, n);
    printf("The array element\n");
    display(a, n);
    printf("Sorted Elements\n");
    quick_sort(a, 0, n - 1);
    display(a, n);
}