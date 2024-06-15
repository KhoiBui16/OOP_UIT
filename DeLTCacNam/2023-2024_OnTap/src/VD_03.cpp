#include <iostream>
#include <string>
using namespace std;

class CNgay 
{
    private:
        int Ngay;
        int Thang;
        int Nam;

    public:
        CNgay(int ngay = 1, int thang = 1, int nam = 1) : Ngay(ngay), Thang(thang), Nam(nam) {}

        ~CNgay() {}

        int getNgay() 
        { 
            return Ngay; 
        }

        int getThang() 
        { 
            return Thang; 
        }

        int getNam() 
        { 
            return Nam; 
        }

        void setNgay(int ngay) 
        { 
            Ngay = ngay; 
        }

        void setThang(int thang) 
        { 
            Thang = thang;
        }
        void setNam(int nam) 
        { 
            Nam = nam; 
        }

        void Nhap() 
        { 
            cout << "Nhap ngay: ";
            cin >> Ngay;
            cout << "Nhap thang: ";
            cin >> Thang;
            cout << "Nhap nam: ";
            cin >> Nam;
        }

        void Xuat() 
        { 
            cout << Ngay << "/" << Thang << "/" << Nam << endl; 
        }

        CNgay& operator = (const CNgay& x)
        {
            Ngay = x.Ngay;
            Thang = x.Thang;
            Nam = x.Nam;
            return *this;
        }
};

class CNguoi
{
    private:
        string HoTen;
        string CMND;
        string DiaChiThuongTru;
        int NamSinh;

    public:
        CNguoi(string hoten = "",  string cmnd = "", string diachi = "", int namsinh = 1) : HoTen(hoten), NamSinh(namsinh), CMND(cmnd), DiaChiThuongTru(diachi) {} 
        
        ~CNguoi() {}

        string getHoTen() 
        { 
            return HoTen; 
        }

        string getCMND() 
        { 
            return CMND; 
        }

        string getDiaChiThuongTru() 
        { 
            return DiaChiThuongTru; 
        }

        int getNamSinh() 
        { 
            return NamSinh; 
        }

        void setHoTen(string hoten) 
        { 
            HoTen = hoten; 
        }
        void setCMND(string cmnd) 
        { 
            CMND = cmnd; 
        }

        void setDiaChiThuongTru(string diachi) 
        { 
            DiaChiThuongTru = diachi; 
        }

        void Nhap()
        {
            cout << "Nhap ho ten: ";
            getline(cin, HoTen);
            cout << "Nhap nam : ";
            cin >> NamSinh;
            cout << "Nhap : ";
            cin >> CMND;
            cin.ignore();
            cout << "Nhap dia chi thuong tru: ";
            getline(cin, DiaChiThuongTru);
        }

        void Xuat()
        {
            cout << "Ho ten chu so huu: " << HoTen << endl;
            cout << "Nam sinh chu so huu: " << NamSinh << endl;
            cout << "CMND chu so huu: " << CMND << endl;
            cout << "Dia chi thuong tru chu so huu: " << DiaChiThuongTru << endl;
        }

        CNguoi& operator = (const CNguoi& x)
        {
            HoTen = x.HoTen;
            CMND = x.CMND;
            DiaChiThuongTru = x.DiaChiThuongTru;
            NamSinh = x.NamSinh;
            return *this;
        }
};

class CDat
{
    protected:
        string SoGiayChungNhan;
        int SoNguoiSoHuu;
        CNguoi* DanhSachNguoiSoHuu;
        int SoThuaDat;
        int SoBanDo;
        string DiaChi;
        double DienTich;
        CNgay NgayCap;
        double DonGiaThueTrenMetVuong;

    public:
        CDat(string sogiaychungnhan = "", CNguoi* danhsachnguoisohuu = NULL, int songuoisohuu = 0, int sothuadat = 0, int sobando = 0, string diachi = "", double dientich = 0, CNgay ngaycap = CNgay(), double dongiathue = 0) 
        {
            SoGiayChungNhan = sogiaychungnhan;
            DanhSachNguoiSoHuu = danhsachnguoisohuu;
            SoThuaDat = sothuadat;
            SoBanDo = sobando;
            DiaChi = diachi;
            DienTich = dientich;
            NgayCap = ngaycap;
            DonGiaThueTrenMetVuong = dongiathue;
            SoNguoiSoHuu = songuoisohuu;
        }

        virtual ~CDat() 
        {
            delete[] DanhSachNguoiSoHuu;
            DanhSachNguoiSoHuu = NULL;
        }

        string getSoGiayChungNhan() 
        { 
            return SoGiayChungNhan; 
        }

        int getSoThuaDat() 
        { 
            return SoThuaDat; 
        }

        int getSoBanDo() 
        { 
            return SoBanDo; 
        }

