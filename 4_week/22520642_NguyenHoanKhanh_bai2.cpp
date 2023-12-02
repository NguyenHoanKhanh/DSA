#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *pLeft;
    Node *pRight;
};

void createNode(Node *&t)
{
    t = nullptr;
}

void AddNodeToTree(Node *&t, int x)
{
    if (t == nullptr)
    {
        Node *p = new Node;
        p->data = x;
        p->pLeft = nullptr;
        p->pRight = nullptr;
        t = p;
    }

    else
    {
        if (x < t->data)
        {
            AddNodeToTree(t->pLeft, x);
        }
        else if (x > t->data)
        {
            AddNodeToTree(t->pRight, x);
        }
    }
}

void Input(Node *t, vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

int HeightOfTree(Node *t)
{
    if (t == nullptr)
    {
        return 0;
    }

    else
    {
        int heightleft = HeightOfTree(t->pLeft);
        int heightright = HeightOfTree(t->pRight);

        return 1 + max(heightleft, heightright);
    }
}

void Output(Node *t, vector<int> &arr, int n)
{
    int height = HeightOfTree(t);
    cout << "Chieu cao cua cay la : " << height - 1;
}

int main()
{
    Node *t;
    createNode(t);

    int n;
    cout << "Nhap vao kich thuoc mang chuyen thanh cay : ";
    cin >> n;

    vector<int> arr(n);
    Input(t, arr, n);
    for (int i = 0; i < n; i++)
    {
        AddNodeToTree(t, arr[i]);
    }

    Output(t, arr, n);
    delete[] &arr;
    return 0;
}