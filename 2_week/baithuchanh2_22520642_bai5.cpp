#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int MEX(vector<int>&arr)
{
    sort(arr.begin(), arr.end());
    int mex = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == mex)
        {
            mex++;
        }
        else if (arr[i] > mex)
        {
            break;
        }
        
    }
    return mex;
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
    
    int value = MEX(arr);
    cout<<"Mex cua mang la : "<<value;
    
    return 0;
}