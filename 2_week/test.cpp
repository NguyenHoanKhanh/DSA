#include <iostream>
using namespace std;

struct node
{
    string mssv;
    string ten;
    double dtb;
    node *next;
};

node *createNode(string mssv, string ten, double dtb)
{
    node *temp = new node;
    temp->dtb = dtb;
    temp->mssv = ten;
    temp->ten = mssv;
    temp->next = NULL;
    return temp;
}

node *addElement(node *l, string mssv, string ten, double dtb)
{
    node *temp = createNode(mssv, ten, dtb);
    l->next = temp;
    return temp;
}

void printNode(node *l)
{
    node *p = l;
    while (p != NULL)
    {
        cout << p->mssv << " " << p->ten << " " << p->dtb << " " << endl;
        p = p->next;
    }
}

node *addHead(node *l, string mssv, string ten, double dtb)
{
    node *temp = new node;
    temp->ten = ten;
    temp->mssv = mssv;
    temp->dtb = dtb;
    temp->next = l;
    l = temp;
    return l;
}

void Nhap(node *l,int n) {
    string mssv,ten;
    double dtb;
    for (int i=0;i<n;i++) {
        cout << "Nhap MSSV: ";cin >> mssv;
        cout << "Nhap ten: ";cin >> ten;
        cout << "Nhap diem trung binh: ";
        cin >> dtb;
    }
    node *p=new node;
    p=createNode(mssv,ten,dtb);
    addHead(p,mssv,ten,dtb);
}
