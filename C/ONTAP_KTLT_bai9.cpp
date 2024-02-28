#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string>
#include <string.h>
#include <ctime>
#include <stdlib.h>
#include <math.h> 

void input(int a[],int &n)
{
    printf("Nhap n: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Nhap a[%d]: ",i);
        scanf("%d",&a[i]);
    }
}

void output(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}

// TÍnh t?ng ð? quy
int sum_dequy(int a[],int n)
{
    int sum=0;
    if(n==1)
    {
        return a[0];
    }
    else
    {
        return a[n-1]+sum_dequy(a,n-1);
    }
}

int tich_dequy(int a[],int n)
{
    int tich=1;
    if(n==1)
    {
        return a[0];
    }
    else
    {
        return a[n-1]*tich_dequy(a,n-1);
    }
}

int tim_min_dequy(int a[],int n)
{
    if(n==1)
    return a[0];
    else
    {
        if(a[n-1]<tim_min_dequy(a,n-1))
        return a[n-1];
        else
        return tim_min_dequy(a,n-1);
    }
}

// Ð?m ph?n t? dýõng b?ng ð? quy
int dem_duong_dequy(int a[],int n)
{
    if(n==1)
    {
        if(a[0]>0)
        return 1;
        else
        return 0;
    }
    else
    {
        if(a[n-1]>0)
        return 1+dem_duong_dequy(a,n-1);
        else
        return dem_duong_dequy(a,n-1);
    }
}

int sum_sole(int a[],int n)
{
    int sum=0;
    if(n==1)
    {
        if(a[0]%2!=0)
        return a[0];
        else
        return 0;
    }
    else
    {
        if(a[n-1]%2!=0)
        return a[n-1]+sum_sole(a,n-1);
        else
        return sum_sole(a,n-1);
    }
}

int max_dequy(int a[],int n)
{
    if(n==1)
    return a[0];
    else
    {
        if(a[n-1]>max_dequy(a,n-1))
        return a[n-1];
        else
        return max_dequy(a,n-1);
    }
}

int bai7(int n)
{
    if(n==0 || n==1)
    {
        return 2;
    }
    return 2*bai7(n-1)*bai7(n-2);
}

int bai8(int n)
{
    if(n==0)
    return 1;
    if(n==1)
    return 2;
    else
    return 2*bai8(n-1)+4*bai8(n-2);
}

int giaithua(int n)
{
    if(n==0)
    return 1;
    else
    return n*giaithua(n-1);
}

float bai13(int n)
{
    if(n==1)
    {
        return (float)(1*giaithua(2))/(2+sqrt(3));
    }
    else
    {
        return (float)(n*giaithua(n+1))/((n+1)+sqrt(n+2))+ bai13(n-1);
    }
}

float bai14(int n)
{
	
    if(n==1)
    {
        return (float)(1+sqrt(3))/(2+sqrt(giaithua(3)));
    }
    else
    {
        return (float)(n+sqrt(n+n+1))/(n+1+sqrt(giaithua(n+2))) + bai14(n-1);
    }
}


int main()
{
    int a[100],n;
    input(a,n);
    output(a,n);
    printf("\nTong = %d",sum_dequy(a,n));
    printf("\nTich = %d",tich_dequy(a,n));
    printf("\nMin = %d",tim_min_dequy(a,n));
    printf("\nSo luong so duong = %d",dem_duong_dequy(a,n));
    printf("\nTong so le = %d",sum_sole(a,n));
    printf("\nMax = %d",max_dequy(a,n));
    printf("\nBai 7 = %d",bai7(n));
    printf("\nBai 8 = %d",bai8(n));
    
    printf("\nBai 13 = %f",bai13(n));
    printf("\nBai 14 = %f",bai14(n));
    getch();
    return 0;
}