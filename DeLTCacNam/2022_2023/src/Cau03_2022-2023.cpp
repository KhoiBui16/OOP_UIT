#include <iostream>
#include <string>
#define endl '\n'
using namespace std;

class CNgay
{
    private:
        int Ngay;
        int Thang;
        int Nam;
    public:
        CNgay(int Ngay = 1, int Thang = 1, int Nam =1) : Ngay(Ngay), Thang(Thang), Nam(Nam) {}
        ~CNgay() {}

        int getNgay() { return Ngay; }
        int getThang() { return Thang; }
        int getNam() { return Nam; }

        void setNgay(int Ngay) { this->Ngay = Ngay; }
        void setThang(int Thang) { this->Thang = Thang; }
        void setNam(int Nam) { this->Nam = Nam; }

        void Nhap() {
            cout << "+) Nhap ngay: ";
            cin >> Ngay;
            cout << "+) Nhap thang: ";
            cin >> Thang;
            cout << "+) Nhap nam: ";
            cin >> Nam;
        }

        void Xuat() { 
            cout << Ngay << "/" << Thang << "/" << Nam << endl;
        }

        CNgay& operator = (const CNgay& x) {
            Ngay = x.Ngay;
            Thang = x.Thang;
            Nam = x.Nam;
            return *this;
        }
};

class CKhachKhang 
{
    private:
        string Ma;
        string HoTen;
        string SoDienThoai;
    public:
        CKhachKhang(string Ma = "", string HoTen = "", string SoDienThoai = 0) : Ma(Ma), HoTen(HoTen), SoDienThoai(SoDienThoai) {}
        ~CKhachKhang() {}

        string getMa() { return Ma; }
        string getHoTen() { return HoTen; }
        string getSoDienThoai() { return SoDienThoai; }

        void setMa(string Ma) { this->Ma = Ma; }
        void setHoTen(string HoTen) { this->HoTen = HoTen; }
        void setSoDienThoai(string SoDienThoai) { this->SoDienThoai = SoDienThoai; }

        void Nhap() {
            cout << "+) Nhap ma khach hang: ";
            getline(cin, Ma);
            cout << "+) Nhap ho ten khach hang: ";
            getline(cin, HoTen);
            cout << "+) Nhap so dien thoai khach hang: ";
            cin >> SoDienThoai;
            cin.ignore();
        }

        void Xuat() {
            cout << "- Ma khach hang: " << Ma << endl;
            cout << "- Ho ten khach hang: " << HoTen << endl;
            cout << "- So dien thoai khach hang: " << SoDienThoai << endl;
        }

        CKhachKhang& operator = (const CKhachKhang& x) {
            Ma = x.Ma;
            HoTen = x.HoTen;
            SoDienThoai = x.SoDienThoai;
            return *this;
        }
};

class CSanPham
{
    protected:
        string MaSo;
        string TieuDe;
        double GiaBan;
    public:
        CSanPham(string MaSo = "", string TieuDe = "", double GiaBan = 0) : MaSo(MaSo), TieuDe(TieuDe), GiaBan(GiaBan) {}
        ~CSanPham() {}

        string getMaSo() { return MaSo; }
        string getTieuDe() { return TieuDe; }
        double getGiaBan() { return GiaBan; }

        void setMaSo(string MaSo) { this->MaSo = MaSo; }
        void setTieuDe(string TieuDe) { this->TieuDe = TieuDe; }
        void setGiaBan(double GiaBan) { this->GiaBan = GiaBan; }

        virtual void Nhap() {
            cout << "+) Nhap ma so san pham: ";
            getline(cin, MaSo);
            cout << "+) Nhap tieu de san pham: ";
            getline(cin, TieuDe);
            cout << "+) Nhap gia ban san pham: ";
            cin >> GiaBan;
            cin.ignore();            
        }

        virtual void Xuat() {
            cout << "- Ma so san pham: " << MaSo << endl;
            cout << "- Tieu de san pham: "<< TieuDe << endl;
            cout << "- Gia ban san pham: "<< GiaBan << endl;
        }

        virtual double TongGiaBan() = 0;
};

class CTranhAnh : public CSanPham 
{
    private:
        double ChieuCao;
        double ChieuRong;
        string TenHoaSi;
    public:
        CTranhAnh(double ChieuCao = 0, double ChieuRong = 0, string TenHoaSi = "") : ChieuCao(ChieuCao), ChieuRong(ChieuRong), TenHoaSi(TenHoaSi) {}
        ~CTranhAnh() {}

        double getChieuCao() { return ChieuCao; }
        double getChieuRong() { return ChieuRong; }
        string getTenHoaSi() { return TenHoaSi; }

        void setChieuCao(double ChieuCao) { this->ChieuCao = ChieuCao; }
        void setChieuRong(double ChieuRong) { this->ChieuRong = ChieuRong; }
        void setTenHoaSi(string TenHoaSi) { this->TenHoaSi = TenHoaSi; }

