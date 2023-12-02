#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct point
{
    int x, y, z;
};

void Input(vector<point>&arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<"Nhap vao toa do x thu "<<i + 1<<" : ";
        cin>>arr[i].x;
        cout<<"Nhap vao toa do y thu : "<<i + 1<<" : ";
        cin>>arr[i].y;
        cout<<"Nhap vao toa do z thu : "<<i + 1<<" : ";
        cin>>arr[i].z;
    }
}

bool mycmp(const point &u, const point &k)
{
    if (u.x < k.x)
    {
        return true;
    }

    else if (u.x == k.x)
    {
        return u.y > k.y;
    }
    
    else if ((u.x == k.x) && (u.y == k.y))
    {
        return u.z > k.z;
    }
    return false;
}

int main()
{
    int n;
    cout<<"Nhap vao kich thuoc mang : ";
    cin>>n;

    vector<point>arr(n);
    Input(arr,n);
    sort(arr.begin(), arr.end(), mycmp);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i].x<<" "<<arr[i].y<<" "<<arr[i].z<<endl;
    }
    
    return 0;
}