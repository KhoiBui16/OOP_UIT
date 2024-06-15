#include <iostream>
#include <string>
using namespace std;

class CNhanVien
{
    protected:
        string Ma;
        string HoTen;
        int Tuoi;
        string SDT;
        string Email;
        double LuongCoban;

    public:
        CNhanVien(string ma = "", string hoten = "", int tuoi = 0, string sdt = "", string email = "@gmail", double luongcoban = 0) 
        {
            Ma = ma;
            HoTen = hoten;
            Tuoi = tuoi;
            SDT = sdt;
            Email = email;
            LuongCoban = luongcoban;
        }
        
        string getMa()
        {
            return Ma;
        }
        
        void setMa(string ma)
        {
            Ma = ma;
        }

        string getHoTen()
        {
            return HoTen;
        }

        void setHoTen(string hoten)
        {
            HoTen = hoten;
        }

        int getTuoi()
        {
            return Tuoi;
        }

        void setTuoi(int tuoi)
        {
            Tuoi = tuoi;
        }

        string getSDT()
        {
            return SDT;
        }

        void setSDT(string sdt)
        {
            SDT = sdt;
        }

        string getEmail()
        {
            return Email;
        }

        void setEmail(string email)
        {
            Email = email;
        }

        double getLuongCoBan()
        {
            return LuongCoban;
        }

        void getLuongCoBan(double luongcoban)
        {
            LuongCoban = luongcoban;
        }

        virtual ~CNhanVien() {}

        virtual void Nhap()
        {
            cout << "Nhap ma: ";
            getline(cin, Ma);
            cout << "Nhap ho ten: ";
            getline(cin, HoTen);
            cout << "Nhap tuoi: ";
            cin >> Tuoi;
            cin.ignore();
            cout << "Nhap so dien thoai: ";
            cin >> SDT;
            cout << "Nhap Email: ";
            cin >> Email;
            cout << "Nhap luong co ban: ";
            cin >> LuongCoban;
        }

        virtual void Xuat()
        {
            cout << "Ma: " << Ma << endl;
            cout << "Ho ten: " << HoTen << endl;
            cout << "Tuoi: " << Tuoi << endl;
            cout << "So dien thoai: " << SDT << endl;
            cout << "Email: " << Email << endl;
            cout << "Luong co ban: " << LuongCoban << endl;
        }

        virtual double LuongThang() = 0;
};

class CLapTrinhVien : public CNhanVien
{
    private:
        int SoGioLamThem;

    public:
        CLapTrinhVien(string ma = "", string hoten = "", int tuoi = 0, string sdt = "", string email = "@gmail", double luongcoban = 0, int sogiolamthem = 0)
        {
            Ma = ma;
            HoTen = hoten;
            Tuoi = tuoi;
            SDT = sdt;
            Email = email;
            LuongCoban = luongcoban;
            SoGioLamThem = sogiolamthem;
        }

        ~CLapTrinhVien() {}

        int getSoGioLamThem()
        {
            return SoGioLamThem;
        }
        
        void setSoGioLamThem(int sogiolamthem)
        {
            SoGioLamThem = sogiolamthem;
        }

        void Nhap()
        {
            CNhanVien::Nhap();
            cout << "Nhap so gio lam them: ";
            cin >> SoGioLamThem;
        }

        void Xuat()
        {
            CNhanVien::Xuat();
            cout << "So gio lam them cua lap trinh vien: " << SoGioLamThem << endl;
            cout << "Luong thang cua lap trinh vien: " << LuongThang() << endl;
        }

        double LuongThang()
        {
            return LuongCoban + SoGioLamThem * 200000;
        }
};

class CKiemChungVien : public CNhanVien
{
    private:
        int SoLoiPhatHien;

    public:
        CKiemChungVien(string ma = "", string hoten = "", int tuoi = 0, string sdt = "", string email = "@gmail", double luongcoban = 0, int soloiphathien = 0)
        {
            Ma = ma;
            HoTen = hoten;
            Tuoi = tuoi;
            SDT = sdt;
            Email = email;
            LuongCoban = luongcoban;
            SoLoiPhatHien = soloiphathien;
        }

        ~CKiemChungVien() {}

