#define _CTR_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string>
#include <string.h>
#include <ctime>
#include <stdlib.h>

void nhapmang_contro(float *&a,int &n)
{
    printf("Nhap so phan tu cua mang: ");
    scanf("%d",&n);
    a = (float*)malloc(n*sizeof(float));
    for(int i=0;i<n;i++)
    {
       printf("Nhap a[%d] = ",i);
        scanf("%f",a+i);
    }
}

void nhapmang_contro_random(float *&a,int &n)
{
    printf("Nhap so phan tu cua mang: ");
    scanf("%d",&n);
    a = (float*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
       *(a+i) = ((float)rand()/(RAND_MAX))*200;
    }
}

void xuatmang_contro(float *a,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%f ",*(a+i));
    }
}
int kt_chuachuso2(float a)
{
	int temp;
	while(a>0)
	{
		temp = (int)a%10;
		if(temp==2)
		return 1;
		a = a/10;
	}
	return 0;
}

int dem_chuachuso2(float *a,int n)
{
	int count=0;
	for(int i=0;i<n;i++)
	{
		if(kt_chuachuso2(*(a+i))==1)
		count++;
	}
	return count;
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

void xuat_songuyen_snt(float *a,int n)
{
    for(int i=0;i<n;i++)
    {
        if(ktsnt(*(a+i))==1)
        {
            printf("%f ",*(a+i));
        }
    }
}

void xuat_thapphan(float *a,int n)
{
	for(int i=0;i<n;i++)
	{
		float phanthapphan = *(a+i) - (int)*(a+i);
		printf("%f ",phanthapphan);
	}
 } 

void xoaphantu(float *a,int &n,int vt)
{
	for(int i=vt;i<n;i++)
	{
		*(a+i) = *(a+i+1);
	}
	n--;
}


void xoa_sole(float *a,int &n)
{
	for(int i=0;i<n;i++)
	{
		if((int)*(a+i)%2!=0)
		{
			xoaphantu(a,n,i);
			i--;
		}
	}
}


int tim_x_tronga(float *a,int n,float &x)
{
	printf("Nhap x muon tim: ");
	scanf("%f",&x);
	int count=0;
	for(int i=0;i<n;i++)
	{
		if(*(a+i)==x)
		count++;
	}
	return count;
 } 
 
 void them_x(float *a,int &n,int vt,float x)
 {
 	n++;
 	for(int i=n-1;i>vt;i--)
 	{
 		*(a+i)= *(a+i-1);
	 }
	 *(a+vt)= x;
 }
 
 int tim_max(float *a,int n)
 {
 	float max =*a;
 	int vt_max=0;
 		for(int i=0;i<n;i++)
 	{
 		if(*(a+i)>max)
 		{
 			max = *(a+i);
 			vt_max= i;
		 }
	}
	return vt_max;
 }
 
 
 void them_x_saumax(float *a,int &n)
 {
 	int vt_max = tim_max(a,n);
 	float x;
 	printf("Nhap x muon them: ");
 	scanf("%f",&x);
 	them_x(a,n,vt_max+1,x);
 }
 
  int tim_min(float *a,int n)
 {
 	float min =*a;
 	int vt_min=0;
 		for(int i=0;i<n;i++)
 	{
 		if(*(a+i)<min)
 		{
 			min = *(a+i);
 			vt_min= i;
		 }
	}
	return vt_min;
 }
 
 
 void them_x_truocmin(float *a,int &n)
 {
 	int vt_min = tim_min(a,n);
 	float x;
 	printf("Nhap x muon them: ");
 	scanf("%f",&x);
 	them_x(a,n,vt_min,x);
 }
 
 
 void xoa_max_min(float *a,int &n)
 {
 	float max =*a;
 	float min=*a;
 	int vt_max=0;
 	int vt_min=0;
 	for(int i=0;i<n;i++)
 	{
 		if(*(a+i)>max)
 		{
 			max = *(a+i);
 			vt_max= i;
		 }
		 if(*(a+i)<min)
		 {
		 	min = *(a+i);
		 	vt_min=i;
		 }
	 }
	 xoaphantu(a,n,vt_max);
	 xoaphantu(a,n,vt_min);
 }

void Cau1()
{
	float *a;
    int n,lc; 
	do
	{
		system("cls");
		printf("\n========================================================MENU==========================================================");
		printf("\n1. Nhap va xuat mang a");
		printf("\n2. Xuat cac phan tu co so nguyen la so nguyen to");
		printf("\n3. Xuat cac phan thap phan cua moi phan tu");
		printf("\n4. Dem so phan tu co phan nguyen chua chu so 2");
		printf("\n5. Xoa cac phan tu co phan nguyen la le");
		printf("\n6. Tim trong a co bao nhieu phan tu x");
		printf("\n7. Xoa phan tu max min");
		printf("\n8. Them x vao sau so lon nhat cua a");
		printf("\n9. Them x vao truoc so nho nhat cua a");
		printf("\n10. Sap xep mang tang dan/giam theo 3 giai thuat ");
		printf("\n20.Nhap mang bang ban phim");
		printf("\n0. Thoat");
		printf("\nVui long nhap lua chon: ");
		scanf("%d", &lc);
		switch (lc)
		{
		case 1:
		{
			nhapmang_contro_random(a,n);
			xuatmang_contro(a,n);
			system("pause");
			break;	
		}
		case 2:
		{
			xuat_songuyen_snt(a,n);
			system("pause");
			break;
		}
		case 3:
			{
				xuat_thapphan(a,n);
				system("pause");
				break;
			}
		case 4:
		{
			printf("\nCo %d phan tu co so nguyen chua so 2",dem_chuachuso2(a,n));
			system("pause");
			break;
		}
		case 5:
		{
			xoa_sole(a,n);
			printf("\nMang sau khi xoa so le la: ");
			xuatmang_contro(a,n);
			system("pause");
			break;
		}
		case 6:
		{
			float x;
			printf("Co %d x trong a",tim_x_tronga(a,n,x));
			system("pause");
			break;
		}
		case 7:
		{
			xoa_max_min(a,n);
			system("pause");
			break;
		}
		case 8:
			{
				float x;
				them_x_saumax(a,n);
				system("pause");
				break;
			}
			case 9:
				{
				
				them_x_truocmin(a,n);
				system("pause");
				break;
				}
		case 20:
			{
				nhapmang_contro(a,n);
				system("pause");
				break;
			}
			case 21:
				{
					xuatmang_contro(a,n);
					system("pause");
					break;
				}
		default:
			break;
		}
	}while(lc != 0);
}

int main()
{
    Cau1();
    getch();
}