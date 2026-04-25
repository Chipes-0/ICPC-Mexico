/*
PROBLEM: https://codeforces.com/gym/106495/problem/E
TIME_COMPLEXITY: O(NLogN)
SPACE_COMPLEXITY: O(N)

INPUT:
Test case 1:
10 10
1
2
3
4
5
6
7
8
9
10

OUTPUT:
1
2
4
8
6
10
3
9
5
7

Test case 2:
10 4
1
4
7
10

OUTPUT:
1
8
3
7

test case 3:
5 1
5

OUTPUT:
5
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> criba(int N){
    
}

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<vector<int>> factors(N + 1);

    vector<int> spf(N + 1); // smallest prime factor

    // Inicializar SPF
    for (int i = 1; i <= N; i++) spf[i] = i;

    for (int i = 2; i * i <= N; i++) {
        if (spf[i] == i) { // i es primo
            for (int j = i * i; j <= N; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }

    // Construir factorizaciones
    for (int i = 1; i <= N; i++) {
        int x = i;
        while (x > 1) {
            factors[i].push_back(spf[x]);
            x /= spf[x];
        }
    }

    factors[0] = vector<int>(1, 1);
    sort(factors.begin(), factors.end());
    int num;
    while (Q--){
        cin >> num;
        int prod = 1;
        for(int v: factors[num]){
            prod *= v;
        }
        cout << prod << endl;
    }

    return 0;
}