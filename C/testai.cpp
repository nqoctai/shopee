
#include <iostream>
#include <cstring>
using namespace std;

int tinhtuoi(int ns, int thangNS, int namHH, int thangHH){
    int tuoi;
    if (thangNS > thangHH)
        tuoi = namHH - ns - 1;
    else
        tuoi = namHH - ns;
    return tuoi;
}

int namNghihuu(int tuoi, char gt[50], int namHH){
    int nnh;
    if (strncmp(gt, "nam", 50) == 0)
    {
        if (tuoi >= 60)
            nnh = namHH;
        else if (tuoi < 60)
        {
            if (namHH < 2021)
                nnh = namHH + (60 - tuoi);
            else if (namHH >= 2021 && namHH < 2028)
                nnh = namHH + (60 - tuoi) + 3;
            else
                nnh = namHH + 62 - tuoi;
        }
    }
    else
    {
        if (tuoi >= 55)
            nnh = namHH;
        else if (tuoi < 55)
        {
            if (namHH < 2021)
                nnh = namHH + (55 - tuoi);
            else if (namHH >= 2021 && namHH < 2035)
                nnh = namHH + (55 - tuoi) + 4;
            else
                nnh = namHH + 60 - tuoi;
        }
    }
    return nnh;
}

int kiemtragt(char gt[50]){
    if (strncmp(gt, "nam", 50) == 0 || strncmp(gt, "nu", 50) == 0)
        return 1;
    else
        return -1;
}

int dieukien(int tuoi, char gt[50]){
    if (tuoi < 15 || tuoi > 60)
        return -1;
    else if (kiemtragt(gt) == -1)
        return -1;
    else
        return 1;
}

void nhapNguoilaodong(char ten[50], int &ns, int &thangNS, char gt[50], int &namHH, int &thangHH){
    cout << "Nhap ho ten: ";
    cin.getline(ten, 50);
    cout << "Nhap ngay sinh (dd): ";
    cin >> ns;
    cout << "Nhap thang sinh (mm): ";
    cin >> thangNS;
    cout << "Nhap nam hien tai: ";
    cin >> namHH;
    cout << "Nhap thang hien tai (mm): ";
    cin >> thangHH;
    cout << "Nhap gioi tinh (nam/nu): ";
    cin >> gt;
}

int main(){
    char ten[50], gt[50];
    int ns, namHH,thangNS,thangHH;
    nhapNguoilaodong(ten, ns, thangNS, gt, namHH, thangHH);
    int tuoi = tinhtuoi(ns, thangNS, namHH, thangHH);
    int nnh;
    try{
        if (kiemtragt(gt) == -1)
            throw "\nGioi tinh khong hop le";
        if (dieukien(tuoi, gt) == -1)
            throw 101;
        else
        {
            nnh = namNghihuu(tuoi, gt, namHH);
            cout << "Thoi gian nghi huu cua " << ten << " la: " << nnh << endl;
        }
    }
    catch (const char* msg) {
        cerr << msg << endl;
    }
    catch (int e){
        cerr << "Tuoi hoac gioi tinh khong hop le" << endl;
    }
    return 0;
}