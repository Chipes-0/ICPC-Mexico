/*
PROBLEM: https://codeforces.com/gym/106540/problem/D
TIME_COMPLEXITY: O(N)
SPACE_COMPLEXITY: O(1)

INPUT:
Test case 1:
1
0 0 5
0 0 3
10

OUTPUT:
YES

Test case 2:
1
0 0 3
10 0 3
7

OUTPUT:
NO

test case 3:
1
0 0 5
4 0 5
12

OUTPUT:
YES
*/

#include <bits/stdc++.h>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    while(N--){
        float x1, x2, y1, y2, r1, r2;
        cin >> x1 >> y1 >> r1;
        cin >> x2 >> y2 >> r2;
        float k;
        cin >> k;

        float d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        float maxV = max(r1, r2) * 2;
        if (d <= r1 + r2){
            maxV = max(maxV, r1 + d + r2);
        }

        if (maxV >= k) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    return 0;
}