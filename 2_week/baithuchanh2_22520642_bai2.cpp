#include <iostream>
using namespace std;

void Insertsort(int arr[], int n)
{
    int pos, i;
    int x;
    for (i = 0; i < n; i++)
    {
        x = arr[i];
        pos = i - 1;
        while ((pos >= 0) && arr[pos] > x)
        {
            arr[pos + 1] = arr[pos];
            pos--;
        }
        arr[pos + 1] = x;
    }
}  
int main()
{
    int n;
    cout << "Nhap vao so phan tu cua mang : ";
    cin >> n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap vao phan tu thu " << i + 1 << " : ";
        cin >> arr[i];
    }
    Insertsort(arr, n);
    cout << "Mang sau khi sap xep : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i]<<" ";
    }
    delete[] arr;
    return 0;
}