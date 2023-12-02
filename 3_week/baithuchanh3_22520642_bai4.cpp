#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

struct Stack
{
    stack<int> data;
};

// Khoi tao ngan xep
void createStack(Stack &a)
{
    while (!a.data.empty())
    {
        a.data.pop();
    }
}

// Kiem tra rong
bool Isempty(Stack a)
{
    return a.data.empty();
}

// Them phan tu vao ngan xep
bool Push(Stack &a, int n)
{
    a.data.push(n);
    return true;
}

// Lay phan tu ra ngan xep

bool Pop(Stack &a, int &n)
{
    if (Isempty(a))
    {
        return false;
    }
    n = a.data.top();
    a.data.pop();
    return true;
}

// Chuyen doi tu he so bat ki sang he 10

int sang10(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
    {
        if (ch >= 'a' && ch <= 'z')
        {
            ch = ch - 'a' + 'A';
        }

        return static_cast<int>(ch) - 'A' + 10;
    }

    else if (ch >= '0' && ch <= '9')
    {
        return ch - '0';
    }

    return -1;
}

string chuyentu10(int num, int base)
{
    Stack result;
    createStack(result);

    while (num > 0)
    {
        int remainder = num % base;
        Push(result, remainder);
        num /= base;
    }

    string res = " ";

    while (!Isempty(result))
    {
        int digit = 0;
        Pop(result, digit);
        if (digit < 10)
        {
            res += to_string(digit);
        }
        else
        {
            res += static_cast<char>('A' + digit - 10);
        }
    }
    return res;
}

int main()
{
    int t;
    cout << "Nhap vao so luong phan tu can giai quyet : ";
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int A, B;
        string N;
        cin.ignore();
        cout << "Nhap vao gia tri A, B, N (N o he A sang he B) : ";
        getline(cin, N);
        cin >> A;
        cin >> B;

        int dec = 0;
        int weight = 1;

        for (int j = N.size() - 1; j >= 0; j--)
        {
            int digit = sang10(N[j]);
            if (digit == -1 || digit >= A)
            {
                cout << "Nhap sai gia tri ! ";
                break;
            }
            dec += digit * weight;
            weight *= A;
        }

        if (dec == 0 && N.size() > 0)
        {
            cout << "Nhap sai gia tri ! ";
        }
        else
        {
            string result = chuyentu10(dec, B);
            cout << "Ket qua la : " << result << endl;
        }
    }
    return 0;
}