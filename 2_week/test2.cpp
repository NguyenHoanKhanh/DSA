#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int>s;
    int x;
    cin>>x;
    while (x > 0)
    {
        int temp = x % 2;
        s.push(temp);
        x /= 2;
    }
    
    while (!s.empty())
    {
        cout<<s.top();
        s.pop();
    }
    return 0;
}