        int getSoLoiPhatHien()
        {
            return SoLoiPhatHien;
        }

        void setSoLoiPhatHien(int soloiphathien)
        {
            SoLoiPhatHien = soloiphathien;
        }

        void Nhap()
        {
            CNhanVien::Nhap();
            cout << "Nhap so loi phat hien: ";
            cin >> SoLoiPhatHien;
        }

        void Xuat()
        {
            CNhanVien::Xuat(); 
            cout << "So loi phat hien cua kiem chung vien: " << SoLoiPhatHien << endl;
            cout << "Luong thang cua kiem chung vien: " << LuongThang() << endl;
        }

        double LuongThang()
        {
            return LuongCoban + SoLoiPhatHien * 50000;
        }
};

class CCongTy
{
    private:
        int SoLuongNhanVien;
        CNhanVien** DanhSach;

    public:
        CCongTy(int n = 0, CNhanVien** ds = NULL) : SoLuongNhanVien(n), DanhSach(ds) {}

        ~CCongTy()
        {
            for (int i = 0; i < SoLuongNhanVien; i++)
                delete DanhSach[i];
            delete[] DanhSach;
            DanhSach = NULL;
        }

        void Nhap()
        {
            cout << "Nhap so luong nhan vien co trong cong ty: ";
            cin >> SoLuongNhanVien;
            DanhSach = new CNhanVien*[SoLuongNhanVien];
            int loai;
            for (int i = 0; i < SoLuongNhanVien; i++)
            {
                cout << "Nhap thong tin nhan vien thu " << i + 1 << ": " << endl;
                cout << "Nhap loai nhan vien (0. Lap trinh vien, 1. Kiem chung vien): ";
                cin >> loai;
                cin.ignore();
                if (loai == 0)
                    DanhSach[i] = new CLapTrinhVien();
                else
                    DanhSach[i] = new CKiemChungVien();
                DanhSach[i]->Nhap();
            }
        }

        void Xuat()
        {
            cout << "So luong nhan vien co trong cong ty: " << SoLuongNhanVien << endl;
            for (int i = 0; i < SoLuongNhanVien; i++)
            {
                cout << endl;
                cout << "Thong tin nhan vien thu " << i + 1 << ": " << endl;
                DanhSach[i]->Xuat();
            }
        }

        double MucLuongTrungBinh()
        {
            double tong = 0;
            for (int i = 0; i < SoLuongNhanVien; i++)
                tong += DanhSach[i]->LuongThang();
            return (double)tong / SoLuongNhanVien;
        }

        void DanhSachNhanVienLuongThapHonMucTrungBinh()
        {
            double LuongTrungBinh = MucLuongTrungBinh();
            for (int i = 0; i < SoLuongNhanVien; i++)
            {
                if (DanhSach[i]->LuongThang() < LuongTrungBinh)
                    DanhSach[i]->Xuat();
            }
        }

        void TimCacNhanVienCoMucLuongToiThieu(double luong, bool& flag)
        {
            for (int i = 0; i < SoLuongNhanVien; i++)
            {
                if (DanhSach[i]->LuongThang() == luong)
                {
                    flag = true;
                    DanhSach[i]->Xuat();
                }
            }
        }
};

int main()
{
    CCongTy Cty;
    cout << "Nhap thong tin cua cong ty: " << endl;
    Cty.Nhap();
    
    cout << "\nThong tin cua cong ty: " << endl;
    Cty.Xuat();

    cout << "\nMuc luong trung binh cua nhan vien trong cong ty: ";
    double LuongTrungBinh = Cty.MucLuongTrungBinh();
    cout << LuongTrungBinh << endl;

    cout << "\nDanh sach cac nhan vien co muc luong thap hon muc luong trung binh cua nhan vien: " << endl;
    Cty.DanhSachNhanVienLuongThapHonMucTrungBinh();

    cout << "\nMuc luong nhan vien toi thieu can tim: ";
    double LuongToiThieu;
    cin >> LuongToiThieu;
    bool flag = false;
    Cty.TimCacNhanVienCoMucLuongToiThieu(LuongToiThieu, flag);
    if (flag == false)
        cout << "\nKhong tim thay!";

    return 0;
}