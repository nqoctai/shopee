#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include<conio.h>
#include <iostream>
#include<stdio.h>
#include<stdlib.h>



void Input(int& n, int& m, int a[][100])
{
	printf("Nhap so hang: ");
	scanf("%d", &m);
	printf("Nhap so cot: ");
	scanf("%d", &n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = (rand() % (90)) + 10;
		}
	}
}

void InputFromKeyBoard(int& n, int& m, int a[][100])
{
	printf("Nhap so dong: ");
	scanf("%d", &m);
	printf("Nhap so cot: ");
	scanf("%d", &n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("a[%d][%d] = ", i, j);
			scanf("%d", &a[i][j]);
		}
	}
}

void Output(int n, int m, int a[][100])
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%2d ", a[i][j]);
		}
		printf("\n");
	}
}

int RowEven(int x, int m, int a[][100])
{
	for (int i = 0; i < m; i++)
	{
		if (a[x][i] % 2 != 0)
		{
			return 0;
		}
	}
	return 1;
}

void RowAllEven(int n,int m,int a[][100])
{
	int check = 0;
	for (int i = 0; i < m; i++)
	{
		if (RowEven(i, m, a) == 1)
		{
			printf("Dong %d co cac phan tu toan chan. \n", i + 1);
			check = 1;
		}
	}
	if (check == 0)
	{
		printf("Ca ma tran ko co dong chua toan so chan. \n");
	}
}

int RowDecrease(int x, int m, int a[][100])
{
	for (int i = 0; i < m - 1; i++)
	{
		if (a[x][i] <= a[x][i+1])
		{
			return 0;
		}
	}
	return 1;
}

void RowMatrixDecrease(int n, int m, int a[][100])
{
	int check = 0;
	for (int i = 0; i < m; i++)
	{
		if (RowDecrease(i, m, a) == 1)
		{
			printf("Dong %d co cac phan tu giam dan. \n", i + 1);
			check = 1;
		}
	}
	if (check == 0)
	{
		printf("Ca ma tran ko co dong giam dan. \n");
	}
}

void mostFrequentElement(int n, int m, int a[][100]) 
{
	int maxCount = 0;  
	int mostFrequent = 0;  
	int maxValue = 0;

	
	int count[100] = { 0 }; 

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			count[a[i][j]]++;
			if (count[a[i][j]] > maxCount) {
				maxCount = count[a[i][j]];
			}
			if (a[i][j] > maxValue)
			{
				maxValue = a[i][j];
			}
		}
	}

	for (int i = 0; i <= maxValue; i++)
	{
		if (count[i] == maxCount)
		{
			printf("%d ",i);
		}
	}
	printf("la phan tu xuat hien nhieu nhat trong ma tran voi so an la: %d \n", maxCount);
}

void Count_Number(int x, int count[])
{
	while (x != 0)
	{
		int temp = x % 10;
		count[temp]++;
		x = x / 10;
	}
}

void Count_Number_In_Matrix(int n, int m, int a[][100])
{
	int count[10] = { 0 };
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			Count_Number(a[i][j], count);
		}
	}
	int max = 0;
	for (int i = 0; i < 10; i++)
	{
		if (count[i] > max)
		{
			max = count[i];
		}
	}
	for (int i = 0; i < 10; i++)
	{
		if (count[i] == max)
		{
			printf("%d ",i);
		}
	}
	printf("la nhung chu so xuat hien nhieu trong ma tran voi so lan la %d. \n", max);
}

int Sum_Collum(int x, int m, int a[][100])
{
	int  sum = 0;
	for (int i = 0; i < m; i++)
	{
		sum += a[i][x];
	}
	return sum;
}

void Sum_Min(int n, int m, int a[][100])
{
	int min = INT_MAX;
	for (int j = 0; j < n; j++)
	{
		if (min > Sum_Collum(j,m,a))
		{
			min = Sum_Collum(j, m, a);
		}
	}

	for (int j = 0; j < n; j++)
	{
		if (min == Sum_Collum(j, m, a))
		{
			printf("%d ",j+1);
		}
	}
	printf("la cot co tong nho nhat la %d \n",min);
}

void Change_Collum(int n, int m, int a[][100])
{
	int x, y;
	printf("Nhap hai cot muon hoan doi: ");
	scanf("%d %d", &x, &y);

	int stemp;
	for (int i = 0; i < m; i++)
	{
		stemp = a[i][x];
		a[i][x] = a[i][y];
		a[i][y] = stemp;
	}
	printf("Ma tra sau khi hoan doi cot: \n");
	Output(n, m, a);
}

void Change_Row(int n, int m, int a[][100])
{
	int x, y;
	printf("Nhap hai dong muon hoan doi: ");
	scanf("%d %d", &x, &y);

	int stemp;
	for (int j = 0; j < n; j++)
	{
		stemp = a[x][j];
		a[x][j] = a[y][j];
		a[y][j] = stemp;
	}
	printf("Ma tra sau khi hoan doi dong: \n");
	Output(n, m, a);
}

