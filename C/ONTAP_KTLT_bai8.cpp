#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string>
#include <string.h>
#include <ctime>
#include <stdlib.h>

struct SP{
    char maSP[10];
    char ten[20];
    int sl;
    int gia;
    char nsx[20];
    char loaiSP[20];
};


void input_1(SP &sp)
{
    printf("Nhap ma SP: ");
    fflush(stdin);
    gets(sp.maSP);
    printf("Nhap ten SP: ");
    fflush(stdin);
    gets(sp.ten);
    printf("Nhap so luong: ");
    scanf("%d",&sp.sl);
    printf("Nhap gia: ");
    scanf("%d",&sp.gia);
    printf("Nhap NSX: ");
    fflush(stdin);
    gets(sp.nsx);
    printf("Nhap loai SP: ");
    fflush(stdin);
    gets(sp.loaiSP);
}

void input(SP a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("Nhap thong tin san pham thu %d:\n",i+1);
        input_1(a[i]);
    }
}

void output_1(SP sp)
{
    printf("Ma SP: %s\n",sp.maSP);
    printf("Ten SP: %s\n",sp.ten);
    printf("So luong: %d\n",sp.sl);
    printf("Gia: %d\n",sp.gia);
    printf("NSX: %s\n",sp.nsx);
    printf("Loai SP: %s\n",sp.loaiSP);
}

void output(SP a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("Thong tin san pham thu %d:\n",i+1);
        output_1(a[i]);
    }
}

void xuat_Laneige(SP a[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(strcmp(a[i].nsx,"Laneige")==0)
        {
            output_1(a[i]);
        }
    }
}

// Tính tổng số lượng các sản phẩm có tên bắt đầu bằng chữ Kem
int tong_SL(SP a[],int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        if(strncmp(a[i].ten,"Kem",3)==0)
        {
            sum+=a[i].sl;
        }
    }
    return sum;
}

int tim_max_dg(SP sp[],int n)
{
    int max=sp[0].gia;
    int vt=0;
    for(int i=1;i<n;i++)
    {
        if(sp[i].gia>max)
        {
            max=sp[i].gia;
            vt=i;
        }
    }
    return vt;
}

void swap(SP &a,SP &b)
{
    SP temp=a;
    a=b;
    b=temp;
}

void sapxep_tangdan_MSP(SP a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(strcmp(a[i].maSP,a[j].maSP)>0)
            {
                swap(a[i],a[j]);
            }
        }
    }
}

void xoa(SP a[],int &n,int vt)
{
    for(int i=vt;i<n-1;i++)
    {
        a[i]=a[i+1];
    }
    n--;
}

void xoa_sp_sl0(SP a[],int &n)
{
    for(int i=0;i<n;i++)
    {
        if(a[i].sl==0)
        {
            xoa(a,n,i);
            i--;
        }
    }
}

int dem_Senka(SP a[],int n)
{
    int dem=0;
    for(int i=0;i<n;i++)
    {
        if(strcmp(a[i].nsx,"Senka")==0)
        {
            dem++;
        }
    }
    return dem;
}

int main()
{
    SP a[100];
    int n;
    printf("Nhap so luong san pham: ");
    scanf("%d",&n);
    input(a,n);
    printf("Thong tin cac san pham:\n");
    output(a,n);
    printf("Thong tin cac san pham NSX Laneige:\n");
    xuat_Laneige(a,n);
    printf("Tong so luong cac san pham co ten bat dau bang chu Kem: %d",tong_SL(a,n));
    printf("\nThong tin san pham co gia cao nhat:\n");
    output_1(a[tim_max_dg(a,n)]);
    sapxep_tangdan_MSP(a,n);
    printf("\nThong tin cac san pham sau khi sap xep tang dan theo ma SP:\n");
    output(a,n);
    xoa_sp_sl0(a,n);
    printf("\nThong tin cac san pham sau khi xoa cac san pham co so luong bang 0:\n");
    output(a,n);
    printf("\nSo luong san pham NSX Senka: %d",dem_Senka(a,n));
    getch();
    return 0;
}
