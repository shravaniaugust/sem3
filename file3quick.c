#include <stdio.h>
#include <string.h>


typedef struct employee
{
    int age;
    char name[20];
} emp;

emp e[10];

void swap(emp *a, emp *b)
{
    emp temp = *a;
    *a = *b;
    *b = temp;
}


int readfile(emp a[])
{
    int i = 0;
    FILE *fp;
    fp = fopen("e.txt", "r");
    if (fp == NULL)
    {
        printf("File is not found\n");
    }
    else
    {
        while (fscanf(fp, "%d %s", &a[i].age, a[i].name) == 2)
        {
            i++;
        }
        fclose(fp); // Close the file after reading.
    }
    return i;
}

void writefile(emp a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d\t%s\n", a[i].age, a[i].name);
    }
}

int partition(emp a[], int low, int high)
{
    int pivot_age = a[high].age;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (a[j].age < pivot_age)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[high]);
    return (i + 1);
}

void quick_sort(emp a[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(a, low, high);

        quick_sort(a, low, pi - 1);
        quick_sort(a, pi + 1, high);
    }
}


int main()
{
    int n;
    printf("The contents of the file are:\n");
    n = readfile(e);
    writefile(e, n);
    /*
    emp key;
    printf("The contents of file are:\n");
    n=readfile(e);
    writefile(e,n);
    printf("Enter Age To Search \n");
    scanf("%d",&key.age);
    insertion_sort(e,n); */

    printf("Sorting with Quick Sort by Age:\n");
    quick_sort(e,0, n-1);
    writefile(e, n);

    return 0;  
}