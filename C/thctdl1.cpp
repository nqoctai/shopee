#include<iostream>
#include<fstream> 
#include<string.h>
using namespace std;

struct sinhvien
{
    string MSSV;
    string Date;
    string Ten;
    string diachi;
    string nganh;
    float dtb;
};
typedef struct sinhvien SV;

int n;
SV a[100];

struct date
{
    int ngay, thang, nam;
};

struct name
{
    string ho, lot, ten;
};

struct SINHVIEN
{
    string MSSV;
    name Ten;
    string diachi;
    string nganh;
    date Date;
    float dtb;
    int tuoi;
};

void doc_file_danhsach_sinhvien(ifstream &filein)
{
    SV sv;
    n = 0;
    while(!filein.eof()) 
    {
        getline(filein,sv.MSSV,',');
        getline(filein,sv.Ten,',');
        sv.Ten = sv.Ten.substr(1); 
        getline(filein,sv.diachi,',');
        sv.diachi = sv.diachi.substr(1); 
        getline(filein,sv.nganh,',');
        sv.nganh = sv.nganh.substr(1); 
        getline(filein,sv.Date,',');
        sv.Date = sv.Date.substr(1);
        filein >> sv.dtb;
        filein.ignore(); 

        a[n] = sv; 
        n++;
    }
    for(int i=0;i<n;i++)
    {
        cout << "\n\n\t\tSinh vien thu " << i+1;
        cout << "\nMa sinh vien: " << a[i].MSSV;
        cout << "\nHo ten sinh vien: " << a[i].Ten;
        cout << "\nDia chi: " << a[i].diachi;
        cout << "\nNganh : " << a[i].nganh;
        cout << "\nNgay sinh: " << a[i].Date;
        cout << "\nDiem trung binh: " << a[i].dtb;
        cout << "\n";
    }
}

void nhap1sv(SINHVIEN &SV) 
{
    cout << "\nNhap ma so: "; cin >> SV.MSSV;
    cout << "\nNhap ho ten: "; cin >> SV.Ten.ho; cin >> SV.Ten.lot; cin >> SV.Ten.ten;
    cout << "\nNhap dia chi: "; cin >> SV.diachi;
    cout << "\nNhap nganh hoc: "; cin >> SV.nganh;
    cout << "\nNhap ngay sinh: "; cin >> SV.Date.ngay; cin >> SV.Date.thang; cin >> SV.Date.nam;
    cout << "\nNhap diem trung binh: "; cin >> SV.dtb; 
}
void xuat1sv(SINHVIEN SV)
{
    cout << "\nMa so sinh vien: " << SV.MSSV;
    cout << "\nHo ten sinh vien: " << SV.Ten.ho << " " << SV.Ten.lot << " " << SV.Ten.ten;
    cout << "\nDia chi: "<< SV.diachi;
    cout << "\nNganh hoc: " <<  SV.nganh;
    cout << "\nNgay sinh: "<< SV.Date.ngay << "/" << SV.Date.thang << "/" << SV.Date.nam;
    cout << "\nDiem trung binh: " << SV.dtb; 
}

void nhapdanhsachsinhvien(SINHVIEN ds[],int &n) 
{
    cout << "\nNhap so luong sinh vien : "; cin >> n; 
    cout << "\n\t\tNHAP DANH SACH SINH VIEN"; 
    for(int i = 0 ; i < n ; i++)
    {
        cout <<  "\nSinh vien thu " << i+1;
        nhap1sv(ds[i]);
        cout << "\n";
    }
}
void xuatdanhsachsinhvien(SINHVIEN ds[],int n)
{
    cout << "\n\t\tDANH SACH THONG TIN SINH VIEN";
    for(int i = 0 ; i < n ; i++)
    {
        cout <<  "\n\t\tSinh vien thu " << i+1;
        xuat1sv(ds[i]);
        cout << "\n";
    }
}


