#include <iostream>
using namespace std;

void swap(int a, int b)
{
    int temp = a;
    a = b;
    temp = b;  
}

void Interchancesort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i + 1] < arr[i])
        {
            swap(arr[i], arr[i + 1]);
        }
    }
}

int Binarysearch(int arr[], int n, int find)
{
    int left = 0;
    int right = n - 1;
    int mid;
    do
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

        else right = mid - 1 ;
    } while (left <= right);
    return -1 ;
}

int main()
{
    int n;
    cout<<"Nhap vao kich thuoc mang : ";
    cin>>n;

    int* arr= new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    int find;
    cout<<"Nhap vao so can tim : ";
    cin>>find;

    int result = Binarysearch(arr, n, find);

    if (result == -1)
    {
        cout<<"Khong tim duoc !";
    }
    else cout<<"Tim thay x";

    return 0;
    
}