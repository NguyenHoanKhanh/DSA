#include <bits/stdc++.h>
using namespace std;

struct Node
{
    string id;
    Node *next;
};

void insert(string id, vector<Node *> &hash_table, int N)
{
    int index = hash<string>{}(id) % N;
    Node *temp = new Node;
    temp->id = id;
    temp->next = nullptr;
    Node *curr = hash_table[index];

    if (curr == nullptr)
    {
        hash_table[index] = temp;
    }
    else
    {
        temp->next = hash_table[index];
        hash_table[index] = temp;
    }
}

int countId(const vector<Node *> &hash_table, int N)
{
    unordered_set<string> uniqueIds;
    int count = 0;

    for (int i = 0; i < N; i++)
    {
        Node *curr = hash_table[i];
        while (curr)
        {
            if (uniqueIds.find(curr->id) == uniqueIds.end())
            {
                uniqueIds.insert(curr->id);
                count++;
            }
            curr = curr->next;
        }
    }

    return count;
}

int main()
{
    int N;
    cout << "Nhap vao so luong id can check : ";
    cin >> N;

    vector<Node *> hash_table(N);

    string id;
    for (int i = 0; i < N; i++)
    {
        cout << "Nhap vao id thu " << i + 1 << " : ";
        cin >> id;
        insert(id, hash_table, N);
    }

    int COUNT = countId(hash_table, N);

    cout << COUNT;

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