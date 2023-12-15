#include <bits/stdc++.h>
using namespace std;

void linearsort(int n, vector<int>&a, int find)
{
    bool check = false;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == find)
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

    vector<int>a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    
    int find;
    cout<<"nhap vao gia tri can tim trong mang : ";
    cin>>find;

    linearsort(n, a, find);

    return 0;
}