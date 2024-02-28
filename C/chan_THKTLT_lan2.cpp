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

int dem_so_luong_phan_biet(int a[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        int j;
        for (j = 0; j < i; j++) {
            if (a[i] == a[j]) {
                break;
            }
        }
        if (i == j) {
            ++count;
        }
    }
    return count;
}


void cau1()
{
    int a[100], n;
    int lc2;
    printf("\nNhap so phan tu cua mang a: ");
    scanf("%d", &n);
    input(a, n);
    do{
        system("cls");
        printf("\n1. Dem so luong phan tu phan biet trong mang A");
        printf("\n2. Dem so phan tu cung xuat hien trong ca 2 mang");
        printf("\nVui long nhap lua chon: ");
        scanf("%d", &lc2);
        switch (lc2)
        {
            case 1:
            {
                printf("\nSo luong phan tu phan biet trong mang A la: %d", dem_so_luong_phan_biet(a,n));
                system("pause");
                break;
            }
            case 2:
            {
                
                system("pause");
                break;
            }
        }
    }while(lc2!=0);
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
			
			system("pause");
			break;
		}
		case 3:
		{
			
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