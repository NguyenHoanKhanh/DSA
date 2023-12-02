#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point
{
    int x, y;
};
    
void Input(vector<Point> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<"Nhap vao gia tri x cho diem "<< i + 1 <<" : ";
        cin >> arr[i].x;
        cout<<"Nhap vao gia tri y cho diem "<< i + 1 <<" : ";
        cin >> arr[i].y;
    }
}

bool mycmp(const Point &u, const Point &v)
{
    if (u.x < v.x)
    {
        return true;
    }
    else if ((u.x == v.x))
    {
        return u.y > v.y;
    }
    return false;
}

int main ()
{
    int n;
    cout<<"Nhap vao kich thuoc mang point : ";
    cin>>n;
    
    vector<Point>arr(n);  
    Input(arr, n);
    sort(arr.begin(), arr.end(), mycmp);
    cout<<"Cac diem da duoc sap xep : "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout << "(" << arr[i].x << ", " << arr[i].y << ")" << endl;
    }
    
    return 0;
}