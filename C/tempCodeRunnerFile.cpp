#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string>
#include <string.h>
#include <ctime>
#include <stdlib.h>

void input(int a[],int &n)
{
    printf("Nhap so phan tu cua mang: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Nhap a[%d] = ",i);
        scanf("%d",&a[i]);
    }
}

void output(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}

int ktsnt(int a)
{
    if(a<2)
    return 0;
    if(a==2)
    return 1;
    for(int i=2;i<a;i++)
    {
        if(a%i==0)
        return 0;
    }
    return 1;
}
int snt_first(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		if(ktsnt(a[i])==1)
		return i;
	}
	return -1;
}

int snt_max(int a[],int n)
{
	if(snt_first(a,n)==-1)
	return -1;
	int vt_max = snt_first(a,n);
	int snt_max = a[vt_max];
	for(int i=vt_max;i<n;i++)
	{
		if(a[i]>snt_max && ktsnt(a[i])==1)
		{
			snt_max = a[i];
			vt_max = i;
		}
	}
	return vt_max;
}

int check(int n) {
    int pos = 1;
    while (n > 0) {
        int digit = n % 10;
        if (pos % 2 != 0 && digit % 2 != 0) {
            return 0;
        }
        n /= 10;
        pos++;
    }
    return 1;
}

int sum(int a[],int n)
{
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        if(check(a[i])==1)
        {
            sum+=a[i];
        }
    }
    return sum;
}

void sapxep_chantang(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        if(a[i]%2==0)
        {
            for(int j=i+1;j<n;j++)
            {
                if(a[j]%2==0)
                {
                    if(a[i]>a[j])
                    {
                        int temp = a[i];
                        a[i] = a[j];
                        a[j] = temp;
                    }
                }
            }
        }
    }
}

int kt_mangtang(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        if(a[i]>a[i+1])
        {
            return 0;
        }
    }
    return 1;
}

int kt_mangcapsocong(int a[],int n)
{
    int d= a[1] - a[0];
    for(int i=0;i<n;i++)
    {
        if(a[i+1]-a[i]!=d)
        {
            return 0;
        }
    }
    return 1;
}

int vt_le_first(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]%2!=0)
        {
            return i;
        }
    }
    return -1;
}

int tim_le_max(int a[],int n)
{
    int vt_le_first= vt_le_first(a,n);
    if(vt_le_first==-1)
    {
        return -1;
    }
    int le_max = a[vt_le_first];

    for(int i=vt_le_first;i<n;i++)
    {
        if(a[i]>le_max && a[i]%2!=0)
        {
            le_max = a[i];
            vt_le_first = i;
        }
    }
    return vt_le_first;
}

void xuat_daycon_giamdainhat(int a[],int n)
{
    int max = 1;
    int vt_day_max =0;
    for(int i=0;i<n;i++)
    {
        int max_temp =1;
        if(a[i+1]>a[i])
        {     
            int j=i;
            while(a[j+1]>a[j])
            {
                max_temp++;
                j++;
            }
        }
        if(max_temp>max)
        {
            max = max_temp;
            vt_day_max = i;
        }
    }
    printf("\nDay con giam dai nhat la: ");
    for(int i=vt_day_max;i<vt_day_max+max;i++)
    {
        printf("%d\t",a[i]);
    }
}



int main()
{
	int a[100],n;
    input(a,n);
    output(a,n);
    printf("So nguyen to lon nhat nam o vi tri %d",snt_max(a,n));
    printf("\nTong cac so co chu so le la: %d",sum(a,n));
    sapxep_chantang(a,n);
    printf("\nMang sau khi sap xep chan tang dan la: ");
    output(a,n);
    if(kt_mangtang(a,n)==1)
    {
        printf("\nMang tang dan");
    }else
    {
        printf("\nMang khong tang dan");
    }
    if(kt_mangcapsocong(a,n)==1)
    {
        printf("\nMang la cap so cong");
    }else
    {
        printf("\nMang khong la cap so cong");
    }
    printf("\nVi tri so le lon nhat la: %d",tim_le_max(a,n));
    xuat_daycon_giamdainhat(a,n);
    getch();
}