#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string>
#include <string.h>
#include <ctime>
#include <stdlib.h>
#include <math.h>

double calculate_sum(int n) {
    if (n == 1) {
        return 1;
    } else {
        double sum = calculate_sum(n - 1);
        return sum + n * sum;
    }
}

double calculate_An(int n) {
    return n * calculate_sum(n - 1);
}

int main() {
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    printf("An = %lf", calculate_An(n));
    getch();
    return 0;
}