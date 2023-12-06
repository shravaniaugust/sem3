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

void insertion_sort(emp a[],int n)
{
    int i, j;
    emp key;
    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;

        while (j >= 0 && a[j].age > key.age)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
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

    printf("Sorting with Insertion Sort by Age:\n");
    insertion_sort(e, n);
    writefile(e, n);

    return 0;  
}