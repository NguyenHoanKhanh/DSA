#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int itemCode;
    Node *next;
};

void InitHashTable(Node* &HT, int n)
{
    HT = new Node[n];
    for (int i = 0; i < n; i++)
    {
        HT[i].next = nullptr;
    }
}

int Hash(int itemCode, int n)
{
    return itemCode % n;
}

void AddTail(Node *&l, int itemCode)
{
    Node *temp = new Node{itemCode, nullptr};
    if (l == nullptr)
    {
        l = temp;
    }
    else
    {
        Node *p = l;
        while (p->next != nullptr)
        {
            p = p->next;
        }
        p->next = temp;
    }
}

void Insert(Node* &HT, int itemCode, int n)
{
    int i = Hash(itemCode, n);
    AddTail(HT[i].next, itemCode);
}

int CountUniqueItems(Node* &HT, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        Node *p = HT[i].next; // Skip the dummy node
        while (p != nullptr)
        {
            count++;
            p = p->next;
        }
    }
    return count;
}

void CountColors(int n, vector<int> &colors, Node* &colorCount)
{
    for (int i = 0; i < n; ++i)
    {
        int color = colors[i];
        int hashValue = Hash(color, n);
        AddTail(colorCount[hashValue].next, color);
    }
}

vector<int> ChooseFlowerColors(int k, Node* &colorCount, int n)
{
    vector<int> result;
    vector<pair<int, int>> colorFrequency;

    for (int i = 0; i < n; ++i)
    {
        Node *p = colorCount[i].next; // Skip the dummy node
        while (p != nullptr)
        {
            colorFrequency.push_back({p->itemCode, 0});
            p = p->next;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        Node *p = colorCount[i].next; // Skip the dummy node
        while (p != nullptr)
        {
            auto it = find_if(colorFrequency.begin(), colorFrequency.end(), [p](const pair<int, int> &element)
                              { return element.first == p->itemCode; });

            if (it != colorFrequency.end())
            {
                it->second++;
            }

            p = p->next;
        }
    }

    sort(colorFrequency.begin(), colorFrequency.end(),
         [](const pair<int, int> &a, const pair<int, int> &b)
         {
             return a.second > b.second;
         });

    for (int i = 0; i < k; ++i)
    {
        result.push_back(colorFrequency[i].first);
    }

    sort(result.begin(), result.end());

    return result;
}

int main()
{
    Node *HT;
    int n, k;
    cin >> n >> k;

    InitHashTable(HT, n);

    vector<int> colors(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> colors[i];
        Insert(HT, colors[i], n);
    }

    vector<int> result = ChooseFlowerColors(k, HT, n);

    for (int i = 0; i < k; ++i)
    {
        cout << result[i] << " ";
    }

    delete[] HT; // Don't forget to free memory
    return 0;
}
