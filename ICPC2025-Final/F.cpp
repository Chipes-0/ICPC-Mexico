/*
PROBLEM: https://codeforces.com/gym/106178/problem/F
TIME_COMPLEXITY: O(sqrt(N))
SPACE_COMPLEXITY: O(K)

INPUT:
Test case 1:
520

OUTPUT:
3
2 3
5 1
13 1

Test case 2:
1073741825

OUTPUT:
5
5 2
13 1
41 1
61 1
1321 1

*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    long long num = stoll(s.substr(0, 10));
    int len = s.size();
    map<ll, int> count;

    for (int i = 0; i < len - 10; i++){
        count[2]++;
        count[5]++;
    }

    for (ll primo = 2; primo * primo <= num; primo++) {
        while (num % primo == 0) {
            count[primo]++;
            num /= primo;
        }
    }
    if (num > 1) {
        count[num]++;
    }

    cout << count.size() << "\n";
    for (auto iterator : count) {
        cout << iterator.first << " " << iterator.second << "\n";
    }

    return 0;
}