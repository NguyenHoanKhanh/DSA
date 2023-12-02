#include <bits/stdc++.h>
using namespace std;

struct Node
{
    string username;
    string password;
    Node *next;
};

void insert(string username, string password, vector<Node *> &hash_table, int n)
{
    int index = hash<string>{}(username) % n;
    Node *temp = new Node;
    temp->password = password;
    temp->username = username;
    temp->next = nullptr;

    if (hash_table[index] == nullptr)
    {
        hash_table[index] = temp;
    }
    else
    {
        temp->next = hash_table[index];
        hash_table[index] = temp;
    }
}

void findPass(string username, vector<Node *> &hash_table, int n)
{
    int index = hash<string>{}(username) % n;
    Node *curr = hash_table[index];

    while (curr)
    {
        if (curr->username == username)
        {
            cout << curr->password << endl;
        }
        else
        {
            cout << "Chua dang ki!" << endl;
        }
        curr = curr->next;
    }
}

int main()
{
    int N, Q;
    cout << "Nhap vao so luong tai khoan va so lan dang nhap : ";
    cin >> N;
    cin >> Q;

    vector<Node *> hash_table(N, nullptr);

    for (int i = 0; i < N; i++)
    {
        string username, password;
        cout << "Nhap vao ten dang nhap va mat khau thu " << i + 1 << " : ";
        cin >> username;
        cin >> password;
        insert(username, password, hash_table, N);
    }

    for (int i = 0; i < Q; i++)
    {
        string username;
        cout << "Nhap vao ten dang nhap lan " << i + 1 << " : ";
        cin >> username;
        findPass(username, hash_table, N);
    }

    for (int i = 0; i < N; i++)
    {
        Node *curr = hash_table[i];
        while (curr)
        {
            Node *temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
    return 0;
}