        void Nhap() {
            CSanPham::Nhap();
            cout << "+) Nhap chieu cao tranh anh: ";
            cin >> ChieuCao;
            cout << "+) Nhap chieu rong tranh anh: ";
            cin >> ChieuRong;
            cin.ignore();
            cout << "+) Nhap ten hoa si tranh anh: ";
            getline(cin, TenHoaSi);
        }

        void Xuat() {
            CSanPham::Xuat();
            cout << "- Chieu cao tranh anh: " << ChieuCao << endl;
            cout << "- Chieu rong tranh anh: " << ChieuRong << endl;
            cout << "- Ten hoa si tranh anh: " << TenHoaSi << endl;
        }
        
        double TongGiaBan() { 
            return GiaBan; }
};

class CCD : public CSanPham 
{
    private:
        string TenCaSi;
        string DonViSanXuat;
    public:
        CCD(string TenCaSi = "", string DonViSanXuat = "") : TenCaSi(TenCaSi), DonViSanXuat(DonViSanXuat) {}
        ~CCD() {}
        
        string getTenCaSi() { return TenCaSi; }
        string getDonViSanXuat() { return DonViSanXuat; }

        void setTenCaSi(string TenCaSi) { this->TenCaSi = TenCaSi; }
        void setDonViSanXuat(string DonViSanXuat) { this->DonViSanXuat = DonViSanXuat; }

        void Nhap() {
            CSanPham::Nhap();
            cout << "+) Nhap ten ca si cua CD: ";
            getline(cin, TenCaSi);
            cout << "+) Nhap don vi san xuat cua CD: ";
            getline(cin, DonViSanXuat);
        }

        void Xuat() {
            CSanPham::Xuat();
            cout << "- Ten ca si cua CD: " << TenCaSi << endl;
            cout << "- Don vi san xuat cua CD" << DonViSanXuat << endl;
        }

        double TongGiaBan() {
            return GiaBan;
        }
};

class CHoaDon
{   
    private:
        string MaHoaDon;
        CKhachKhang ThongTinKhachHang;
        CNgay NgayLapHoaDon;
        int SoLuongSanPham;
        CSanPham** DanhsachSanPham;
        double TongGia;
    public:
        CHoaDon(string MaHoaDon = "", int SoLuongSanPham = 0, double TongGia = 0, CSanPham** DanhSachSanPham = NULL) : MaHoaDon(MaHoaDon), TongGia(TongGia) ,SoLuongSanPham(SoLuongSanPham), DanhsachSanPham(DanhSachSanPham) {}

        ~CHoaDon() {
            for (int i = 0; i < SoLuongSanPham; i++)
                delete DanhsachSanPham[i];
            delete[] DanhsachSanPham;
            DanhsachSanPham = NULL;
            SoLuongSanPham = 0;
        }

        string getMaHoaDon() { return MaHoaDon; }
        CKhachKhang getThongTinKhachHang() { return ThongTinKhachHang; }
        CNgay getNgayLapHoa() { return NgayLapHoaDon; }
        int getSoLuongSanPham() { return SoLuongSanPham; }
        double getTongGia() { return TongGia; }

        void setMaHoaDon(string MaHoaDon) { this->MaHoaDon = MaHoaDon; }
        void setThongTinKhachHang(CKhachKhang ThongTinKhachHang) { this->ThongTinKhachHang = ThongTinKhachHang; }
        void setNgayLapHoaDon(CNgay NgayLapHoaDon) { this->NgayLapHoaDon = NgayLapHoaDon; }
        void setSoLuongSanPham(int SoLuongSanPham) { this->SoLuongSanPham = SoLuongSanPham; }
        void setTongGia(double TongGia) { this->TongGia = TongGia; }

        void Nhap() {
            cout << "+) Nhap ma hoa don: ";
            getline(cin, MaHoaDon);
            cout << "+) Nhap thong tin khach hang: " << endl;
            ThongTinKhachHang.Nhap();
            cout << "+) Nhap ngay lap hoa don: " << endl;
            NgayLapHoaDon.Nhap();
            cin.ignore();
            cout << "+) Nhap so luong san pham: ";
            cin >> SoLuongSanPham;
            cin.ignore();
            DanhsachSanPham = new CSanPham* [SoLuongSanPham];
            int loai;
            for (int i = 0; i < SoLuongSanPham; i++)
            {
                cout << "+) Nhap san pham thu " << i + 1 << ": " << endl;
                cout << "+) Chon loai san pham (0. Tranh anh, 1. CD): ";
                cin >> loai;
                cin.ignore();
                if (loai == 0)
                    DanhsachSanPham[i] = new CTranhAnh();
                else
                    DanhsachSanPham[i] = new CCD();
                DanhsachSanPham[i]->Nhap();
            }
        }

        void Xuat() {
            cout << "- Ma hoa don: " << MaHoaDon << endl;
            cout << "- Thong tin cua khach hang: " << endl;
            ThongTinKhachHang.Xuat();
            cout << "- Ngay thanh lap hoa don: ";
            NgayLapHoaDon.Xuat();
            cout << "- So luong san pham: " << SoLuongSanPham << endl;
            for (int i = 0; i < SoLuongSanPham; i++)
            {
                cout << "Thong tin so luong san pham thu " << i + 1 << ": " << endl;
                DanhsachSanPham[i]->Xuat();
            }
            TongGia = TongGiaHoaDon();
            cout << "Tong gia cua hoa don: " << TongGia << endl;
        }

