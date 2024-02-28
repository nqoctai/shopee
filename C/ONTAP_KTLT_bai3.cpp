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

int LinearSearch(int a[],int n,int x)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==x)
        {
            return i;
        }
    }
    return -1;
}

void swap(int &a,int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void InterchangeSort(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                swap(a[i],a[j]);
            }
        }
    }
}

void SelectionSort(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            {
                min = j;
            }
        }
        swap(a[i],a[min]);
    }
}

void QuickSort(int a[],int left,int right)
{
    if(left>=right)
    {
        return;
    }
    int i=left,j=right;
    int mid = (left+right)/2;
    int x = a[mid];
    do
    {
        while(a[i]<x)
        {
            i++;
        }
        while(a[j]>x)
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

int BinarySearch(int a[],int n, int x)
{
    int left=0,right=n-1;
    while(left<=right)
    {
        int mid = (left+right)/2;
        if(a[mid]==x) return mid;
        else
        {
            if(a[mid]>x)
            {
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
    }
    return -1;
}

int main()
{
    int a[100],n;
    input(a,n);
    output(a,n);
    getch();
}