        string getDiaChi() 
        { 
            return DiaChi; 
        }

        double getDienTich() 
        { 
            return DienTich; 
        }

        CNgay getNgay() 
        { 
            return NgayCap;
        }

        double getDonGiaThueTrenMetVuong() 
        { 
            return DonGiaThueTrenMetVuong; 
        }

        void setSoGiayChungNhan(string sogiaychungnhan ) 
        { 
            SoGiayChungNhan = sogiaychungnhan; 
        }

        void setSoThuaDat(int sothuadat) 
        { 
            SoThuaDat = sothuadat; 
        }

        void setSoBanDo(int sobando) 
        { 
            SoBanDo = sobando; 
        }

        void setDiaChi(string diachi) 
        { 
            DiaChi = diachi; 
        }

        void setDienTich(double dientich) 
        { 
            DienTich = dientich; 
        }

        void setNgay(CNgay ngaycap) 
        { 
            NgayCap = ngaycap; 
        }

        void setDonGiaThueTrenMetVuong(double dongiathue) 
        { 
            DonGiaThueTrenMetVuong = dongiathue; 
        }

        virtual void Nhap()
        {
            cout << "Nhap thong tin so giay chung nhan: ";
            getline(cin, SoGiayChungNhan);
            cout << "Nhap so nguoi so huu: ";
            cin >> SoNguoiSoHuu;
            cin.ignore();   
            DanhSachNguoiSoHuu = new CNguoi[SoNguoiSoHuu];
            for (int i = 0; i < SoNguoiSoHuu; i++)
            {
                cout << "Nhap thong tin nguoi so huu thu " << i + 1 << ": " << endl;
                DanhSachNguoiSoHuu[i].Nhap();
            }
            cout << "Nhap so thua dat: ";
            cin >> SoThuaDat;
            cout << "Nhap so ban do: ";
            cin >> SoBanDo;
            cin.ignore();
            cout << "Nhap dia chi dat: ";
            getline(cin, DiaChi);
            cout << "Nhap dien tich dat: ";
            cin >> DienTich;
            cout << "Nhap thong tin ngay cap: " << endl;
            NgayCap.Nhap();
            cout << "Nhap don gia tren 1 met vuong: ";
            cin >> DonGiaThueTrenMetVuong;
        }

        virtual void Xuat()
        {
            cout << "Thong tin so giay chung nhan: " << SoGiayChungNhan << endl;
            cout << "So nguoi so huu: " << SoNguoiSoHuu << endl;
            for (int i = 0; i < SoNguoiSoHuu; i++)
            {
                cout << "Thong tin nguoi so huu thu " << i + 1 << ": " << endl;
                DanhSachNguoiSoHuu[i].Xuat();
            }
            cout << "So thua dat: " << SoThuaDat << endl;
            cout << "So ban do: " << SoBanDo << endl;
            cout << "Dia chi dat: " << DiaChi << endl;
            cout << "Dien tich dat: " << DienTich << endl;
            cout << "Thong tin ngay cap: ";
            NgayCap.Xuat();
            cout << "Don gia tren 1 met vuong la: " << DonGiaThueTrenMetVuong << endl;
        }

        virtual int getLoai() = 0;
        virtual double TienThueSuDungDat() = 0;
        virtual int ThoiHanSuDungDat() = 0;
};

class CDatNongNghiep : public CDat
{
    private:
        int ThoiHanSuDung;

    public:
        CDatNongNghiep(string sogiaychungnhan = "", CNguoi* nguoisohuu = NULL, int songuoisohuu = 0,int sothuadat = 0, int sobando = 0, string diachi = "", double dientich = 0, CNgay ngaycap = CNgay(), double dongiathue = 0 ,int thoihansudung = 0) : CDat(sogiaychungnhan, nguoisohuu, songuoisohuu, sothuadat, sobando, diachi, dientich, ngaycap, dongiathue), ThoiHanSuDung(thoihansudung) {}

        ~CDatNongNghiep() {}

        int getThoiHanSuDung()
        {
            return ThoiHanSuDung;
        }

        void setThoiHanSuDung(int thoihansudung)
        {
            ThoiHanSuDung = thoihansudung;
        }

        void Nhap()
        {
            CDat::Nhap();
            cout << "Nhap thoi han su dung dat(theo nam): ";
            cin >> ThoiHanSuDung;
        }

        void Xuat()
        {
            CDat::Xuat();
            cout << "Thoi han su dung dat(theo nam): " << ThoiHanSuDung << endl;
            cout << "Tien thue su dung dat: " << TienThueSuDungDat() << endl;
        }

        int getLoai()
        {
            return 1;
        }

        double TienThueSuDungDat()
        {
            return DonGiaThueTrenMetVuong * DienTich;
        }

        int ThoiHanSuDungDat()
        {
            return ThoiHanSuDung + NgayCap.getNam();
        }
};

