#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string>
#include <string.h>
#include <ctime>
#include <stdlib.h>

struct Phanso{
    int tu;
    int mau;
};

void input(Phanso &p)
{
    printf("Nhap tu so: ");
    scanf("%d",&p.tu);
    printf("Nhap mau so: ");
    scanf("%d",&p.mau);
}

void input_random(Phanso a[],int n)
{
    srand(time(NULL));
    for(int i=0;i<n;i++)
    {
        a[i].tu = rand()%100;
        a[i].mau = (rand()%100)*2+1;
    }
}

void output(Phanso p)
{
    printf("%d/%d",p.tu,p.mau);
}

void output_mang(Phanso a[],int n)
{
    for(int i=0;i<n;i++)
    {
        output(a[i]);
        printf("\t");
    }
}

// Rút gọn phân số
// void rutgon(Phanso &p)
// {
//     int a = p.tu;
//     int b = p.mau;
//     while(a!=b)
//     {
//         if(a>b)
//         {
//             a-=b;
//         }
//         else
//         {
//             b-=a;
//         }
//     }
//     p.tu/=a;
//     p.mau/=a;
// }

void rutgon(Phanso &a)
{
    int min;
    if(a.tu>=a.mau)
    {
        min= a.mau;
    }else
    {
        min = a.tu;
    }
    int ucln = 1;
    for(int i=1;i<=min;i++)
    {
        if(a.tu%i==0 && a.mau%i==0)
        {
            ucln = i;
        }
    }
    a.tu/=ucln;
    a.mau/=ucln;
}

void rutgon_mang(Phanso a[],int n)
{
    for(int i=0;i<n;i++)
    {
        rutgon(a[i]);
    }
}

void max_mau(Phanso a[],int n)
{
    int max = a[0].mau;
    int vt=0;
    for(int i=1;i<n;i++)
    {
        if(a[i].mau>max)
        {
            max = a[i].mau;
            vt = i;
        }
    }
    printf("\nPhan so co mau lon nhat la: ");
    output(a[vt]);
}

void xoa(Phanso a[],int &n,int vt)
{
    for(int i=vt;i<n-1;i++)
    {
        a[i] = a[i+1];
    }
    n--;
}

void xoa_tu1(Phanso a[],int &n)
{
    for(int i=0;i<n;i++)
    {
        if(a[i].tu==1)
        {
            xoa(a,n,i);
            i--;
        }
    }
}
void swap(Phanso &a,Phanso &b)
{
    Phanso temp = a;
    a = b;
    b = temp;
}
void InterchangeSort(Phanso a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if((float)a[i].tu/a[i].mau>(float)a[j].tu/a[j].mau)
            {
                swap(a[i],a[j]);
            }
        }
    }
}

void SelectionSort(Phanso a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if((float)a[j].tu/a[j].mau<(float)a[min].tu/a[min].mau)
            {
                min = j;
            }
        }
        swap(a[i],a[min]);
    }
}

void QuickSort(Phanso a[],int left,int right)
{
    int i = left;
    int j = right;
    int mid = (left+right)/2;
    float x = (float)a[mid].tu/a[mid].mau;
    do
    {
        while((float)a[i].tu/a[i].mau<x)
        {
            i++;
        }
        while((float)a[j].tu/a[j].mau>x)
        {
            j--;
        }
        if(i<=j)
        {
            swap(a[i],a[j]);
            i++;
            j--;
        }
    } while (i<=j);
    if(left<j)
    {
        QuickSort(a,left,j);
    }
    if(i<right)
    {
        QuickSort(a,i,right);
    }
    
}

int dem_phantu_behon1(Phanso a[],int n)
{
    int dem=0;
    for(int i=0;i<n;i++)
    {
        if((float)a[i].tu/a[i].mau<1)
        {
            dem++;
        }
    }
    return dem;
}

float sum(Phanso a[],int n)
{
    float sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=(float)a[i].tu/a[i].mau;
    }
    return sum;
}

float tich(Phanso a[],int n)
{
    float tich=1;
    for(int i=0;i<n;i++)
    {
        tich*=(float)a[i].tu/a[i].mau;
    }
    return tich;
}

void them_x(Phanso a[],int &n,int vt,Phanso x)
{
    for(int i=n;i>vt;i--)
    {
        a[i] = a[i-1];
    }
    a[vt] = x;
    n++;
}

void them_x_truoccucdai(Phanso a[],int &n)
{
    printf("\nNhap phan so can them: ");
    Phanso x;
    input(x);
    if((float)a[0].tu/a[0].mau>(float)a[1].tu/a[1].mau)
    {
        them_x(a,n,0,x);
    }
    if((float)a[n-1].tu/a[n-1].mau>(float)a[n-2].tu/a[n-2].mau)
    {
        them_x(a,n,n-1,x);
    }
    for(int i=1;i<n-1;i++)
    {
        if(float(a[i].tu)/a[i].mau>float(a[i-1].tu)/a[i-1].mau && float(a[i].tu)/a[i].mau>float(a[i+1].tu)/a[i+1].mau)
        { 
            them_x(a,n,i,x);
            i++;
        }
    }
}

void xoa_cuctieu(Phanso a[],int &n)
{
    if((float)a[0].tu/a[0].mau<(float)a[1].tu/a[1].mau)
    {
        xoa(a,n,0);
    }
    if((float)a[n-1].tu/a[n-1].mau<(float)a[n-2].tu/a[n-2].mau)
    {
        xoa(a,n,n-1);
    }
    for(int i=1;i<n;i++)
    {
        if(float(a[i].tu)/a[i].mau<float(a[i-1].tu)/a[i-1].mau && float(a[i].tu)/a[i].mau<float(a[i+1].tu)/a[i+1].mau)
        {
            xoa(a,n,i);
            i--;
        }
    }
}

int main()
{
    int n;
    printf("Nhap so luong phan so: ");
    scanf("%d",&n);
    Phanso a[100];
    input_random(a,n);
    output_mang(a,n);
    rutgon_mang(a,n);
    printf("\nMang sau khi rut gon: ");
    output_mang(a,n);
    max_mau(a,n);
    xoa_tu1(a,n);
    printf("\nMang sau khi xoa phan so tu 1: ");
    output_mang(a,n);
    InterchangeSort(a,n);
    // SelectionSort(a,n);
    // QuickSort(a,0,n-1);
    printf("\nMang sau khi sap xep: ");
    output_mang(a,n);
    printf("\nSo luong phan so be hon 1 la: %d",dem_phantu_behon1(a,n));
    printf("\nTong cac phan so la: %f",sum(a,n));
    printf("\nTich cac phan so la: %f",tich(a,n));
    them_x_truoccucdai(a,n);
    printf("\nMang sau khi them phan so truoc cuc dai la:\n ");
    output_mang(a,n);
    xoa_cuctieu(a,n);
    printf("\nMang sau khi xoa phan so cuc tieu la:\n ");
    output_mang(a,n);
    getch();
    return 0;
}