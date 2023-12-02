#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string mssv;
    string name;
    float point;
    Node *next;
};

struct LinkedList
{
    Node *head;
    Node *tail;
};

Node *createNode(string mssv, string name, float point)
{
    Node *node = new Node;
    node->mssv = mssv;
    node->name = name;
    node->point = point;
    node->next = nullptr;
    return node;
}

void createList(LinkedList &l)
{
    l.head = nullptr;
    l.tail = nullptr;
}

void addNode(LinkedList &l, string mssv, string name, float point)
{
    Node *newNode = createNode(mssv, name, point);

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

void inputStudents(LinkedList &l, int n)
{
    for (int i = 0; i < n; i++)
    {
        string mssv, name;
        float point;

        cout << "Nhap thong tin sinh vien thu " << i + 1 << ":" << endl;
        cout << "MSSV: ";
        cin >> mssv;
        cin.ignore(); // Để xử lý dấu Enter trong getline()
        cout << "Ten sinh vien: ";
        getline(cin, name);
        cout << "Diem trung binh: ";
        cin >> point;

        addNode(l, mssv, name, point);
    }
}

void addStudentToHead(LinkedList &l, string mssv, string name, float point)
{
    Node *newNode = createNode(mssv, name, point);

    if (l.head == nullptr)
    {
        l.head = newNode;
        l.tail = newNode;
    }
    else
    {
        newNode->next = l.head;
        l.head = newNode;
    }
}

Node *findStudent(LinkedList &l, string &mssv)
{
    Node *current = l.head;
    while (current != nullptr)
    {
        if (current->mssv == mssv)
        {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void deleteStudent(LinkedList &l, string &mssv)
{
    Node *current = l.head;
    Node *prev = nullptr;

    while (current != nullptr)
    {
        if (current->mssv == mssv)
        {
            if (prev != nullptr)
            {
                prev->next = current->next;
            }
            else
            {
                l.head = current->next;
            }

            if (current == l.tail)
            {
                l.tail = prev;
            }

            delete current;
            return;
        }

        prev = current;
        current = current->next;
    }
}

void outputStudents(LinkedList &l)
{
    Node *current = l.head;
    while (current != nullptr)
    {
        cout << "MSSV: " << current->mssv << endl;
        cout << "Ten: " << current->name << endl;
        cout << "Diem trung binh: " << current->point << endl;
        current = current->next;
    }
}

void outputStudentsWithPointGreaterThan(LinkedList &l, float a)
{
    Node *current = l.head;
    while (current != nullptr)
    {
        if (current->point > a)
        {
            cout << "MSSV: " << current->mssv << endl;
            cout << "Ten: " << current->name << endl;
            cout << "Diem trung binh: " << current->point << endl;
        }
        current = current->next;
    }
}

void sortByPoint(LinkedList &l)
{
    if (l.head == nullptr || l.head->next == nullptr)
    {
        return;
    }

    bool swapped;
    Node *current;
    Node *last = nullptr;

    do
    {
        swapped = false;
        current = l.head;

        while (current->next != last)
        {
            if (current->point > current->next->point)
            {
                swap(current->mssv, current->next->mssv);
                swap(current->name, current->next->name);
                swap(current->point, current->next->point);
                swapped = true;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
}

void classifyStudents(LinkedList& l)
{
    Node* current = l.head;
    while (current != nullptr)
    {
        string xeploai;
        if (current->point <= 3.6)
        {
            xeploai = "Loai yeu";
        }
        else if (current->point >= 5.0 && current->point < 6.5)
        {
            xeploai = "Loai trung binh";
        }
        else if (current->point >= 6.5 && current->point < 7.0)
        {
            xeploai = "Loai trung binh kha";
        }
        else if (current->point >= 7.0 && current->point < 8.0)
        {
            xeploai = "Loai kha";
        }
        else if (current->point >= 8.0 && current->point < 9.0)
        {
            xeploai = "Loai gioi";
        }
        else
        {
            xeploai = "Loai xuat sac";
        }
        cout << "MSSV: " << current->mssv << endl;
        cout << "Ten: " << current->name << endl;
        cout << "Diem trung binh: " << current->point << endl;
        cout << "Xep loai: " << xeploai << endl;
        current = current->next;
    }
}


int main()
{
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    LinkedList mylist;
    createList(mylist);
    inputStudents(mylist, n);

    string mssv, name;
    float point;

    cout << "Nhap thong tin sinh vien them vao: " << endl;
    cout << "MSSV: ";
    cin >> mssv;
    cin.ignore();
    cout << "Ten sinh vien: ";
    getline(cin, name);
    cout << "Diem trung binh: ";
    cin >> point;

    addStudentToHead(mylist, mssv, name, point);

    string mssv_find;
    cout << "Nhap MSSV cua sinh vien can tim: ";
    cin >> mssv_find;
    Node *foundStudent = findStudent(mylist, mssv_find);
    if (foundStudent != nullptr)
    {
        cout << "Sinh vien co trong danh sach!" << endl;
    }
    else
    {
        cout << "Khong tim thay sinh vien co MSSV " << mssv_find << endl;
    }

    cout << "Danh sach sinh vien sau khi them:" << endl;
    outputStudents(mylist);

    string mssv_del;
    cout << "Nhap MSSV cua sinh vien muon xoa: ";
    cin >> mssv_del;
    deleteStudent(mylist, mssv_del);

    cout << "Danh sach sinh vien sau khi xoa:" << endl;
    outputStudents(mylist);

    cout << "Sinh vien co diem trung binh lon hon 5:" << endl;
    outputStudentsWithPointGreaterThan(mylist, 5);

    sortByPoint(mylist);

    cout << "Danh sach sinh vien sau khi sap xep theo diem trung binh:" << endl;
    outputStudents(mylist);

    cout << "Danh sach sinh vien sau khi xep loai:" << endl;
    classifyStudents(mylist);

    return 0;
}
