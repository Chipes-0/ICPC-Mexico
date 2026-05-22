/*
PROBLEM: https://codeforces.com/gym/106540/problem/G
TIME_COMPLEXITY: O(M + N log N)
SPACE_COMPLEXITY: O(N)

INPUT:
Test case 1:
5 3
0 1
1 2
3 4

OUTPUT:
2
2 4
1 3

*/

#include <bits/stdc++.h>
#include <numeric>
using namespace std;

class DSU {

    public:
        vector<int> parent, sz;

        DSU(int n) {
            parent.resize(n);
            sz.resize(n, 1);

            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        int find(int x) {
            if (parent[x] == x)
                return x;

            return parent[x] = find(parent[x]);
        }

        // Union by size
        bool unite(int a, int b) {
            a = find(a);
            b = find(b);

            if (a == b)
                return false;

            if (sz[a] < sz[b])
                swap(a, b);

            parent[b] = a;
            sz[a] += sz[b];

            return true;
        }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K;
    cin >> N >> K;
    // Formar DSU
    DSU dsu = DSU(N);
    for (int i = 0; i < K; i++){
        int a, b;
        cin >> a >> b;
        dsu.unite(a, b);
    }

    // Hacer un mapa con los grupos
    unordered_map<int, deque<int>> groups;
    for (int i = 0; i < dsu.parent.size(); i++){
        groups[dsu.find(i)].push_back(i);
    }
    
    // Heap de tamaño del grupo
    priority_queue<pair<int,int>> pq;
    for (auto &[leader, dq] : groups) {
        pq.push({dq.size(), leader});
    }

    // Sacar 1 de cada uno de los 2 grupos más grandes 
    vector<pair<int, int>> ans;
    while (pq.size() >= 2) {
        auto [sz1, g1] = pq.top();
        pq.pop();

        auto [sz2, g2] = pq.top();
        pq.pop();

        int a = groups[g1].front();
        groups[g1].pop_front();

        int b = groups[g2].front();
        groups[g2].pop_front();

        ans.push_back({a, b});

        if (!groups[g1].empty()) {
            pq.push({groups[g1].size(), g1});
        }

        if (!groups[g2].empty()) {
            pq.push({groups[g2].size(), g2});
        }
    }
    cout << ans.size() << "\n";
    for (auto &[a, b] : ans){
        cout << a << " " << b << "\n";
    }
    
    return 0;
}