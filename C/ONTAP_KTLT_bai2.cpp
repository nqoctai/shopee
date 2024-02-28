#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string>
#include <string.h>
#include <ctime>
#include <stdlib.h>

int tinh_giadien(int &chiso_moi,int &chiso_cu)
{
    int tiendien;
    printf("Nhap chi so moi: ");
    scanf("%d",&chiso_moi);
    printf("Nhap chi so cu: ");
    printf("%d",&chiso_cu);	
    int dien_dadung = chiso_moi - chiso_cu;
    if(dien_dadung>=0)
    {
        if(dien_dadung<=50)
        {
            tiendien = dien_dadung*1678;
        }else
        {
            if(dien_dadung<=100)
            {
                tiendien = 50*1678 + (dien_dadung-50)*1734;
            }else
            {
                if(dien_dadung<=200)
                {
                    tiendien = 50*1678 + 50*1734 + (dien_dadung-100)*2014;
                }else
                {
                    if(dien_dadung<=300)
                    {
                        tiendien = 50*1678 + 50*1734 + 100*2014 + (dien_dadung-200)*2536;
                    }else
                    {
                        if(dien_dadung<=400)
                        {
                            tiendien = 50*1678 + 50*1734 + 100*2014 + 100*2536 + (dien_dadung-300)*2834;
                        }else
                        {
                            tiendien = 50*1678 + 50*1734 + 100*2014 + 100*2536 + 100*2834 + (dien_dadung-400)*2927;
                        }
                    }
                }
            }
        }
    }
    return tiendien;
}


int main()
{
    int chiso_moi,chiso_cu;
    int tiendien = tinh_giadien(chiso_moi,chiso_cu);
    printf("Tien dien phai tra la: %d",tiendien);
    getch();
    return 0;
}