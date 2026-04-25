// https://codeforces.com/gym/106495/problem/E

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