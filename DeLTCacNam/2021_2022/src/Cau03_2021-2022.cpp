#include <iostream>
#include <string>
using namespace std;

class Sach
{
    protected:
        string maSach;
        string tenSach;
        string nhaXuatBan;
        int soLuong;
        double donGia;

    public:
        Sach(const string& ms = "", const string& ts = "", const string& nxb = "", int soLuong = 0, double donGia = 0)
            : maSach(ms), tenSach(ts), nhaXuatBan(nxb), soLuong(soLuong), donGia(donGia){}

        virtual ~Sach(){}

        string getMaSach(){return maSach;}
        string getTenSach(){return tenSach;}
        string getNhaXuatBan(){return nhaXuatBan;}
        virtual int getSoLuong() = 0;
        double getDonGia(){return donGia;}

        void setMaSach(string x){maSach = x;}
        void setTenSach(string x){tenSach = x;}
        void setNhaXuatBan(string x){nhaXuatBan = x;}
        void setSoLuong(int x){soLuong = x;}
        void setDonGia(double x){donGia = x;}

        virtual void Nhap()
        {
            cout << "Nhap ma sach: ";
            getline(cin, maSach);
            cout << "Nhap ten sach: ";
            getline(cin , tenSach);
            cout << "Nhap nha xuat ban: ";
            getline(cin, nhaXuatBan);
            cout << "Nhap so luong: ";
            cin >> soLuong;
            cout << "Nhap don gia: ";
            cin >> donGia;
        }

        virtual void Xuat()
        {
            cout << "Ma sach: " << maSach << endl;
            cout << "Ten sach: " << tenSach << endl;
            cout << "Nha xuat ban: " << nhaXuatBan << endl;
            cout << "So luong: " << soLuong << endl;
            cout << "Don gia: " << donGia << endl;
        }

        virtual double ThanhTien() = 0;
        virtual int getLoai() = 0;
};

class SGK : public Sach
{
    private:
        int tinhTrang;

    public:
        SGK(const string& ms = "", const string& ts = "", const string& nxb = "", int soLuong = 0, double donGia = 0, int tt = -1)
            : Sach(ms, ts, nxb, soLuong, donGia), tinhTrang(tt){}

        ~SGK(){}

        int getSoLuong(){return soLuong;}
        int getTinhTrang(){return tinhTrang;}
        void setTinhTrang(int x){tinhTrang = x;}

        void Nhap()
        {
            Sach::Nhap();
            cout << "Nhap tinh trang: ";
            cin >> tinhTrang;
        }

        void Xuat()
        {
            Sach::Xuat();
            if(tinhTrang == 0) cout << "Tinh trang: Moi" << "\n";
            else if(tinhTrang == 1) cout << "Tinh trang: Cu" << "\n";
        }

        double ThanhTien() 
        {
            if (tinhTrang == 1)
                return soLuong * donGia;
            else
                return soLuong * donGia * 0.5;
        }

        int getLoai() 
        {
            return 1;
        }
};

class STK : public Sach
{
    private:
        double tienThue;
    public:
        STK(const string& ms = "", const string& ts = "", const string& nxb = "", int soLuong = 0, double donGia = 0, double tt = -1)
            : Sach(ms, ts, nxb, soLuong, donGia), tienThue(tt){}

        ~STK(){}

        int getSoLuong(){return soLuong;}
        double getTienThue(){return tienThue;}
        void setTienThue(double x){tienThue = x;}

        void Nhap()
        {
            Sach::Nhap();
            cout << "Nhap tien thue: ";
            cin >> tienThue;
        }

        void Xuat()
        {
            Sach::Xuat();
            cout << "Tien thue: " << tienThue << "\n";
        }

        double ThanhTien() 
        {
            return soLuong * donGia + tienThue;
        }

        int getLoai() 
        {
            return 2;
        }
};

class ThuVien
{
    private:
        Sach **ds;
        int soLuong;
    public:
        ThuVien(int SoLuong = 0, Sach** ds = NULL) : soLuong(SoLuong), ds(new Sach*[SoLuong]) {}

        ~ThuVien() 
        {
            for (int i = 0; i < soLuong; i++)
                delete ds[i];
            delete[] ds;
            ds = NULL;
        }
        
        void Nhap() 
        {
            cout << "Nhap so luong: ";
            cin >> soLuong;
            int loai;
            for (int i = 0; i < soLuong; i++) 
            {
                cout << "Nhap loai sach (0. SGK, 1. STK): ";
                cin >> loai;
                cin.ignore();
                if (loai == 0)
                    ds[i] = new SGK();
                else
                    ds[i] = new STK();
                ds[i]->Nhap();
            }
        }

        void Xuat() 
        {
            cout << "So luong: " << soLuong << endl;
            for (int i = 0; i < soLuong; i++) 
                ds[i]->Xuat();
        }

        double ThanhTienSGK() 
        {
            double tong = 0;
            for (int i = 0; i < soLuong; i++) 
                if (ds[i]->getLoai() == 1) 
                    tong += ds[i]->ThanhTien();
            return tong;
        }

        double ThanhTienStk() 
        {
            double tong = 0;
            for (int i = 0; i < soLuong; i++) 
                if (ds[i]->getLoai() == 2) 
                    tong += ds[i]->ThanhTien();
            return tong;
        }

        double ThanhTienSGKNhoNhat() 
        {
            double giaNhoNhat = ds[0]->ThanhTien();
            for (int i = 1; i < soLuong; i++) 
                if (ds[i]->ThanhTien() < giaNhoNhat)
                    giaNhoNhat = ds[i]->ThanhTien();
            return giaNhoNhat;
        }

        void TimKiemSachThanhTien() 
        {
            double minGia = ThanhTienSGK();
            for (int i = 0; i < soLuong; i++) 
                if (ds[i]->ThanhTien() == minGia)
                    ds[i]->Xuat();
        }

        void TimKiemTenNXB(string s) 
        {
            for (int i = 0; i < soLuong; i++) 
                if (ds[i]->getNhaXuatBan().compare(s) == 0)
                    ds[i]->Xuat();
        }
};

int main() 
{
    ThuVien tv;
    tv.Nhap();
    tv.Xuat();
    string x;
    cin.ignore();
    getline(cin, x);
    tv.TimKiemTenNXB(x);
    return 0;
}