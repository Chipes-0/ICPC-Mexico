/*
PROBLEM: https://codeforces.com/gym/106495/problem/A
TIME_COMPLEXITY: O(N + M)
SPACE_COMPLEXITY: O(1)

INPUT:
Test case 1:
5 4
180 250 120 300 150
200 180 150 220

OUTPUT:
NO

Test case 2:
4 5
200 350 250 200
220 210 200 190 230

OUTPUT:
NO

Test case 3:
3 3
300 350 250
350 400 260

OUTPUT:
YES
*/

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