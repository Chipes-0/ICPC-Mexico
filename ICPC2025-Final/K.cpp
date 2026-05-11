/*
PROBLEM: https://codeforces.com/gym/106178/problem/K
TIME_COMPLEXITY: O(N)
SPACE_COMPLEXITY: O(N)

INPUT:
Test case 1:
4 1
1 -1
-2 -1
0 -2
0 0

OUTPUT:
16

Test case 2:
2 3
1 1
-1 0

OUTPUT:
30

Test case 3:
2 99999
0 0
1 1

OUTPUT:
10000200001

*/


#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    int minR = 1e9, maxR = -1e9;
    int minC = 1e9, maxC = -1e9;
    vector<pair<int, int>> points(N);
    for (int i = 0; i < N; i++){
        int C, R;
        cin >> R >> C;
        minR = min(minR, R);
        maxR = max(maxR, R);
        minC = min(minC, C);
        maxC = max(maxC, C);
        points[i] = {R, C};
    }

    vector<pair<ll,ll>> dirs = {
            {-K, +K}, // up-right
            {-K, -K}, // up-left
            {+K, +K}, // down-right
            {+K, -K}  // down-left
    };

    ll wide = maxC - minC + 1;
    ll high = maxR - minR + 1;

    ll ans = wide * high; // caso donde no se mueve nadie

    // caso en el que puedo llegar a una esquina
    for (int i = 0; i < N; i++){
        int currR = points[i].first, currC = points[i].second;
        for (auto& dir : dirs){
            int newC = currC + dir.second;
            int newR = currR + dir.first;
            ll wideCurr = max(maxC, newC) - min(minC, newC) + 1;
            ll highCurr = max(maxR, newR) - min(minR, newR) + 1;
            ans = max(ans, wideCurr * highCurr);
        }
    }

    // caso en el que no puedo llegar a una esquina, aumento ancho y alto por separado
    for (int i = 0; i < K + 1; i++){
        ans = max(ans, (wide + i) * (high + K - i));
    }

    if (N == 1){
        ans = 1;
    }
    cout << ans << "\n";

    return 0;
}