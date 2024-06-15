#include <iostream>
#include <string>
using namespace std;

class CVe
{
    protected:
        string MaVe;
        string HoTen;
        int NamSinh;
        long long GiaVe;
        int SoTroChoi;

    public:
        CVe(string mave = "", string hoten = "", int namsinh = 1, long long giave = 0, int sotrochoi = 0) : MaVe(mave), HoTen(hoten), NamSinh(namsinh), GiaVe(giave), SoTroChoi(sotrochoi) {}

        virtual ~CVe() {}

        virtual void Nhap()
        {
            cout << "Nhap ma ve: ";
            cin >> MaVe;
            cin.ignore();
            cout << "Nhap ho ten chu ve: ";
            getline(cin, HoTen);
            cout << "Nhap nam sinh chu ve: ";
            cin >> NamSinh;
            cin.ignore();
        }

        virtual void Xuat()
        {
            cout << "Ma ve: " << MaVe << endl;
            cout << "Ho ten chu ve: " << HoTen << endl;
            cout << "Nam sinh chu ve: " << NamSinh << endl;
        }

        virtual long long getGiaVe() = 0;
        virtual void setGiaVe(long long) = 0;
        virtual int getSoTroChoi() = 0;
        virtual void setSoTroChoi(int SoTroChoi) = 0;
        virtual int getLoai() = 0;
        virtual int SoVeTronGoi() = 0;
        virtual int SoVeTungPhan() = 0;

        string getMaVe() 
        {
            return MaVe;
        }

        string getHoTen()
        {
            return HoTen;
        }

        int getNamSinh()
        {
            return NamSinh;
        }

        void setMaVe(string MaVe)
        {
            this->MaVe = MaVe;
        }

        void setHoTen(string HoTen)
        {
            this->HoTen = HoTen;
        }

        void setNamSinh(int NamSinh)
        {
            this->NamSinh = NamSinh;
        }
};

class CVeTronGoi : public CVe
{
    public:
        CVeTronGoi(string mave = "", string hoten = "", int namsinh = 1, long long giave = 0, int sotrochoi = 0) : CVe(mave, hoten, namsinh, giave, sotrochoi) {}

        ~CVeTronGoi() {}
        
        void Nhap()
        {
            CVe::Nhap();
            cout << "Nhap gia ve tron goi: ";
            cin >> GiaVe;
            cout << "Nhap so tro choi tron goi: ";
            cin >> SoTroChoi;
            cin.ignore();
        }

        void Xuat()
        {
            CVe::Xuat();
            cout << "Gia ve tron goi: " << GiaVe << endl;
            cout << "So tro choi tron goi: " << SoTroChoi << endl;
        }

        long long getGiaVe()
        {
            return GiaVe;
        }

        void setGiaVe(long long GiaVe)
        {
            this->GiaVe = GiaVe;
        }
        
        int getSoTroChoi()
        {
            return SoTroChoi;
        }

        void setSoTroChoi(int SoTroChoi)
        {
            this->SoTroChoi = SoTroChoi;
        }

        int getLoai()
        {
            return 1;
        }

        int SoVeTronGoi()
        {
            return 1;
        }

        int SoVeTungPhan()
        {
            return 0;
        }
};

class CVeTungPhan : public CVe
{
    public:
        CVeTungPhan(string mave = "", string hoten = "", int namsinh = 1, long long giave = 0, int sotrochoi = 0) : CVe(mave, hoten, namsinh, giave, sotrochoi) {}

        ~CVeTungPhan() {}
        
        void Nhap()
        {
            CVe::Nhap();
            cout << "Nhap gia ve tung phan: ";
            cin >> GiaVe;
            cout << "Nhap so tro tung phan: ";
            cin >> SoTroChoi;
            cin.ignore();
        }

        void Xuat()
        {
            CVe::Xuat();
            cout << "Gia ve tung phan (gia ve vao cong): " << GiaVe << endl;
            cout << "So tro choi thanh phan: " << SoTroChoi << endl;
            cout << "Tong gia ve tung phan (so tro choi * 20000 choi + gia ve tung phan): " << getGiaVe() << endl;
        }

        long long getGiaVe()
        {
            return GiaVe + (SoTroChoi * 20000);
        }

        void setGiaVe(long long GiaVe)
        {
            this->GiaVe = GiaVe;
        }

        int getSoTroChoi()
        {
            return SoTroChoi;
        }

        void setSoTroChoi(int SoTroChoi)
        {
            this->SoTroChoi = SoTroChoi;
        }

        int getLoai()
        {
            return 2;
        }

        int SoVeTronGoi()
        {
            return 0;
        }

        int SoVeTungPhan()
        {
            return 1;
        }
};

class CCongVien
{
    private:
        int SoLuongVe;
        CVe** DanhSach;

