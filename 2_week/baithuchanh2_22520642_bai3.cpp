#include <iostream>
#include <vector>
using namespace std;

int Partition(vector<int>&arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void Quick_sort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivot = Partition(arr, low, high);
        Quick_sort(arr, low, pivot - 1);
        Quick_sort(arr, pivot + 1, high);
    }
    
}

int main()
{
    int n;
    cout << "Nhap vao kich thuc mang : ";
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Quick_sort(arr,0, n - 1);

    cout<<"Ket qua sap xep la : ";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}