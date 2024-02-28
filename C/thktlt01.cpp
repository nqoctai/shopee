#define _CTR_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string>
#include <string.h>
#include <ctime>
#include <stdlib.h>



void Nhapmang(int a[],int &n)
{
    printf("\nNhap so luong phan tu: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
    	printf("\n[%d]=",i);
        scanf("%d",&a[i]);
    }
}

void Xuatmang(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}



void Bai13(int a[],int b[],int n,int m)
{
	try
	{
		if(m!=n)
		throw "\nSo luong phan tu mang a khac voi mang b";
		else
		{
			for(int i=0;i<n;i++)
			{
				try
				{
					if(b[i]==0)
					{
						throw 101;
					}				
					else
					{
						float t=(float)a[i]/b[i];
						printf("\na[%d]/b[%d]=%.2f",i,i,t);
					} 
				}
				catch(int errcode)
				{
					if(errcode == 101)
					printf("\na[%d]/b[%d]: Loi so bi chia khong duoc la 0",i,i); 
				}
			}
		}
	}
	catch (const char *st)
	{
		printf("\nLoi: %s",st);
	}	
}

void nhapNguoilaodong(char ten[], int &ns, char gt[],int &namHH)
{
	time_t now = time(0);
	tm *ltm = localtime(&now);
	namHH = 1900 + ltm->tm_year;
	printf("\nNhap ten nguoi lao dong: ");
	gets(ten);
	printf("\nNhap gioi tinh nguoi lao dong: ");
	gets(gt);
	printf("\nNhap nam sinh nguoi lao dong: ");
	scanf("%d", &ns);

}
int tinhtuoi(int ns,int namHH)
{
	return namHH - ns;
}
int kiemtragt(char gt[50])
{
	if (strncmp(gt, "nam", 50) == 0 || strncmp(gt, "nu", 50) == 0)
		return 1;
	else
		return -1;
}
int dieukien(int tuoi, char gt[])
{
	if (strncmp(gt, "nam",50) == 0)
	{
		if (tuoi < 18 || tuoi >62)
			return -1;
		else
			return 1;
	}
	else if (strncmp(gt, "nu",50)==0)
	{
		if (tuoi < 18 || tuoi > 60)
			return -1;
		else
			return 1;
	}
}
int namNghihuu(int tuoi,char gt[],int namHH)
{
	int nnh;
	if (strncmp(gt, "nam", 50) == 0)
		nnh = namHH + (62 - tuoi);
	else
		nnh = namHH + (60 - tuoi);
	return nnh;
}
void BaiMau06(){
	char ten[50], gt[50];
	int ns, namHH;
	nhapNguoilaodong(ten, ns, gt,namHH);
	int tuoi = tinhtuoi(ns,namHH);
	int nnh;
	try{
		if (kiemtragt(gt) == -1)
			throw "\nGioi tinh khong hop le";
		if (dieukien(tuoi, gt) == -1)
			throw 101;
		else
		{
			nnh = namNghihuu(tuoi, gt,namHH);
			printf("\nNam nghi huu: %d", nnh);
		}
	}
	catch(int errCode){
		if (errCode == 101)
			printf("\nTuoi khong hop le");
	}
	catch (const char *errcode)
	{
		printf("\nLoi: %s", errcode);
	}
}



int main()
{
    
	int lc; 
	int a[100], b[100],m,n;
	do
	 {
	printf("\n------------------------------------------------MENU--------------------------------------------------");
	printf("\n1. Bai 13");
	printf("\n2. Bai 14");
	printf("\nVui long nhap lua chon: ");
	scanf("%d",&lc);
	getchar(); 
	switch(lc)
		{
			case 1:
				{	
					printf("\nNhap mang a:");
					Nhapmang(a,n);
					Xuatmang(a,n);
					printf("\nNhap mang b: ");
					Nhapmang(b,m);
					Xuatmang(b,m);
					Bai13(a,b,n,m);
					break;
				}
				
			case 2:
				{
					BaiMau06();
					break;
				}
		}
		
	}while(lc!=0);	
}