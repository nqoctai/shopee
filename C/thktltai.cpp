#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

struct DateOfBirth {
    int day;
    int month;
    int year;
};

struct Worker {
    char name[50];
    char gender[10];
    DateOfBirth dob;
};

void inputDateOfBirth(DateOfBirth& dob) {
    printf("Enter day: ");
    scanf("%d", &dob.day);
    printf("Enter month: ");
    scanf("%d", &dob.month);
    printf("Enter year: ");
    scanf("%d", &dob.year);
}



void inputWorker(Worker& worker, int &namHH, int &thangHH, int &ngayHH) {
    time_t now = time(0);
	tm *ltm = localtime(&now);
    ngayHH = ltm->tm_mday;
	namHH = 1900 + ltm->tm_year;
    thangHH = 1 + ltm->tm_mon;
    printf("Enter name: ");
    cin.getline(worker.name, 50);
    printf("Enter gender: ");
    cin.getline(worker.gender, 10);
    printf("Enter date of birth:\n");
    inputDateOfBirth(worker.dob);
}

// Tinh tuoi
int tinhtuoi(Worker worker,int namHH,int thangHH, int ngayHH)
{
    if(worker.dob.month > thangHH)
    {
        return namHH - worker.dob.year - 1;
    }else
    {
        if(worker.dob.month == thangHH && worker.dob.day > ngayHH)
        {
            return namHH - worker.dob.year - 1;
        }else
        return namHH - worker.dob.year;
    }
}

// Kiểm tra giới tính
int kiemtragt(char gt[50])
{
	if (strncmp(gt, "nam", 50) == 0 || strncmp(gt, "nu", 50) == 0)
		return 1;
	else
		return -1;
}

int tinhtuoinghihuu_nam(Worker worker)
{
    int tnh = 60 * 12 + 3;
    int month_limit = 0;
    if(worker.dob.year * 12 + worker.dob.month >= 1961 * 12 + 1 )
    {
        if(worker.dob.year * 12 + worker.dob.month <= 1966 * 12 + 4)
        {
            for(int i=1961 * 12 + 1; i<=worker.dob.year * 12 + worker.dob.month; i++)
            {
            month_limit++;
            if(month_limit%9==0)
            {
                tnh+=3;
            }
            }
        }else
        {
            tnh = 62 * 12;
        }
    }else
    {
        tnh = 60 * 12 ;
    }
    return tnh;
}

int tinhtuoinghihuu_nu(Worker worker)
{
    int tnh = 55 * 12 + 4;
    int month_limit = 0;
    if(worker.dob.year * 12 + worker.dob.month >= 1966 * 12 + 1 )
    {
        if(worker.dob.year * 12 + worker.dob.month <= 1975 * 12 + 5)
        {
            for(int i=1966 * 12 + 1; i<=worker.dob.year * 12 + worker.dob.month; i++)
            {
            month_limit++;
            if(month_limit%8==0)
            {
                tnh+=4;
            }
            }
        }else
        {
            tnh = 60 * 12;
        }
    }else
    {
        tnh = 55 * 12 ;
    }
    return tnh;
}

int dieukien(Worker worker,int tuoi, char gt[])
{
    float tnh_n = (float)tinhtuoinghihuu_nam(worker) / 12;
    float tnh_nu = (float)tinhtuoinghihuu_nu(worker) / 12;
	if (strncmp(gt, "nam",50) == 0)
	{
		if (tuoi < 18 || tuoi > tnh_n)
			return -1;
		else
			return 1;
	}
	else if (strncmp(gt, "nu",50)==0)
	{
		if (tuoi < 18 || tuoi > tnh_nu)
			return -1;
		else
			return 1;
	}
}

int namNghihuu(Worker worker,int tuoi,char gt[],int namHH,int thangHH)
{
	int nnh;
    float tnh_n = tinhtuoinghihuu_nam(worker);
    float tnh_nu = tinhtuoinghihuu_nu(worker);
	if (strncmp(gt, "nam", 50) == 0)
		nnh = namHH * 12 + thangHH + (tnh_n - tuoi*12);
	else
		nnh = namHH * 12 + (tnh_nu - tuoi*12);
	return nnh/12;
}

void BaiMau06(){
    Worker worker;
	char ten[50], gt[50];
	int ns, namHH, thangHH, ngayHH;
	inputWorker(worker, namHH,thangHH,ngayHH);
	int tuoi = tinhtuoi(worker,namHH,thangHH,ngayHH);
	int nnh;
	try{
		if (kiemtragt(gt) == -1)
			throw "\nGioi tinh khong hop le";
		if (dieukien(worker,tuoi, gt) == -1)
			throw 101;
		else
		{
			nnh = namNghihuu(worker,tuoi, gt,namHH,thangHH);
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


int main() {
    Worker worker;
    int namHH,thangHH,ngayHH;
    inputWorker(worker, namHH,thangHH,ngayHH);
    printf("Name: %s\n", worker.name);
    printf("Gender: %s\n", worker.gender);
    printf("Date of birth: %d/%d/%d\n", worker.dob.day, worker.dob.month, worker.dob.year);

    int tnh = tinhtuoinghihuu_nu(worker);
    printf("Tuoi nghi huu: %d\n", tnh);

    int tt = tinhtuoi(worker, namHH,thangHH,ngayHH);
    printf("Tuoi: %d\n", tt);
    return 0;
}



