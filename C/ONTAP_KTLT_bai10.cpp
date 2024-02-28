#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string>
#include <string.h>
#include <ctime>
#include <stdlib.h>
#include <math.h> 

void calculate(int n, int& xn, int& yn) {
    if (n == 0) {
        xn = 1;
        yn = 0;
    } else {
        int xn_minus_1, yn_minus_1;
        calculate(n - 1, xn_minus_1, yn_minus_1);
        xn = xn_minus_1 + yn_minus_1;
        yn = 3 * xn_minus_1 + 2 * yn_minus_1;
    }
}

int bai10(int n) {
    int xn, yn;
    calculate(n, xn, yn);
    return xn; // or return yn; depending on what you want to return
}

int main() {
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    printf("xn = %d", bai10(n));
    getch();
    return 0;
}