    public:
        CCongVien(int soluongve = 0, CVe** ds = NULL) : SoLuongVe(soluongve), DanhSach(ds) {}

        ~CCongVien()
        {
            for (int i = 0; i < SoLuongVe; i++)
                delete DanhSach[i];
            delete[] DanhSach;
            DanhSach = NULL;
        }

        void Nhap()
        {
            cout << "Nhap so ve: ";
            cin >> SoLuongVe;
            DanhSach = new CVe*[SoLuongVe];
            int loai;
            for (int i = 0; i < SoLuongVe; i++)
            {
                cout << "Nhap ve thanh phan thu " << i + 1 << ": " << endl;
                cout << "Nhap loai ve (0. Ve tron goi, 1. Ve tung phan): ";
                cin >> loai;
                cin.ignore();
                if (loai == 0)
                    DanhSach[i] = new CVeTronGoi();
                else
                    DanhSach[i] = new CVeTungPhan();
                DanhSach[i]->Nhap();
            }
        }

        void Xuat()
        {
            cout << "So ve la: " << SoLuongVe << endl;
            for (int i = 0; i < SoLuongVe; i++)
            {
                cout << "\nThong tin ve thanh phan thu " << i + 1 << ": " << endl;
                DanhSach[i]->Xuat();
            }
        }

        long long TongVeTungPhan()
        {
            long long tong = 0;
            for (int i = 0; i < SoLuongVe; i++)
            {
                if (DanhSach[i]->getLoai() == 2)
                    tong += DanhSach[i]->getGiaVe();
            }
            return tong;
        }

        long long GiaVeTungPhanCaoNhat()
        {
            long long GiaVeCaoNhat = 0;
            for (int i = 0; i < SoLuongVe; i++)
            {
                if (DanhSach[i]->getLoai() == 2 && DanhSach[i]->getGiaVe() > GiaVeCaoNhat)
                    GiaVeCaoNhat = DanhSach[i]->getGiaVe();
            }
            return GiaVeCaoNhat;
        }

        void DanhSachVeTungPhanCaoNhat()
        {
            long long GiaVeCaoNhat = GiaVeTungPhanCaoNhat();
            for (int i = 0; i < SoLuongVe; i++)
            {
                if (DanhSach[i]->getLoai() == 2 && DanhSach[i]->getGiaVe() == GiaVeCaoNhat)
                    DanhSach[i]->Xuat();
            }
        }

        int SoLuongGiaVeTronGoi()
        {
            int dem = 0;
            for (int i = 0; i < SoLuongVe;i++)
                dem += DanhSach[i]->SoVeTronGoi();
            return dem;
        }

        int SoLuongGiaVeTungPhan()
        {
            int dem = 0;
            for (int i = 0; i < SoLuongVe;i++)
                dem += DanhSach[i]->SoVeTungPhan();
            return dem;
        }

        void SapXepDanhSachCacVe()
        {
            for (int i = 0; i < SoLuongVe - 1; i++)
            {
                for (int j = i + 1; j < SoLuongVe; j++)
                {
                    if (DanhSach[i]->getLoai() != DanhSach[j]->getLoai())
                    {
                        if (DanhSach[i]->getLoai() == 2)
                            swap(DanhSach[i], DanhSach[j]);
                    }
                    else 
                    {
                        if (DanhSach[i]->getLoai() == 1 && DanhSach[i]->getMaVe() > DanhSach[j]->getMaVe())
                            swap(DanhSach[i], DanhSach[j]);
                        else
                            if (DanhSach[i]->getGiaVe() < DanhSach[j]->getGiaVe())
                                swap(DanhSach[i], DanhSach[j]);
                    }
                }
            }
        }
};

int main()
{
    CCongVien cv;
    cout << "Nhap thong tin cong vien van hoa Dam Sen: " << endl;
    cv.Nhap();

    cout << "\nThong tin cong vien van hoa Dam sen: " << endl;
    cv.Xuat();

    cout << "\nTong ve tung phan cong vien van hoa Dam Sen thu duoc: ";
    long long TongVeTungPhan = cv.TongVeTungPhan();
    cout << TongVeTungPhan << endl;

    cout << "\nDanh sach cac ve tung phan co gia ve cao nhat: " << endl;
    cv.DanhSachVeTungPhanCaoNhat();

    cout << "\nSo luong ve tron goi cong vien da ban: ";
    long long SoLuongVeTronGoi = cv.SoLuongGiaVeTronGoi();
    cout << SoLuongVeTronGoi << endl;

    cout << "\nSo luong ve tung phan cong vien da ban: ";
    long long SoLuongVeTungPhan = cv.SoLuongGiaVeTungPhan();
    cout << SoLuongVeTungPhan << endl;

    cout << "\nDanh sach cac ve sau khi sap xep theo yeu cau: " << endl;
    cv.SapXepDanhSachCacVe();
    cv.Xuat();
    return 0;
}