int check_sole_1cot(int n,int m, int a[][100])
{
	for (int i = 0; i < n; i++)
	{
		if (a[i][m] % 2 == 0)
		{
			return 0;
		}
	}
	return 1;
}

void check_sole_allcot(int n,int m, int a[][100])
{
    int check = 0;
    for (int i = 0; i < n; i++)
    {
        if (check_sole_1cot(n, i, a) == 1)
        {
            printf("Cot %d co cac phan tu toan so le. \n", i + 1);
            check = 1;
        }
    }
    if (check == 0)
    {
        printf("Ca ma tran ko co cot chua toan so le. \n");
    }

}

// Tìm Max trong các phần tử trên biên ma trận
int Max_bien(int n, int m, int a[][100])
{
	int max = a[0][0];
	for (int i = 0; i < m; i++)
	{
		if (max < a[0][i])
		{
			max = a[0][i];
		}
	}
	for (int i = 0; i < m; i++)
	{
		if (max < a[n - 1][i])
		{
			max = a[n - 1][i];
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (max < a[i][0])
		{
			max = a[i][0];
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (max < a[i][m - 1])
		{
			max = a[i][m - 1];
		}
	}
	return max;
}

// Kiểm tra có số 2 trong các chữ số không
int check_2(int n)
{
	while (n != 0)
	{
		if (n % 10 == 2)
		{
			return 1;
		}
		n = n / 10;
	}
	return 0;
}

// Xuất phần tử chứa số 2 trong các chữ số của nó
void Output_2(int n, int m, int a[][100])
{
	int count = 0;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if (check_2(a[i][j]) == 1)
			{
				count++;
			}
		}
	}
	printf("Co %d phan tu chua chu so 2 trong ma tran. \n", count);
}

// Xuất các phần tử cực tiểu trong ma trận ( phần tử cực tiểu là phần tử nhỏ nhất trong các phần tử xung quanh nó
void print_SuperMin(int m, int n, int a[][100])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i == 0 || i == n - 1 || j == 0 || j == n - 1)
			{
				// Các phần tử ở biên
				if (i == 0 && j == 0)
				{
					if (a[i][j] < a[i][j + 1] && a[i][j] < a[i + 1][j] && a[i][j] < a[i + 1][j + 1])
					{
						printf("%d ", a[i][j]);
					}
				}
				else if (i == 0 && j == m - 1)
				{
					if (a[i][j] < a[i][j - 1] && a[i][j] < a[i + 1][j - 1] && a[i][j] < a[i + 1][j])
					{
						printf("%d ", a[i][j]);
					}
				}
				else if (i == n - 1 && j == 0)
				{
					if (a[i][j] < a[i - 1][j] && a[i][j] < a[i - 1][j + 1] && a[i][j] < a[i][j + 1])
					{
						printf("%d ", a[i][j]);
					}
				}
				else if (i == n - 1 && j == m - 1)
				{
					if (a[i][j] < a[i - 1][j - 1] && a[i][j] < a[i - 1][j] && a[i][j] < a[i][j - 1])
					{
						printf("%d ", a[i][j]);
					}
				}
				else if (i == 0)
				{
					if (a[i][j] < a[i][j - 1] && a[i][j] < a[i][j + 1] && a[i][j] < a[i + 1][j - 1] && a[i][j] < a[i + 1][j] && a[i][j] < a[i + 1][j + 1])
					{
						printf("%d ", a[i][j]);
					}
				}
				else if (i == n - 1)
				{
					if (a[i][j] < a[i][j - 1] && a[i][j] < a[i][j + 1] && a[i][j] < a[i - 1][j - 1] && a[i][j] < a[i - 1][j] && a[i][j] < a[i - 1][j + 1])
					{
						printf("%d ", a[i][j]);
					}
			}
			else
			{
				if (a[i][j] < a[i-1][-1] && a[i][j] < a[i-1][j] && a[i][j] < a[i-1][j+1] && a[i][j] < a[i][-1] && a[i][j] < a[i][j+1] && a[i][j] < a[i+1][j-1] && a[i][j] < a[i+1][j] && a[i][j] < a[i+1][j+1])
				{
					printf("%d ", a[i][j]);
				}
			}
		}
	}
}
}


// Hoán đổi vị trí 2 phần tử trong ma trận
void swap(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}

// Sắp xếp ma trận sao cho: các dòng có chỉ số lẻ tăng dần, còn các dòng có chỉ số chẵn thì giảm dần
void Sort_Matrix(int n, int m, int a[][100])
{
	int temp;
	for (int i = 0; i < m; i++)
	{
		if (i % 2 == 0)
		{
			for (int j = 0; j < n - 1; j++)
			{
				for (int k = j + 1; k < n; k++)
				{
					if (a[i][j] < a[i][k])
					{
						swap(a[i][j], a[i][k]);
					}
				}
			}
		}
		else
		{
			for (int j = 0; j < n - 1; j++)
			{
				for (int k = j + 1; k < n; k++)
				{
					if (a[i][j] > a[i][k])
					{
						swap(a[i][j], a[i][k]);
					}
				}
			}
		}
	}
	Output(n, m, a);
}

