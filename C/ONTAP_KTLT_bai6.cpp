#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string>
#include <string.h>
#include <ctime>
#include <stdlib.h>


void input_matranvuong(int a[][100],int &n)
{
    printf("Nhap cap ma tran: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("Nhap a[%d][%d] = ",i,j);
            scanf("%d",&a[i][j]);
        }
    }
}

void swap(int &a,int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Tính tổng các phần tử trên đường chéo chính
int sum_main_diagonal(int a[][100],int n)
{
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i][i];
    }
    return sum;
}

// Tính tổng các phần tử trên đường chéo phụ
int sum_sub_diagonal(int a[][100],int n)
{
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i][n-i-1];
    }
    return sum;
}

// Tính tổng tam giác trên
int sum_upper_triangle(int a[][100],int n)
{
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            sum+=a[i][j];
        }
    }
    return sum;
}

// Tính tổng tam giác dưới
int sum_lower_triangle(int a[][100],int n)
{
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            sum+=a[i][j];
        }
    }
    return sum;
}

void xuat_songsong_dcc(int a[][100],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            continue;
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}

void xuat_songsong_dcp(int a[][100],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i+j==n-1)
            continue;
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}




void output(int a[][100],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}

int tim_min_1dong(int a[][100],int n,int row)
{
    int min = a[row][0];
    for(int i=0;i<n;i++)
    {
        if(a[row][i]<min)
        min = a[row][i];
    }
    return min;
}

int sum_min_dong(int a[][100],int n)
{
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        sum+=tim_min_1dong(a,n,i);
    }
    return sum;
}

int sapxep_ziczac(int a[][100],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(a[i][n-1]>a[i+1][0])
            return 0;  
            if(a[i][j]>a[i][j+1])
            return 0;
        }
    }
    return 1;
}

void sapxep_tangdan_1cot(int a[][100],int n,int col)
{
    for(int i=0;i<n-1;i++)
    {
        if(a[i][col]>a[i+1][col])
        {
            swap(a[i][col],a[i+1][col]);
        }
    }
}

void sapxep_tangdan_theocot(int a[][100],int n)
{
    for(int i=0;i<n;i++)
    {
        sapxep_tangdan_1cot(a,n,i);
    }
}

void sapxep_giamdan_1dong(int a[][100],int n,int row)
{
    for(int i=0;i<n-1;i++)
    {
        if(a[row][i]<a[row][i+1])
        {
            swap(a[row][i],a[row][i+1]);
        }
    }
}

void sapxep_giamdan_theodong(int a[][100],int n)
{
    for(int i=0;i<n;i++)
    {
        sapxep_giamdan_1dong(a,n,i);
    }
}

void sapxep_tangdan_dcc(int a[][100],int n)
{
    for(int i=0;i<n-1;i++)
    {
        if(a[i][i]>a[i+1][i+1])
        {
            swap(a[i][i],a[i+1][i+1]);
        }
    }
}

void xuat_duongbien(int a[][100],int n)
{

}

void In_duong_bien(int m, int n, int a[][100])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i == 0 || i == n-1 || j == 0  || j == n-1 )
			{
				printf("%d ", a[i][j]);
			}
			else
			{
				printf("   ");
			}
		}
		printf("\n");
	}
}

int kt_tangdan_dcc(int a[][100],int n)
{
    for(int i=0;i<n-1;i++)
    {
        if(a[i][i]>a[i+1][i+1])
        return 0;
    }
    return 1;
}



int kt_giamdan_1cot(int a[][100],int n,int col)
{
    for(int i=0;i<n-1;i++)
    {
        if(a[i][col]<a[i+1][col])
        return 0;
    }
    return 1;
}

int kt_giamdan_theocot(int a[][100],int n)
{
    for(int i=0;i<n;i++)
    {
        if(kt_giamdan_1cot(a,n,i)==0)
        return 0;
    }
    return 1;
}


int main()
{
    int a[100][100];
    int n;
    input_matranvuong(a,n);
    output(a,n);
    printf("\nTong duong cheo chinh la: %d",sum_main_diagonal(a,n));
    printf("\nTong duong cheo phu la: %d",sum_sub_diagonal(a,n));
    printf("\nTong tam giac tren la: %d",sum_upper_triangle(a,n));
    printf("\nTong tam giac duoi la: %d",sum_lower_triangle(a,n));
    printf("\nCac phan tu song song duong cheo chinh la:\n ");
    xuat_songsong_dcc(a,n);
    printf("\nCac phan tu song song duong cheo phu la:\n ");
    xuat_songsong_dcp(a,n);
    printf("\nTong cac gia tri nho nhat tren moi dong la: %d",sum_min_dong(a,n));
    if(sapxep_ziczac(a,n)==1)
    printf("\nMa tran da sap xep ziczac");
    else
    printf("\nMa tran chua sap xep ziczac");
    sapxep_tangdan_theocot(a,n);
    printf("\nMa tran sau khi sap xep tang dan theo cot la:\n ");
    output(a,n);
    sapxep_giamdan_theodong(a,n);
    printf("\nMa tran sau khi sap xep giam dan theo dong la:\n ");
    output(a,n);
    sapxep_tangdan_dcc(a,n);
    printf("\nMa tran sau khi sap xep tang dan theo duong cheo chinh la:\n ");
    output(a,n);
    printf("\nXuat duong bien:\n");
    In_duong_bien(n,n,a);
    printf("\nKiem tra duong cheo chinh co tang dan khong: ");
    if(kt_tangdan_dcc(a,n)==1)
    printf("\nCo");
    else
    printf("\nKhong");
    printf("\nKiem tra cac cot co giam dan khong: ");
    if(kt_giamdan_theocot(a,n)==1)
    printf("\nCo");
    else
    printf("\nKhong");
    getch();
    return 0;
}