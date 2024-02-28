#define _CTR_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string>
#include <string.h>
#include <ctime>
#include <stdlib.h>
#include <iostream>

using namespace std;

// Nhap xuat mang 1 chieu so nguyen
void nhapM1C_SoNguyen(int a[], int& n)
{

		printf("\nNhap so phan tu cua mang : ");
		scanf_s("%d", &n);
		for (int i = 0; i < n; i++)
		{
			printf("\nNhap phan tu thu %d: ", i);
			scanf_s("%d", &a[i]);
		}
}

void nhapM1C_SoNguyen_Auto(int a[], int& n)
{
	do{
		printf("\nNhap so phan tu muon tao ngau nhien (n>=15): ");
		scanf_s("%d", &n);
		for (int i = 0; i < n; i++)
		{
			a[i] = rand() % 100;
		}
	} while (n < 15);
}

void xuatM1C_SoNguyen(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("\nPhan tu thu %d co gia tri %d ",i,a[i]);

	}
}

void nhapM1C_SoNguyen_ToanChan(int a[], int& n)
{
	do{
		printf("\nNhap so phan tu muon tao ngau nhien (n>=15): ");
		scanf_s("%d", &n);
		for (int i = 0; i < n; i++)
		{
			a[i] = rand() % 100;
			while (a[i] % 2 != 0)
				a[i] = rand() % 100;
		}
	} while (n < 15);
}

int LinearSearch(int a[], int n, int &x)
{
	printf("\nNhap phan tu can tim: ");
	scanf("%d", &x);
	int vt = -1;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x)
			vt = i;
	}
	return vt;
}


void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void InterchangeSort_TangDan(int a[], int n)
{
	for (int i = 0; i < n-1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i]>a[j])
				swap(a[i], a[j]);
}

void InterchangeSort_GiamDan(int a[], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i]<a[j])
				swap(a[i], a[j]);
		}
	}
}


int BinarySearch(int a[], int n, int &x,int l,int r)
{
	if (r >= l)
	{
		int m = (l + r) / 2;
		if (a[m] == x)
			return m;
		if (a[m] > x)
			return BinarySearch(a, n, x, l,  m - 1);
		if (a[m] < x)
			return BinarySearch(a, n, x, m + 1,  r);
	}
	return -1;
}

// SelectionSort
void SelectionSort(int a[], int n)
{
    int min;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i+1; j < n; j++)
        {
            if (a[j] < a[min])
                min = j;
        }
        swap(a[i], a[min]);
    }
}

// QuickSort
void QuickSort(int a[], int left, int right)
{
    int i = left;
    int j = right;
    int pivot = a[(left + right) / 2];
    while (i <= j)
    {
        while (a[i] < pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (left < j)
        QuickSort(a, left, j);
    if (i < right)
        QuickSort(a, i, right);
}

// Kiểm tra số nguyên tố
int ktsnt(int n)
{
    if(n<2)
        return 0;
    for(int i=2;i<=n/2;i++)
    {
        if(n%i==0)
            return 0;
    }
    return 1;
}

void lksnt_nhohonn(int a[],int n, int &x)
{
    printf("\nNhap so nguyen duong x: ");
    scanf("%d",&x);
    bool flag = false; // biến kiểm tra có số nguyên tố nhỏ hơn x hay không
    for(int i=0;i<n;i++)
    {
        if(a[i]<x && ktsnt(a[i])==1)
        {
            printf("%d ",a[i]);
            flag = true;
        }
    }
    if(!flag)
    {
        printf("\nKhong co so nguyen to nao nho hon %d trong mang.", x);
    }
}

int sum_fisrt_le(int a[], int n)
{
	int temp;
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        temp = a[i];
        while(temp>=10)
        {
           temp/= 10;
        }
        if(temp%2!=0)
            sum += a[i];
    }
    return sum;
}

// Liệt kê số lần xuất hiện của các phần tử trong mảng
void lietke(int a[], int n)
{
    int b[100];
    int dem = 0;
    for(int i=0;i<n;i++)
    {
        int flag = 0;
        for(int j=0;j<dem;j++)
        {
            if(a[i]==b[j])
            {
                flag = 1;
                break;
            }
        }
        if(flag==0)
        {
            b[dem] = a[i];
            dem++;
        }
    }
    for(int i=0;i<dem;i++)
    {
        int count = 0;
        for(int j=0;j<n;j++)
        {
            if(b[i]==a[j])
                count++;
        }
        printf("\nPhan tu %d xuat hien %d lan",b[i],count);
    }
}

/* void Sapxep_chantang_legiam(int a[],int n)
{
	int c[100];
	int b[100];
	int demc = 0;
	for(int i=0;i<n;i++)
	{
		if(a[i]%2==0)
		{
			b[demc] = a[i];
			demc++;
		}
	}
	for(int i=0;i<demc-1;i++)
	{
		for(int j=i+1;j<demc;j++)
		{
			if(b[i]>b[j])
				swap(b[i],b[j]);
		}
	}
	for(int i=0;i<demc;i++)
	{
		printf("%d ",b[i]);
	}
	int deml = 0;
	for(int i=0;i<n;i++)
	{
		if(a[i]%2!=0)
		{
			c[deml] = a[i];
			deml++;
		}
	}
	for(int i=0;i<deml-1;i++)
	{
		for(int j=i+1;j<deml;j++)
		{
			if(c[i]<c[j])
				swap(c[i],c[j]);
		}
	}
	for(int i=0;i<deml;i++)
	{
		printf("%d ",c[i]);
	}

} */

void Sapxep_chantang_legiam(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		if(a[i]%2!=0)
		{
			for(int j=i+1;j<n;j++)
			{
				if(a[j]%2!=0 && a[i]<a[j])
					swap(a[i],a[j]);
			}
		}
		else
		{
			for(int j=i+1;j<n;j++)
			{
				if(a[j]%2==0 && a[i]>a[j])
					swap(a[i],a[j]);
			}
		}
	}
}