class CDatPhiNongNghiep : public CDat
{
    public:
        CDatPhiNongNghiep(string sogiaychungnhan = "", CNguoi* nguoisohuu = NULL, int songuoisohuu = 0,int sothuadat = 0, int sobando = 0, string diachi = "", double dientich = 0, CNgay ngaycap = CNgay(), double dongiathue = 1 ,int thoihansudung = 0) : CDat(sogiaychungnhan, nguoisohuu, songuoisohuu, sothuadat, sobando, diachi, dientich, ngaycap, dongiathue) {}

        ~CDatPhiNongNghiep() {}

        void Nhap()
        {
            CDat::Nhap();
        }

        void Xuat()
        {
            CDat::Xuat();
            cout << "Tien thue su dung dat: " << TienThueSuDungDat() << endl;
        }

        int getLoai()
        {
            return 2;
        }

        double TienThueSuDungDat()
        {
            return DonGiaThueTrenMetVuong * DienTich;
        }

        int ThoiHanSuDungDat()
        {
            return 1e9;
        }
};

class CNhaNuoc
{
    private:
        int SoLuongDat;
        CDat** DanhSach;

    public: 
        CNhaNuoc(int n = 0, CDat** ds = NULL) : SoLuongDat(n), DanhSach(ds) {}

        ~CNhaNuoc() 
        {
            for (int i = 0; i < SoLuongDat; i++)
                delete DanhSach[i];
            delete[] DanhSach;
            DanhSach = NULL;
        }

        void Nhap()
        {
            cout << "Nhap so luong dat: ";
            cin >> SoLuongDat; 
            cin.ignore();
            DanhSach = new CDat*[SoLuongDat];
            int loai;
            for (int i = 0; i < SoLuongDat; i++)
            {
                cout << "Nhap thua dat thu " << i + 1 << ": " << endl;
                cout << "Nhap loai dat (0. Dat nong nghiep, 1. Dat phi nong nghiep): ";
                cin >> loai;
                cin.ignore();
                if (loai == 0) 
                    DanhSach[i] = new CDatNongNghiep();
                else 
                    DanhSach[i] = new CDatPhiNongNghiep();
                DanhSach[i]->Nhap();
            }
        }

        void Xuat()
        {
            cout << "So luong thua dat: " << SoLuongDat << endl;
            for (int i = 0; i < SoLuongDat; i++)
            {
                cout << '\n';
                cout << "Thong tin thua dat thu " << i + 1 << ": " << endl;
                DanhSach[i]->Xuat();
            }
        }

        double TienThueSuDungDat()
        {
            double tong = 0;
            for (int i = 0; i < SoLuongDat; i++)
                tong += DanhSach[i]->TienThueSuDungDat();
            return tong;
        }

        CDat* ThuaDatDongTienThueNhieuNhat()
        {
            CDat* ThuaDatNhieuNhat = DanhSach[0];
            for (int i = 1; i < SoLuongDat; i++)
                if (DanhSach[i]->TienThueSuDungDat() > ThuaDatNhieuNhat->TienThueSuDungDat())
                    ThuaDatNhieuNhat = DanhSach[i];
            return ThuaDatNhieuNhat;
        }

        void DanhSachDatNongNghiepHetHanSuDung(int NamHienTai, int& SoDatHethan)
        {
            for (int i = 0; i < SoLuongDat; i++)
                if (DanhSach[i]->getLoai() == 1 && DanhSach[i]->ThoiHanSuDungDat() < NamHienTai)
                {
                    DanhSach[i]->Xuat();
                    SoDatHethan++;
                }
        }
};

int main()
{
    CNhaNuoc NhaNuoc;
    cout << "+) Nhap thong tin dat nha nuoc quan ly: " << endl;
    NhaNuoc.Nhap();

    cout << "\n+) Thong tin dat nha nuoc quan ly la: " << endl;
    NhaNuoc.Xuat();

    cout << "\n+) Tien thue phai dong cho nha nuoc: ";
    double TienThueDongChoNhaNuoc = NhaNuoc.TienThueSuDungDat();
    cout << TienThueDongChoNhaNuoc << endl;

    cout << "\n+) Thua dat dong thue nhieu nhat la: " << endl;
    NhaNuoc.ThuaDatDongTienThueNhieuNhat()->Xuat();

    cout << "\n+) Nhap nam hien tai de tim kiem thua dat het han su dung dat (theo nam): ";
    int NamHienTai, SoDatHetHan = 0;
    cin >> NamHienTai;
    cin.ignore();

    cout << "+) Danh sach cac thua dat nong nghiep het han: ";
    NhaNuoc.DanhSachDatNongNghiepHetHanSuDung(NamHienTai, SoDatHetHan);
    if (SoDatHetHan == 0)
        cout << "Chua co dat het han!";
    return 0;
}