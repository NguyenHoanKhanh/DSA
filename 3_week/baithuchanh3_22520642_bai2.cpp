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
    Node *newNode = createNode(x);
    if (l.head == nullptr)
    {
        l.head = newNode;
        l.tail = newNode;
    }

    else
    {
        l.tail->next = newNode;
        l.tail = newNode;
    }
}

void Input(LinkedList &l, int n)
{
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        cout<<endl;
        
        addNode(l, x);
    }
    
}

void insertSort(LinkedList &l, int x)
{
    Node *list = createNode(x);
    if (!l.head || x < l.head->data)
    {
        list->next = l.head;
        l.head = list;
    }
    
    else
    {
        Node *current = l.head;
        while (current->next && current->next->data < x)
        {
            current = current->next;
        }
        list->next = current->next;
        current->next = list;
    }
}
void output(LinkedList &l)
{
    Node *list = l.head;
    while (list != nullptr)
    {
        cout<<list->data<<" ";
        list = list->next;
    }
    
}

int main()
{
    int n;
    cout<<"Nhap vao kich thuc n : ";
    cin>>n;

    LinkedList mylist;
    createList(mylist);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        insertSort(mylist, x);
    }
    
    int valuetoinsert ;
    cin>>valuetoinsert;
    insertSort(mylist, valuetoinsert);

    cout<<"Danh sach sau khi sap xep la : ";
    output(mylist);
}

