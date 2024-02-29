#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class UnionFind
{
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;

public:
    void makeSet(vector<int> nums)
    {
        for (int i : nums) // O(n)

        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int i) // O(logn)
    {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    void unionSet(int i, int j) // O(logn)
    {
        int parentI = find(i); // O(logn)
        int parentJ = find(j); // O(logn)
        if (parentI == parentJ)
            return;
        if (rank[parentI] > rank[parentJ])
        {
            parent[parentJ] = parentI;
        }
        else if (rank[parentI] < rank[parentJ])
        {
            parent[parentI] = parentJ;
        }
        else
        {
            parent[parentI] = parentJ;
            rank[parentJ]++;
        }
    }

    bool isSameSet(int i, int j) // O(logn)
    {
        return find(i) == find(j);
    }

    int numDisjointSets() // O(n)
    {
        int count = 0;
        for (auto i : parent)
        {
            if (i.first == i.second)
                count++;
        }
        return count;
    }

    int sizeOfSet(int i) // O(n)
    {
        int count = 0;
        for (auto j : parent)
        {
            if (find(j.first) == i)
                count++;
        }
        return count;
    }
};

int main()
{
    UnionFind u;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    u.makeSet(nums);
    u.unionSet(1, 2);
    u.unionSet(2, 3);
    u.unionSet(4, 5);
    u.unionSet(6, 7);
    cout << u.isSameSet(1, 3) << endl;   // 1
    cout << u.isSameSet(1, 2) << endl;   // 1
    cout << u.isSameSet(4, 7) << endl;   // 0
    cout << u.numDisjointSets() << endl; // 3
    cout << u.sizeOfSet(1) << endl;      // 3
    cout << u.sizeOfSet(4) << endl;      // 2
    return 0;
}