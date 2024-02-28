#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string>
#include <string.h>
#include <ctime>
#include <stdlib.h>


void xuat_fibonaci_doanmn(int m,int n)
{
    int a=0,b=1,c=1;
    while(c<m)
    {
        c = a+b;
        a = b;
        b = c;
    }
    while(c<=n)
    {
        printf("%d\t",c);
        c = a+b;
        a = b;
        b = c;
    }
}

int main()
{
    int m,n;
    printf("Nhap m: ");
    scanf("%d",&m);
    printf("Nhap n: ");
    scanf("%d",&n);
    xuat_fibonaci_doanmn(m,n);
    getch();
    return 0;
}