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

void NodeLeftRight(Node *t)
{
    if (t != nullptr)
    {
        cout << t->data << " ";
        NodeLeftRight(t->pLeft);
        NodeLeftRight(t->pRight);
    }
}

void LeftRightNode(Node *t)
{
    if (t != nullptr)
    {
        LeftRightNode(t->pLeft);
        LeftRightNode(t->pRight);
        cout << t->data << " ";
    }
}

void LeftNodeRight(Node *t)
{
    if (t != nullptr)
    {
        LeftNodeRight(t->pLeft);
        cout << t->data << " ";
        LeftNodeRight(t->pRight);
    }
}

Node *FindElement(Node *t, int x)
{
    if (t == nullptr)
    {
        return nullptr;
    }

    else
    {
        if (x < t->data)
        {
            return FindElement(t->pLeft, x);
        }
        else if (x > t->data)
        {
            return FindElement(t->pRight, x);
        }
        else
            return t;
    }
}

void FindNodeKill(Node *x, Node* y)
{
    if (y->pLeft != nullptr)
    {
        FindNodeKill(x, y->pLeft);
    }
    else
    {
        x->data = y->data;
        x = y;
        y = y->pRight;
    }
    
}

void DeleteNode(Node *&t, int data)
{
    if (t == nullptr)
    {
        return;
    }
    else
    {
        if (data < t->data)
        {
            DeleteNode(t->pLeft, data);
        }
        else if (data > t->data)
        {
            DeleteNode(t->pRight, data);
        }
        else
        {
            Node *x = t;
            if (t->pLeft == nullptr)
            {
                t = t->pRight;
            }
            else if (t->pRight == nullptr)
            {
                t = t->pLeft;
            }
            else
            {
                FindNodeKill(x, t->pRight);
            }
            delete x;
        }
    }
}

void OutputAfterDelete(Node *t)
{
    if (t != nullptr)
    {
        cout << t->data << " ";
        OutputAfterDelete(t->pLeft);
        OutputAfterDelete(t->pRight);
    }
}

void Output(Node *t, vector<int> &arr, int n)
{
    cout << "Ket qua node - left - right : ";
    NodeLeftRight(t);
    cout << endl;

    cout << "Ket qua left - right - node : ";
    LeftRightNode(t);
    cout << endl;

    cout << "Ket qua left - node - right : ";
    LeftNodeRight(t);
    cout << endl;

    int x;
    cout << "Nhap vao phan tu can tim : ";
    cin >> x;

    if (t == nullptr)
    {
        cout << "Khong tim thay phan tu " << x;
    }
    else
    {
        cout << "Tim thay phan tu " << x;
    }
    cout << endl;

    int k;
    cout << "Nhap vao so phan tu can xoa : ";
    cin >> k;
    vector<int> a(k);
    for (int i = 0; i < k; i++)
    {
        cin >> a[i];
        DeleteNode(t, a[i]);
    }
    cout << "Ket qua node sau khi xoa : ";
    OutputAfterDelete(t);
    cout << endl;
}

int main()
{
    Node *t;
    createNode(t);

    int n;
    cout << "Nhap vao kich thuoc mang : ";
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