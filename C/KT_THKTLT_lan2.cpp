#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include<conio.h>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <string>
using namespace std;

void input(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nNhap [%d] = ", i);
        scanf("%d", &a[i]);
    }
}

void output(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
}

int kt_BtrongA(int a[],int n,int b)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==b)
        {
            return 1;
        } 
    }
    return 0;
}

int kt_chanB_trongA(int a[], int n, int b[], int m)
{
    int flag = 0;
    for(int i=0;i<m;i++)
    {
        if(b[i]%2==0)
        {
            if(kt_BtrongA(a,n,b[i])==1)
            {
                flag = 1;
            }
            else
            {
                flag = 0;
                break;
            }
        }
    }
    return flag;
}

int kt_pt_xuathien2mang(int a[],int n,int x)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==x)
        {
            return 1;
        }
    }
    return 0;
}

int dem_pt_xh2mang(int a[],int n, int b[],int m)
{
    int c[100];
    int sl_c=0;
    for(int i=0;i<n;i++)
    {
        if(kt_pt_xuathien2mang(b,m,a[i])==1)
        {
            if(kt_pt_xuathien2mang(c,sl_c,a[i])==0)
            {
                c[sl_c]=a[i];
                sl_c++;
            }
        }
    }
    return sl_c;
}



void cau1()
{
    int a[100], n;
    int b[100], m;
    int lc2;
    printf("\nNhap so phan tu cua mang a: ");
    scanf("%d", &n);
    input(a, n);
    printf("\nNhap so phan tu cua mang b: ");
    scanf("%d", &m);
    input(b, m);
    do{
        system("cls");
        printf("\n1. Kiem tra tat ca cac phan tu chan cua B co nam trong mang A hay khong");
        printf("\n2. Dem so phan tu cung xuat hien trong ca 2 mang");
        printf("\nVui long nhap lua chon: ");
        scanf("%d", &lc2);
        switch (lc2)
        {
            case 1:
            {
                if(kt_chanB_trongA(a,n,b,m)==1)
                {
                    printf("\nTat ca cac phan tu chan cua B nam trong mang A");
                }
                else
                {
                    printf("\nKhong phai tat ca cac phan tu chan cua B nam trong mang A");
                }
                system("pause");
                break;
            }
            case 2:
            {
                printf("\nSo phan tu cung xuat hien trong ca 2 mang la: %d", dem_pt_xh2mang(a,n,b,m));
                system("pause");
                break;
            }
        }
    }while(lc2!=0);
}


void thay_the_chuoiB_trongA(char* a, const char* b) {
    const char* replace = "I LOVE";
    int lenA = strlen(a), lenB = strlen(b), lenReplace = strlen(replace);
   

    for (int i = 0; i <= lenA - lenB; ) {
        int j = 0;
        while (j < lenB && a[i + j] == b[j]) j++; // T?m chu?i b trong a
        if (j == lenB) { // N?u t?m th?y chu?i b
            for (int k = i; k <= lenA - lenB; k++) {
                a[k] = a[k + lenB]; // Xóa chu?i b kh?i a
            }
            lenA -= lenB; // C?p nh?t ð? dài chu?i a
            for (int k = lenA; k >= i; k--) {
                a[k + lenReplace] = a[k]; // D?ch chuy?n ph?n c?n l?i c?a chu?i a
            }
            lenA += lenReplace; // C?p nh?t ð? dài chu?i a
            for (int k = 0; k < lenReplace; k++) {
                a[i + k] = replace[k]; // Thêm chu?i replace vào a
            }
            i += lenReplace; // Ti?p t?c t?m ki?m sau chu?i replace
        } else {
            i++; // N?u không t?m th?y chu?i b, ti?p t?c t?m ki?m
        }
    }
    a[lenA] = '\0'; // K?t thúc chu?i a
}



void xoa_so_trong_chuoi(char* a) {
    int lenA = strlen(a);
    int j = 0;
    for (int i = 0; i < lenA; i++) {
        if (a[i] < '0' || a[i] > '9') { // Nếu a[i] không phải là số
            a[j++] = a[i]; // Giữ lại a[i]
        }
    }
    a[j] = '\0'; // Kết thúc chuỗi a
}



void cau2()
{
    char a[100], b[100];
    int lc3;
    printf("\nNhap chuoi A: ");
    fflush(stdin);
    gets(a);
    printf("\nNhap chuoi B: ");
    fflush(stdin);
    gets(b);
    do{
        system("cls");
        printf("\n1. Chuyen tat ca tu cua chuoi B co trong chuoi A thanh chu I LOVE");
        printf("\n2. Xoa tat ca cac so trong chuoi A");
        printf("\nVui long nhap lua chon: ");
        scanf("%d", &lc3);
        switch (lc3)
        {
            case 1:
            {
                thay_the_chuoiB_trongA(a,b);
                puts(a); 
                system("pause");
                break;
            }
            case 2:
            {
                xoa_so_trong_chuoi(a);
                puts(a);
                system("pause");
                break;
            }
        }
    }while(lc3!=0);
}


int dem_so_luong_de_quy(int arr[], int n, int x) {
    if (n == 0) {
        return 0;
    } else {
        return (arr[n - 1] == x) + dem_so_luong_de_quy(arr, n - 1, x);
    }
}

int dem_so_luong_khu_de_quy(int arr[], int n, int x) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] == x) {
            ++count;
        }
    }
    return count;
}

long long tinh_to_hop(int n, int k) {
    if (k == 0 || k == n) {
        return 1;
    }
    if (k == 1) {
        return n;
    }
    return tinh_to_hop(n - 1, k - 1) + tinh_to_hop(n - 1, k);
}

void cau3()
{
    int lc4;
    do{
        system("cls");
        printf("\n1. Dem so luong x xuat hien trong mang de quy");
        printf("\n2. Tinh to hop cua n va k");
        printf("\nVui long nhap lua chon: ");
        scanf("%d", &lc4);
        switch (lc4)
        {
            case 1:
            {
                int a[100], n, x;
                printf("\nNhap so phan tu cua mang: ");
                scanf("%d", &n);
                input(a, n);
                printf("\nNhap x: ");
                scanf("%d", &x);
                printf("\nSo luong x xuat hien trong mang la: %d", dem_so_luong_de_quy(a,n,x));
                system("pause");
                break;
            }
            case 2:
            {
                int n, k;
                printf("\nNhap n: ");
                scanf("%d", &n);
                printf("\nNhap k: ");
                scanf("%d", &k);
                printf("\nTo hop cua n va k la: %d", tinh_to_hop(n,k));
                system("pause");
                break;
            }
        }
    }while(lc4!=0);
}

int main()
{
    int lc;
	do
	{
		system("cls");
		printf("\n========================================================MENU==========================================================");
		printf("\n1. Cau 1");
		printf("\n2. Cau 2");
		printf("\n3. Cau 3");
		printf("\n0. ");
		printf("\nVui long nhap lua chon: ");
		scanf("%d", &lc);
		switch (lc)
		{
		case 1:
		{
			cau1();
			system("pause");
			break;
		}
		case 2:
		{
			cau2();
			system("pause");
			break;
		}
		case 3:
		{
			cau3();
			system("pause");
			break;
		}
		case 4:
		{
			
			system("pause");
			break;
		}
		default:
			break;
		}
	}while(lc != 0);
}

