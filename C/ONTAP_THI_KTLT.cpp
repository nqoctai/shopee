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
       printf("Nhap a[%d] = ",i);
        scanf("%d",a+i);
    }
}

void nhapmang_contro_random(int *&a,int &n)
{
    printf("Nhap so phan tu cua mang: ");
    scanf("%d",&n);
    a = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
       *(a+i) = rand()%100;
    }
}

void xuatmang_contro(int *a,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d\t",*(a+i));
    }
}

int ktsnt(int a)
{
    if(a<2)
    {
        return 0;
    }   
    for(int i=2;i<a/2;i++)
    {
        if(a%i==0)
        {
            return 0;
        }
    }
    return 1;
}

void xuat_songuyen_snt(int *a,int n)
{
    for(int i=0;i<n;i++)
    {
        if(ktsnt(*(a+i))==1)
        {
            printf("%d\t",*(a+i));
        }
    }
}

int main()
{
    int *a,n;
    nhapmang_contro_random(a,n);
    xuatmang_contro(a,n);
    xuat_songuyen_snt(a,n);
    getch();
}