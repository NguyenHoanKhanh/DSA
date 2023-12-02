#include <iostream>
using namespace std;

void linearsort(int n, int arr[], int find)
{
    bool check = false;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == find)
        {
            cout<<"Phan tu "<<find<<" duoc tim thay o : "<<i+1;
        }
    }

    if (check == false)
    {
        cout<<"Khong tim duoc phan tu !";
    }    

}
int main()
{
    int n;
    cout<<"Nhap vao kich thuoc mang : ";
    cin>>n;

    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    int find;
    cout<<"nhap vao gia tri can tim trong mang : ";
    cin>>find;

    linearsort(n, arr, find);

    return 0;
}