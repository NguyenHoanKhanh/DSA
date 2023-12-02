#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void binarysearch(const vector<int> &arr, int n, int find, const vector<int> &a)
{
    for (int j = 0; j < find; j++)
    {
        int mid;
        int left = 0;
        int right = n - 1;
        int tg = a[j];
        bool check = false;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (arr[mid] == tg)
            {
                check = true;
                break;
            }
            else if (arr[mid] < tg)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        if (check)
        {
            cout << "So thu " << j + 1 << " : YES!!!!"<<endl;
        }
        else
            cout << "So thu " << j + 1 << " : NO!!!";
    }
}

int main()
{
    int n;
    cout << "Nhap vao kich thuoc mang : ";
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int find;
    cout << "Nhap vao kich thuoc mang gia tri can tim : ";
    cin >> find;

    vector<int> a(find);
    for (int i = 0; i < find; i++)
    {
        cin >> a[i];
    }

    binarysearch(arr, n, find, a);

    return 0;
}
