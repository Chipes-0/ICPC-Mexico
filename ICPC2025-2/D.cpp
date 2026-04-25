// https://codeforces.com/gym/105979/problem/D

#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;
vector<int> high;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    parent = vector<int>(N, 0);
    high = vector<int>(N, 0);

    

    return 0;
}



void makeSet(int x) {
    parent[x] = x;
    high[x] = 0;
}

void link(int x, int y) {
    if (high[x] > high[y]) {
        parent[y] = x;
    } else {
        parent[x] = y;
        if (high[x] == high[y]) {
        high[y]++;
        }
    }
}

int findSet(int x) {
    while (x != parent[x]) {
        x = parent[x];
    }
    return x;
}

void unionSet(int x, int y) { 
    link(findSet(x), findSet(y)); 
}