#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

struct Stack
{
    stack<int> data;
};

void createStack(Stack &s)
{
    while (!s.data.empty())
    {
        s.data.pop();
    }
}

bool IsEmpty(Stack s)
{
    return s.data.empty();
}

bool Push(Stack &s, int x)
{
    s.data.push(x);
    return true;
}

bool Pop(Stack &s, int &x)
{
    if (IsEmpty(s))
    {
        return false;
    }

    x = s.data.top();
    s.data.pop();
    return true;
}

int ConvertToDecimal(string num, int base)
{
    int decimal = 0;
    int exponent = 0;

    for (int i = num.size() - 1; i >= 0; --i)
    {
        int digitValue = 0;
        if (isdigit(num[i]))
        {
            digitValue = num[i] - '0';
        }
        else if (isalpha(num[i]))
        {
            digitValue = toupper(num[i]) - 'A' + 10;
        }
        else
        {
            cout << "Invalid input!" << endl;
            return -1;
        }

        decimal += digitValue * static_cast<int>(pow(base, exponent));
        exponent++;
    }

    return decimal;
}

string ConvertFromDecimal(int num, int base)
{
    Stack resultStack;
    createStack(resultStack);

    while (num > 0)
    {
        int remainder = num % base;
        Push(resultStack, remainder);
        num /= base;
    }

    string result = "";
    while (!IsEmpty(resultStack))
    {
        int digit = 0;
        Pop(resultStack, digit);
        if (digit < 10)
        {
            result += to_string(digit);
        }
        else
        {
            result += static_cast<char>('A' + digit - 10);
        }
    }

    return result;
}

int main()
{
    int T;
    cout << "Nhap vao so luong phan tu can giai quyet : ";
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int A, B;
        string N;
        cin.ignore();
        cout << "Nhap gia tri A, B, C (A thuoc he B, doi sang he C) : " << endl;
        cin >> N >> A >> B;

        int decimalValue = ConvertToDecimal(N, A);
        if (decimalValue != -1)
        {
            string result = ConvertFromDecimal(decimalValue, B);
            cout << "Ket qua: " << result << endl;
        }
    }

    return 0;
}