void daycon_giamdainhat(int a[],int n)
{
	int result[100]; // Mảng kết quả chứa dãy con giảm dần dài nhất
    int maxLength = 1; // Độ dài dãy con giảm dần dài nhất
    int currentLength = 1; // Độ dài dãy con giảm dần tạm thời
    int endIndex = 0; // Chỉ số cuối cùng của dãy con giảm dần dài nhất
    int currentEndIndex = 0; // Chỉ số cuối cùng của dãy con giảm dần tạm thời

    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            currentLength++;
            currentEndIndex = i;
        } else {
            if (currentLength > maxLength) {
                maxLength = currentLength;
                endIndex = currentEndIndex;
            }
            currentLength = 1;
        }
    }

    // Kiểm tra xem dãy con cuối cùng có lớn hơn dãy con tốt nhất không
    if (currentLength > maxLength) {
        maxLength = currentLength;
        endIndex = currentEndIndex;
    }

    // Sao chép dãy con giảm dần dài nhất vào mảng kết quả
    for (int i = 0; i < maxLength; i++) {
        result[i] = a[endIndex - maxLength + 1 + i];
    }

	// In kết quả
	printf("\nDay con giam dan dai nhat la: ");
	for (int i = 0; i < maxLength; i++) {
		printf("%d ", result[i]);
	}
}

void timchuso_xtronga(int a[],int n, int &x)
{
	printf("\nNhap so nguyen duong x: ");
	scanf("%d",&x);
	int temp_songuyen = x/10;
	int temp_du = x%10;
	int flag = 0;
	for(int i=0;i<n;i++)
	{
		int try_nguyen = 0;
		int try_du = 0;
		int temp = a[i];
		int temp_chuso;
		while(temp>10)
		{
			temp_chuso = temp % 10;
			if(temp_chuso==temp_songuyen)
				try_nguyen = 1;
			if(temp_chuso==temp_du)
				try_du = 1;
			temp = temp / 10;
		}
		if(try_nguyen ==1 && try_du ==1)
		{
			printf("%d ",a[i]);
			flag = 1;
		}
	}
	if(flag == 0)
	{
		printf("\nKhong co phan tu nao chua cac chu so cua %d",x);
	}
}

void Sapxep_chantang_legiunguyen(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		if(a[i]%2==0)
		{
			for(int j=i+1;j<n;j++)
			{
				if(a[j]%2==0 && a[i]>a[j])
					swap(a[i],a[j]);
			}
		}
	}
}

void Sapxep_ledau_chancuoi(int a[],int n)
{

	int c[100];
	int b[100];
	int demc = 0;
	int deml = 0;
	for(int i=0;i<n;i++)
	{
		if(a[i]%2!=0)
		{
			c[deml] = a[i];
			deml++;
		}
	}
	for(int i=0;i<deml;i++)
	{
		printf("%d ",c[i]);
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]%2==0)
		{
			b[demc] = a[i];
			demc++;
		}
	}
	for(int i=0;i<demc;i++)
	{
		printf("%d ",b[i]);
	}
}

