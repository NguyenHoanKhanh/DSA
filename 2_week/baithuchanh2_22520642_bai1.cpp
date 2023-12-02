#include <iostream>
#include <vector>
using namespace std;

void Selection_sort(vector<int>&arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
    
}

int main()
{
    int n;
    cout<<"Nhap vao kich thuc mang : ";
    cin>>n;

    vector<int>arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    Selection_sort(arr,n);

    cout<<"Mang sau khi sap xep la : ";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}