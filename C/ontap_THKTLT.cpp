#define _CTR_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string>
#include <string.h>
#include <ctime>
#include <stdlib.h>

void nhapmang_contro(int *&a,int &n)
{
    printf("Nhap so phan tu cua mang: ");
    scanf("%d",&n);
    a = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
       *(a+i)= rand()*100;
    }
}

void xuatmang_contro(int *a,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d\t",*(a+i));
    }
}

int main()
{
    int *a,n;
    nhapmang_contro(a,n);
    xuatmang_contro(a,n);
    getch();
}