void tinhdiemchu_cach1(SINHVIEN ds[],int n)
{
    for(int i = 0 ; i < n ; i ++)
    {
        if(ds[i].dtb > 8.5)
        {
            cout << "\nDiem chu cua " << ds[i].Ten.ho << " " << ds[i].Ten.lot << " " << ds[i].Ten.ten << " la A";
        }
        else 
        {
            if(ds[i].dtb > 7.0)
            {
                cout << "\nDiem chu cua " << ds[i].Ten.ho << " " << ds[i].Ten.lot << " " << ds[i].Ten.ten << " la B";
            }
            else
            {
                if(ds[i].dtb > 5.5)
                {
                    cout << "\nDiem chu cua " << ds[i].Ten.ho << " " << ds[i].Ten.lot << " " << ds[i].Ten.ten << " la C";
                }
                else
                {
                    if(ds[i].dtb > 4.0)
                    {
                        cout << "\nDiem chu cua " << ds[i].Ten.ho << " " << ds[i].Ten.lot << " " << ds[i].Ten.ten << " la D";
                    }
                    else
                    {
                        cout << "\nDiem chu cua " << ds[i].Ten.ho << " " << ds[i].Ten.lot << " " << ds[i].Ten.ten << " la A";
                    }
                }
            }
        }
    }
}
void tinhdiemchu_cach2(SINHVIEN ds[],int n)
{
    for(int i = 0 ;i < n ; i++)
    {
        if(ds[i].dtb > 8.5)
        {
            cout << "\nDiem chu cua " << ds[i].Ten.ho << " " << ds[i].Ten.lot << " " << ds[i].Ten.ten << " la A = 4.0";
        }
        else
        {
            if(ds[i].dtb > 8.0)
            {
                cout << "\nDiem chu cua " << ds[i].Ten.ho << " " << ds[i].Ten.lot << " " << ds[i].Ten.ten << " la B+ = 3.5";
            }
            else
            {
                if(ds[i].dtb > 7.0)
                {
                    cout << "\nDiem chu cua " << ds[i].Ten.ho << " " << ds[i].Ten.lot << " " << ds[i].Ten.ten << " la B = 3.0";
                }
                else
                {
                    if(ds[i].dtb >6.5)
                    {
                        cout << "\nDiem chu cua " << ds[i].Ten.ho << " " << ds[i].Ten.lot << " " << ds[i].Ten.ten << " la C+ = 2.5";
                    }
                    else
                    {
                        if(ds[i].dtb > 5.5)
                        {
                            cout << "\nDiem chu cua " << ds[i].Ten.ho << " " << ds[i].Ten.lot << " " << ds[i].Ten.ten << " la C = 2.0";
                        }
                        else
                        {
                            if(ds[i].dtb > 5.0)
                            {
                                cout << "\nDiem chu cua " << ds[i].Ten.ho << " " << ds[i].Ten.lot << " " << ds[i].Ten.ten << " la D+ = 1.5";
                            }
                            else
                            {
                                if(ds[i].dtb > 4.0)
                                {
                                    cout << "\nDiem chu cua " << ds[i].Ten.ho << " " << ds[i].Ten.lot << " " << ds[i].Ten.ten << " la D = 1.0";
                                }
                                else
                                {
                                    cout << "\nDiem chu cua " << ds[i].Ten.ho << " " << ds[i].Ten.lot << " " << ds[i].Ten.ten << " la F = 0";
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void xeploai(SINHVIEN ds[],int n)
{
    for(int i = 0 ;i < n ;i++)
    {
        if(ds[i].dtb >= 8.5)
        {
            cout << "\nSinh vien " << ds[i].Ten.ho << " " << ds[i].Ten.lot << " " << ds[i].Ten.ten << " xep loai: Gioi";
        }
        else
        {
            if(ds[i].dtb >= 7.0)
            {
                cout << "\nSinh vien " <<ds[i].Ten.ho << " " << ds[i].Ten.lot << " " << ds[i].Ten.ten << " xep loai: Kha";
            }
            else
            {
                if(ds[i].dtb >= 5.5)
                {
                    cout << "\nSinh vien " << ds[i].Ten.ho << " " << ds[i].Ten.lot << " " << ds[i].Ten.ten << " xep loai: Trung binh";
                }
                else
                {
                    if(ds[i].dtb>=4.0)
                    {
                        cout << "\nSinh vien " <<ds[i].Ten.ho << " " << ds[i].Ten.lot << " " << ds[i].Ten.ten << " xep loai: Trung binh yeu";
                    }
                    else
                    {
                        cout << "\nSinh vien " << ds[i].Ten.ho << " " << ds[i].Ten.lot << " " << ds[i].Ten.ten << " xep loai: Yeu ( khong dat)";
                    }
                }
            }
        }
    }
}

void xuatcacsinhvienCNTT(SINHVIEN ds[],int n)
{
    cout << "\n\t\tDANH SACH SINH VIEN THUOC NGANH CNTT";
    for(int i = 0 ;i < n ; i++)
    {
        if(strcmp((ds[i].nganh.c_str()),"CNTT")==0)
        {
            cout << "\n";
            cout << "\nSinh vien thu " << i+1;
            xuat1sv(ds[i]);
        }
    }
}

int demsvtren22tuoi(SINHVIEN ds[],int n)
{
    int dem=0;
    for(int i = 0 ; i<n;i++)
    {
        int tuoi = 2019 - ds[i].Date.nam;
        if(tuoi > 22)
        {
            dem++;
        }
    }
    return dem;
}

void xuatcacsinhvien_quequan_TPHCM(SINHVIEN ds[],int n)
{
    cout << "\n\t\tDANH SACH SINH VIEN CO QUE QUAN TPHCM";
    for(int i = 0 ;i < n ; i++)
    {
        if(strcmp((ds[i].diachi.c_str()),"TPHCM")==0)
        {
            cout << "\n";
            cout << "\nSinh vien thu " << i+1;
            xuat1sv(ds[i]);
        }
    }
}


void thongkesv_gioi_CNTT_CNTP(SINHVIEN ds[],int n)
{
    cout << "\nDanh sach sinh vien loai gioi cua khoa CNTT va CNTP";
    for(int i = 0 ; i<n;i++)
    {
        if(strcmp((ds[i].nganh.c_str()),"CNTT")==0 && ds[i].dtb >=8.5 || (strcmp((ds[i].nganh.c_str()),"CNTP")==0) && ds[i].dtb >=8.5)
        {
            cout << "\n";
            xuat1sv(ds[i]);
        }
    }
}

int maxDTB(SINHVIEN ds[],int n)
{
    int max = ds[0].dtb;
    for(int i = 0 ; i<n;i++)
    {
        if(max < ds[i].dtb)
        {
            max = ds[i].dtb;
        }
    }
    return max;
}


void timsv012015(SINHVIEN ds[],int n) // 
{
    for(int i = 0 ;i<n;i++)
    {
        if(strcmp((ds[i].MSSV.c_str()),"012015")==0 && strcmp((ds[i].nganh.c_str()),"CNTT")==0) 
        {
            cout << "\nTim thay sinh vien";
            xuat1sv(ds[i]);
        }
        else
        {
            cout << "\nKhong tim thay sinh vien";
        }
    }
}

int DemNganhHoc(sinhvien a[], int n)
{
    char ds_nganh[100][50];  
    int dem = 0;          

    for (int i = 0; i < n; i++)
    {
        int j;
        for (j = 0; j < dem; j++)
        {
            if (strcmp(a[i].nganh, ds_nganh[j]) == 0)
            {
                break;
            }
        }
        if (j == dem)
        {
            strcpy(ds_nganh[dem], a[i].nganh);
            dem++;
        }
    }
    return dem;
}

void thongkesinhvientheonhomxeploai(SINHVIEN ds[],int n)
{
    for(int i = 0 ;i < n ;i++)
    {
        if(ds[i].dtb >= 8.5)
        {
            cout << "\n\t\tXep loai gioi";
            xuat1sv(ds[i]);
        }
        else
        {
            if(ds[i].dtb >= 7.0)
            {
                cout << "\n\t\tXep loai kha";
                xuat1sv(ds[i]);
            }
            else
            {
                if(ds[i].dtb >= 5.5)
                {
                    cout << "\n\t\tXep loai trung binh";
                    xuat1sv(ds[i]);
                }
                else
                {
                    if(ds[i].dtb>=4.0)
                    {
                        cout << "\n\t\tXep loai trung binh yeu";
                        xuat1sv(ds[i]);
                    }
                    else
                    {
                        cout << "\n\t\tXep loai yeu";
                        xuat1sv(ds[i]);
                    }
                }
            }
        }
    }
}


void menu()
{
    SV sv;
    SINHVIEN SV1, ds[100];
    int n;
    int lc;
    ifstream filein;
    filein.open("./quanlysinhvien.txt",ios::in);
    while(true)
    {
        system("cls");
        cout << "\n\n\t\t===============================QUAN LY SINH VIEN==================================";
        cout << "\n1. Doc ghi file danh sach sinh vien";
        cout << "\n2. Nhap xuat thong tin 1 sinh vien";
        cout << "\n3. Nhap xuat danh sach sinh vien";
        cout << "\n4. Tinh diem chu ( theo tin chi) theo 2 cach tinh";
        cout << "\n5. Xep loai cho sinh vien";
        cout << "\n6. Xuat ds sinh vien thuoc CNTT";
        cout << "\n7. Dem so sinh vien tren 22 tuoi (tinh tu nam 2019)";
        cout << "\n8. Xuat ds sinh vien co que quan o TPHCM";
        cout << "\n9. Thong ke sinh vien loai gioi trong khoa CNTT va CNTP";
        cout << "\n10.Tim sinh vien co diem trung binh cao nhat";
        cout << "\n11.Tim xem khoa CNTT co mssv 012015 hay khong";
        cout << "\n12.Trong danh sach co bao nhieu nganh hoc";
        cout << "\n13.Thong ke sinh vien theo tung nhom xep loai";

        cout << "\nChon: "; cin >> lc;
        if(lc==0)
        {
            exit(1);
            system("pause");
        }
        else if(lc == 1)
        {
            doc_file_danhsach_sinhvien(filein);
            system("pause");
        }
        else if(lc==2)
        {
            nhap1sv(SV1);
            xuat1sv(SV1);
            system("pause");
        }
        else if(lc == 3)
        {
            nhapdanhsachsinhvien(ds,n);
            xuatdanhsachsinhvien(ds,n);
            system("pause");
        }
        else if(lc == 4)
        {
            tinhdiemchu_cach1(ds,n);
            tinhdiemchu_cach2(ds,n);
            system("pause");
        }
        else if(lc == 5)
        {
            xeploai(ds,n);
            system("pause");
        }
        else if(lc ==6)
        {
            xuatcacsinhvienCNTT(ds,n);
            system("pause");
        }
        else if(lc==7)
        {
            cout << "Dem duoc " << demsvtren22tuoi(ds,n) << " sinh vien trong danh sach";
            system("pause");
        }
        else if(lc ==8)
        {
            xuatcacsinhvien_quequan_TPHCM(ds,n);
            system("pause");
        }
        else if(lc == 9)
        {
            thongkesv_gioi_CNTT_CNTP(ds,n);
            system("pause");
        }
        else if(lc == 10)
        {
            cout  << "\nDiem trung binh cao nhat trong ds la " << maxDTB(ds,n);
            system("pause");
        }
        else if(lc == 11)
        {
            timsv012015(ds,n);
            system("pause");
        }
        else if(lc ==12)
        {
            int dem=DemNganhHoc(ds,n);
            cout << "\nCo" << dem << "Nganh hoc";
            system("pause");
        }
        else if(lc==13)
        {
            thongkesinhvientheonhomxeploai(ds,n);
            system("pause");
        }
    }
    filein.close();
}

int main()
{
    menu();
    system("pause");
    return 0;
}