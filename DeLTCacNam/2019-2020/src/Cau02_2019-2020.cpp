#include <iostream>
using namespace std;

class CPhanSo
{
    private:
        int Tu;
        int Mau;
    public:
        CPhanSo(int Tu = 0, int Mau = 1) : Tu(Tu), Mau(Mau) {}
        ~CPhanSo() {}
        friend istream& operator >> (istream& is, CPhanSo& x)
        {
            is >> x.Tu >> x.Mau;
            return is;
        }

        friend ostream& operator << (ostream& os, CPhanSo& x)
        {
            os << x.Tu << "/" << x.Mau << endl;
            return os;
        }

        CPhanSo& operator = (const CPhanSo& x)
        {
            Tu = x.Tu;
            Mau = x.Mau;
            return *this;
        }

        bool operator == (const CPhanSo& x)
        {
            return Tu * x.Mau == Mau * x.Tu;
        }

        friend CPhanSo operator + (const CPhanSo& a, const CPhanSo& b)
        {
            CPhanSo temp(a.Tu * b.Mau + a.Mau * b.Tu, a.Mau * b.Mau);
            return temp;
        }

        friend CPhanSo operator + (int a, const CPhanSo& x)
        {
            CPhanSo temp(a);
            return temp + x;
        }
};

int main()
{
    CPhanSo a(5, 3);
    CPhanSo b, c, kq;
    cin >> b >> c;
    kq = a + b + 5 + c;
    cout << "Ket qua la: " << kq;
    if (a == b)
        cout << "Phan so a bang phan so b" << endl;
    return 0;
}