// Sắp xếp ma trận sao cho: các cột có chỉ số lẻ giảm dần, còn các cột có chỉ số chẵn thì tăng dần
void Sort_Matrix_2(int n, int m, int a[][100])
{
	int temp;
	for (int i = 0; i < n; i++)
	{
		if (i % 2 != 0)
		{
			for (int j = 0; j < m - 1; j++)
			{
				for (int k = j + 1; k < m; k++)
				{
					if (a[j][i] < a[k][i])
					{
						swap(a[j][i], a[k][i]);
					}
				}
			}
		}
		else
		{
			for (int j = 0; j < m - 1; j++)
			{
				for (int k = j + 1; k < m; k++)
				{
					if (a[j][i] > a[k][i])
					{
						swap(a[j][i], a[k][i]);
					}
				}
			}
		}
	}
	Output(n, m, a);
}




// Kiểm tra các giá trị trong ma trận có giảm dần theo cột và dòng ( ziczac ) không
int check_ziczac(int n, int m, int a[][100])
{
	int check = 1;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{	
			if(a[i][n-1] < a[i+1][0])
				check = 0;
			if(a[i][j] < a[i][j+1])
				check = 0;
		}
	}
	return check;
}


void Bai03_THTL_buoi4()
{
	int a[100][100], n,m;
	int b[100], sl_b;
	int count[10] = {0};
	int lc;
	do
	{
		system("cls");
		printf("\n========================================================MENU==========================================================");
		printf("\n20. Tao mang 2 chieu ngau nhien");
		printf("\n21. Tao mang 2 chieu nhap tu ban phim");
		printf("\n22. Xuat mang 2 chieu");
		printf("\n1. Liet ke cac cot chua toan so le");
		printf("\n2. Tim phan tu lon nhat tren bien cua ma tran");
		printf("\n3. Dem cac phan tu co chu so 2 trong ma tran");
		printf("\n4. Tim phan tu cuc tieu trong ma tran");
		printf("\n5. Sap xep cac dong co chi so le tang dan, chi so chan giam dan");
		printf("\n6. Sap xep cac cot co chi so le giam dan, chi so chan tang dan");
        printf("\n7. Kiem tra ma tran co cac phan tu giam dan theo dong va cot khong");
        printf("\n8. Liet ke cac dong chua toan so chan");
		printf("\n9. Liet ke cac dong co cac phan tu giam dan");
		printf("\n10. Tim phan tu xuat hien nhieu nhat trong ma tran");
		printf("\n11. Tim cac chu so xuat hien nhieu nhat trong ma tran");
		printf("\n12. Tim cot co tong nho nhat") ;
		printf("\n13. Hoan doi hai cot trong ma tran");
		printf("\n14. Hoan doi hai dong trong ma tran");
		printf("\n0. Thoat");	
		printf("\nVui long nhap lua chon: ");
		scanf("%d", &lc);
		switch (lc)
		{

		case 20:
		{
			Input(n, m, a);
			system("pause");
			break;
		}
		case 21:
		{
			InputFromKeyBoard(n, m, a);
			system("pause");
			break;
		}
		case 22:
		{
			Output(n, m, a);
			system("pause");
			break;
		}
		case 1:
		{
				check_sole_allcot(n, m, a);
				  system("pause");
				  break;
		}
		case 2:
		{
				  printf("Max tren bien la: %d \n", Max_bien(n, m, a));
				  system("pause");
				  break;
		}
		case 3:
		{
				  Output_2(n, m, a);
				  system("pause");
				  break;
		}
		case 4:
		{
				 
				  print_SuperMin(n, m, a);
				  system("pause");
				  break;
		}
		case 5:
		{
				  Sort_Matrix(n, m, a);
				  system("pause");
				  break;
		}
        case 6:
        {
                    Sort_Matrix_2(n, m, a);
                    system("pause");
                    break;
        }
        case 7:
        {
                    if (check_ziczac(n, m, a) == 1)
					{
						printf("Ma tran co cac phan tu giam dan theo cot va dong. \n");
					}
					else
					{
						printf("Ma tran ko co cac phan tu giam dan theo cot va dong. \n");
					}
                    system("pause");
                    break;
        }
        case 8:
        {
                    RowAllEven(n, m, a);
                    system("pause");
                    break;
        }
        case 9:
        {
                    RowMatrixDecrease(n, m, a);
                    system("pause");
                    break;
        }
		case 10:
		{
			
					mostFrequentElement(n, m, a);
				   system("pause");
				   break;
		}
		case 11:
		{
					Count_Number_In_Matrix(n, m, a);
					system("pause");
					break;
		}
		case 12:
		{
					Sum_Min(n, m, a);
					system("pause");
					break;
		}
		case 13:
		{
					Change_Collum(n, m, a);
					system("pause");
					break;
		}
		case 14:
		{
					Change_Row(n, m, a);
					system("pause");
					break;
		}
		
		default:
			break;
		}
	} while (lc != 0);
}




int main()
{
	Bai03_THTL_buoi4();
	return 0;
}