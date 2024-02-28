#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include<conio.h>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <string>
#include <math.h>
using namespace std;

void Input1(unsigned long long&n, unsigned long long&m, unsigned long long&r, unsigned long long&c)
{
	printf("Enter n: ");
	scanf_s("%d", &n);
	printf("Enter m: ");
	scanf_s("%d", &m);
	printf("Enter r: ");
	scanf_s("%d", &r);
	printf("Enter c: ");
	scanf_s("%d", &c);
}

void Input2(unsigned long long& n, unsigned long long& m, unsigned long long& r, unsigned long long& c)
{
	scanf_s("%d %d %d %d", &n,&m,&r,&c);
}

int max(int a, int b)
{
	if (a>b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

// khoáº£ng cÃ¡ch Manhattan |x1 - x2| + |y1 - y2|
int  Prison_Break(unsigned long long n, unsigned long long m, unsigned long long r, unsigned long long c)
{
	int Max = 0;
	Max = max(Max, (r - 1) + (c - 1));
	Max = max(Max, (n - r) + (c - 1));
	Max = max(Max, (r - 1) + (m - c));
	Max = max(Max, (n - r) +(m - c));

	return Max;
}

int main()
{
	unsigned long long t,n,m,r,c;
	printf("Enter t: ");
	scanf_s("%d", &t);

	while (t--)
	{
		//Input1(n, m, r, c);
		Input2(n, m, r, c);
		printf("%d\n", Prison_Break(n, m, r, c));
	}
	return 0;
}