#include <iostream>
#include <stack>
#include <math.h>
using namespace std;

int ChuyenSangHeSo10(string num, int base)
{
    int coso10 = 0;
    int somu = 0;

    stack<int> nganXep;
    for (char chuSo : num)
    {
        int giatri = 0;
        if (chuSo >= '0' && chuSo <= '9')
        {
            giatri = chuSo - '0';
        }
        else if (chuSo >= 'A' && chuSo <= 'F')
        {
            giatri = chuSo - 'A' + 10;
        }
        else if (chuSo >= 'a' && chuSo <= 'f')
        {
            giatri = chuSo - 'a' + 10;
        }
        nganXep.push(giatri);
    }
    while (!nganXep.empty())
    {
        int giaTri = nganXep.top();
        nganXep.pop();
        coso10 += giaTri * static_cast<int>(pow(base, somu));
        somu++;
    }
    return coso10;
}

string chuyenDoiSangCoSoKhac(int so, int base)
{
    stack<int> nganXepKetQua;

    while (so > 0)
    {
        int du = so % base;
        nganXepKetQua.push(du);
        so /= base;
    }

    string ketQua = "";
    while (!nganXepKetQua.empty())
    {
        int chuSo = nganXepKetQua.top();
        nganXepKetQua.pop();
        if (chuSo < 10)
        {
            ketQua += to_string(chuSo);
        }
        else
        {
            ketQua += char('A' + chuSo - 10);
        }
    }

    return ketQua;
}

int main()
{
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int A, B;
        string N;
        cin.ignore();
        cin >> N;
        cin >> A >> B;
        int coSo10 = ChuyenSangHeSo10(N, A);
        string ketQua = chuyenDoiSangCoSoKhac(coSo10, B);
        cout << ketQua << endl;
    }

    return 0;
}