        double TongGiaHoaDon() {
            double Tong = 0;
            for (int i = 0; i < SoLuongSanPham; i++)
                Tong = Tong + DanhsachSanPham[i]->TongGiaBan();
            return Tong;
        }
};

class CCuaHang
{
    private:
        int SoLuongHoaDon;
        CHoaDon* DanhSachHoaDon;
    public:
        CCuaHang(int SoLuongHoaDon = 0, CHoaDon* DanhSachHoaDon = NULL) : SoLuongHoaDon(SoLuongHoaDon), DanhSachHoaDon(DanhSachHoaDon) {}

        ~CCuaHang(){
            delete[] DanhSachHoaDon;
            SoLuongHoaDon = 0;
            DanhSachHoaDon = NULL;
        }

        void Nhap() {
            cout << "+) Nhap so luong hoa don: ";
            cin >> SoLuongHoaDon;
            cin.ignore();
            DanhSachHoaDon = new CHoaDon [SoLuongHoaDon];
            for (int i = 0; i < SoLuongHoaDon; i++)
            {
                cout << "+) Nhap thong tin thu " << i + 1 << ": " << endl;
                DanhSachHoaDon[i].Nhap();
            }
        }

        void Xuat() {
            cout << "- So luong hoa don: " << SoLuongHoaDon << endl;
            for (int i = 0; i < SoLuongHoaDon; i++) 
            { 
                cout << "- Thong tin hoa don thu " << i + 1 << ": " << endl;
                DanhSachHoaDon[i].Xuat();
            }
        }

        double TongGiaTriKhachHangMua(int idx) {
            double TongAi = DanhSachHoaDon[idx].getTongGia();
            for (int i = idx + 1; i < SoLuongHoaDon; i++)
            {
                if (DanhSachHoaDon[idx].getThongTinKhachHang().getMa() == DanhSachHoaDon[i].getThongTinKhachHang().getMa())
                    TongAi += DanhSachHoaDon[i].getTongGia();
            }
            return TongAi;
        }

        double TongGiaTriKhachMuaNhieuNhat()
        {
            long long TongGiaLonNhat = DanhSachHoaDon[0].getTongGia();
            // Tìm khách hàng có tổng giá trị hóa đơn lớn nhất
            for (int i = 0; i < SoLuongHoaDon; i++)
            {
                long long TongAi = TongGiaTriKhachHangMua(i);
                if (TongAi > TongGiaLonNhat)
                    TongGiaLonNhat = TongAi;
            }
            return TongGiaLonNhat;
        }

        void DanhDauHoaDonDaXuLy(int idx, bool* DaXuLyHoaDon)
        {
            for (int j = idx + 1; j < SoLuongHoaDon; j++)
            {
                if (DanhSachHoaDon[j].getThongTinKhachHang().getMa() == DanhSachHoaDon[idx].getThongTinKhachHang().getMa())
                    DaXuLyHoaDon[j] = true; // Đánh dấu các hóa đơn cùng mã khách hàng đã được xử lý
            }
        }

        void DanhSachKhachHangMuaNhieuNhat()
        {
            double TongGiaLonNhat = TongGiaTriKhachMuaNhieuNhat();
            bool* DaXuLyHoaDon = new bool[SoLuongHoaDon];
            for (int i = 0; i < SoLuongHoaDon; i++)
                DaXuLyHoaDon[i] = false; // Khởi tạo mảng đánh dấu, false: chưa xử lý, true: đã xử lý

            // Duyệt qua từng hóa đơn
            for (int i = 0; i < SoLuongHoaDon; i++)
            {
                if (DaXuLyHoaDon[i] == false) 
                {
                    // Tổng giá trị hóa đơn của hóa đơn thứ i
                    long long TongGiaTriHD = TongGiaTriKhachHangMua(i); 
                    // Kiểm tra nếu tổng giá trị hóa đơn của Khách hàng bằng tổng giá trị lớn nhất
                    if (TongGiaTriHD == TongGiaLonNhat)
                    {
                        DanhSachHoaDon[i].Xuat(); // In ra thông tin hóa đơn
                        DaXuLyHoaDon[i] = true; // Đánh dấu hóa đơn đã được xử lý
                        DanhDauHoaDonDaXuLy(i, DaXuLyHoaDon);
                    }
                }
            }
            delete[] DaXuLyHoaDon;
        }
};

int main() 
{
    CCuaHang CuaHang;
    CuaHang.Nhap();
    cout << "\n ----- Thong tin cua hang: " << endl;
    CuaHang.Xuat();
    cout << "\n ----- Danh sach khach mua nhieu nhat: " << endl;
    CuaHang.DanhSachKhachHangMuaNhieuNhat();
    return 1;
}