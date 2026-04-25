// https://codeforces.com/gym/106495/problem/A

#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    int sum1 = 0, sum2 = 0;
    int num;
    for (int i = 0; i < N; i++) {
        cin >> num;
        sum1 += num;
    }
    for (int i = 0; i < M; i++) {
        cin >> num;
        sum2 += num;
    }

    if (sum2 >= sum1 * 1.1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}