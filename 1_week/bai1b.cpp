#include <iostream>
#include <vector>
using namespace std;

void linearsort(const vector<int> &arr, int n, int giatri)
{
    bool check = false;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == giatri)
        {
            cout<<"Phan tu "<< giatri <<" duoc tim thay o : "<<i + 1;
            check = true;
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

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    int giatri;
    cout<<"Nhap vao gia tri can tim : ";
    cin>>giatri;

    linearsort(arr, n, giatri);

    return 0;
}