#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct LinkedList
{
    Node *head;
    Node *tail;
};

Node *createNode(int x)
{
    Node *node = new Node;
    node->data = x;
    node->next = nullptr;
    return node;
}

void createList(LinkedList &l)
{
    l.head = nullptr;
    l.tail = nullptr;
}

void addNode(LinkedList &l, int x)
{
    Node *newnode = createNode(x);
    if (l.head == nullptr)
    {
        l.head = newnode;
        l.tail = newnode;
    }

    else
    {
        l.tail->next = newnode;
        l.tail = newnode;
    }
}

void Input(LinkedList &l, int n)
{
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        addNode(l, x);
    }
}

void reverseLinkedlist(LinkedList &l)
{
    Node *prev = nullptr;
    Node *current = l.head;
    Node *next = nullptr;

    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;

        prev = current;
        current = next;
    }

    l.tail = l.head;
    l.head = prev;
}

void Output(LinkedList &l)
{
    Node* list = l.head;
    while (list != nullptr)
    {
        cout<<list->data<<" ";
        list = list->next;
    }
    
}
int main()
{
    int n;
    cout << "Nhap vao so luong phan tu : " << endl;
    cin >> n;

    LinkedList mylist;
    createList(mylist);

    Input(mylist, n);
    reverseLinkedlist(mylist);

    cout<<"Danh sach sau khi dao nguoc la : ";
    Output(mylist);

    return 0;

    
}