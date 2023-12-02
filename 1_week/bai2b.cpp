#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarysearch(const vector<int> &arr, int n, int find)
{
    int mid;
    int left = 0;
    int right = n - 1;
    while (left <= right)
    {
       mid = left + (right - left) / 2;
            if (arr[mid] == find)
            {
                return mid;
            }
            
            else if (arr[mid] < find)
            {
                left = mid + 1;
            }
            else right = mid - 1;
    }
    return -1 ; 
}

int main()
{
    int n;
    cout<<"Nhap vao kich thuoc mang : ";
    cin>>n;

    vector<int>arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    int find;
    cout<<"Nhap vao gia tri can tim : ";
    cin>>find;

    int result = binarysearch(arr, n,find);
    if (result != -1)
    {
        cout<<"Tim thay x! ";
    }
    else 
    {
        cout<<"Khong tim thay x !";
    }

    return 0;
}

