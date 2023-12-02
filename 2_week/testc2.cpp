#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n;
    stack<int> s;
    
    cout << "Nhap vao so nguyen n : ";
    cin >> n;
    
    while (n % 10 != 0)
    {
        int a;
        a = n % 10;
        n /= 10;
        s.push(a);
        cout<<s.top();
 
    }
    
    
    
    return 0;
}
