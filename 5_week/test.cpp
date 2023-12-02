#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Node
{
    string id;
    Node* next;
};

// Hàm hash function
size_t customHash(const string& id) {
    size_t hash = 0;
    for (char c : id) {
        hash = hash * 31 + c;  // Sử dụng phép toán để tạo hash
    }
    return hash;
}

// Hàm chèn vào hash table
void insert(string id, vector<Node*>& hash_table, int N)
{
    size_t index = customHash(id) % N;
    Node* temp = new Node;
    temp->id = id;
    temp->next = nullptr;
    Node* curr = hash_table[index];

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

// Hàm kiểm tra sự tồn tại của id trong hash table
bool check(string id, vector<Node*>& hash_table, int N)
{
    size_t index = customHash(id) % N;
    Node* curr = hash_table[index];

    while (curr)
    {
        if (curr->id == id)
        {
            return true;
        }
        curr = curr->next;
    }
    return false;
}

// Hàm đếm số loại hàng khác nhau
int countDistinctIds(vector<Node*>& hash_table, int N)
{
    int count = 0;

    for (int i = 0; i < N; i++)
    {
        Node* curr = hash_table[i];

        while (curr)
        {
            if (!check(curr->id, hash_table, N))
            {
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

    vector<Node*> hash_table(N, nullptr);

    string id;
    for (int i = 0; i < N; i++)
    {
        cout << "Nhap vao id thu " << i + 1 << " : ";
        cin >> id;
        insert(id, hash_table, N);
    }

    int distinctCount = countDistinctIds(hash_table, N);

    cout << "So luong loai hang khac nhau la: " << distinctCount << endl;

    // Giải phóng bộ nhớ
    for (int i = 0; i < N; i++)
    {
        Node* curr = hash_table[i];
        while (curr)
        {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
    return 0;
}