void Bai01_THTL()
{
	int a[100], b[100], n;
	int lc;
	do
	{
		system("cls");
		printf("\n========================================================MENU==========================================================");
		printf("\n1. Tao mang mot chieu ngau nhien co phan tu lon hon 15");
		printf("\n2. Tao mang chua toan so chan");
		printf("\n3. Tim kiem x trong mang");
		printf("\n4. Sap xep InterchangeSort");
		printf("\n5. Tim kiem BinarySearch");
		printf("\n6. Tim kiem SelectionSort");
        printf("\n7. Tim kiem QuickSort");
        // BTVN
        printf("\n8. Liet ke so nguyen to nho hon x trong mang");
		printf("\n9. Tinh tong cac so co chu so dau tien la so le");
		printf("\n10. Liet ke so lan xuat hien cua phan tu trong mang");
		printf("\n11. Sap xep mang co so chan tang dan, so le giam dan");
		printf("\n12. Tim day con giam dan dai nhat trong mang"); 
		printf("\n13. Cho x la so co 2 chu so. Tim trong a phan tu co chua cac chu so cua x");
		printf("\n14. Sap xep mang co so chan tang dan, so le giu nguyen vi tri");
		printf("\n15. Sap xep mang: so le o dau mang, so chan o cuoi mang");
		printf("\n20. Nhap mang mot chieu");
		printf("\n21. Xuat mang mot chieu");	
		printf("\nVui long nhap lua chon: ");
		scanf("%d", &lc);
		switch (lc)
		{
		case 1:
		{
				  nhapM1C_SoNguyen_Auto(a, n);
				  xuatM1C_SoNguyen(a, n);
				  system("pause");
				  break;
		}
		case 2:
		{
				  nhapM1C_SoNguyen_ToanChan(b, n);
				  xuatM1C_SoNguyen(b, n);
				  system("pause");
				  break;
		}
		case 3:
		{
				  int x;
				  int vt=LinearSearch(a, n, x);
				  if (vt != -1)
				  {
					  printf("\nVi tri cua %d la : %d ",x, vt);
				  }
				  else
				  {
					  printf("\nKhong tim thay x trong mang");
				  }
				  system("pause");
				  break;
		}
		case 4:
		{
				  int lc1;
				  printf("\n1. Sap xep tang dan");
				  printf("\n2. Sap xep giam dan");
				  printf("\nVui long nhap lua chon: ");
				  scanf("%d", &lc1);
                  switch (lc1)
				  {
				  case 1:
				  {
							InterchangeSort_TangDan(a, n);
							break;
				  }
				  case 2:
				  {
							InterchangeSort_GiamDan(a, n);
							break;
				  }
				  }
				  system("pause");
				  break;
		}
		case 5:
		{
				  int l = 1;
				  int r = n;
				  int x, vt;
				  InterchangeSort_TangDan(a, n);
				  printf("Nhap phan tu muon tim: ");
				  scanf("%d", &x);
				  vt=BinarySearch(a, n, x,l,r);
				  if (vt != -1)
					  printf("Vi tri cua %d la: %d", x, vt);
				  else
					  printf("Khong tim thay vi tri cua %d ", x);
				  system("pause");
				  break;
		}
        case 6:
        {
                    SelectionSort(a, n);
                    system("pause");
                    break;
        }
        case 7:
        {
                    QuickSort(a, 0, n - 1);
                    system("pause");
                    break;
        }
        case 8:
        {
                    int x;
                    lksnt_nhohonn(a, n, x);
                    system("pause");
                    break;
        }
        case 9:
        {
                    int sum = sum_fisrt_le(a, n);
                    printf("\nTong cac so co chu so dau tien la so le la: %d", sum);
                    system("pause");
                    break;
        }
		case 10:
		{
			
				   lietke(a, n);
				   system("pause");
				   break;
		}
		case 11:
		{
					Sapxep_chantang_legiam(a, n);
					system("pause");
					break;
		}
		case 12:
		{
					daycon_giamdainhat(a, n);
					system("pause");
					break;
		}
		case 13:
		{
					int x;
					timchuso_xtronga(a, n, x);
					system("pause");
					break;
		}
		case 14:
		{
					Sapxep_chantang_legiunguyen(a, n);
					system("pause");
					break;
		}
		case 15:
		{
					Sapxep_ledau_chancuoi(a, n);
					system("pause");
					break;
		}
		case 20:
		{
				nhapM1C_SoNguyen(a, n);
				system("pause");
				break;
		}
		case 21:
		{
				   xuatM1C_SoNguyen(a, n);
				   system("pause");
				   break;
		}
		default:
			break;
		}
	} while (lc != 0);
}


void Bai01_BTVN()
{
    
}

int main()
{
    Bai01_THTL();
    return 0;
}