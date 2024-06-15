#include <iostream>
#include <cmath>
#define endl '\n'
using namespace std;

class CDonThuc
{
    private:
        double HeSo, SoMu;
    public:
        CDonThuc(double HeSo = 0, double SoMu = 0) : HeSo(HeSo), SoMu(SoMu) {}
        ~CDonThuc() {}
        double getHeSo() { return HeSo; }
        double getSoMu() { return SoMu; }
        void setHeSo(double HeSo) { this->HeSo = HeSo; }
        void setSoMu(double SoMu) {this->SoMu = SoMu; }
        double GiaTriDonThuc(double x) {
            return HeSo * pow(x, SoMu);
        }
        CDonThuc operator + (const CDonThuc& x) {
            CDonThuc temp(HeSo + x.HeSo, SoMu);
            return temp;
        }
};

int main()
{
    CDonThuc a(1, 2);
    CDonThuc b;
    cout << a.GiaTriDonThuc(2);
    return 0;
}