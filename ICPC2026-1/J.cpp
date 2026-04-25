/*
PROBLEM: https://codeforces.com/gym/106495/problem/J
TIME_COMPLEXITY: O(N)
SPACE_COMPLEXITY: O(1)

INPUT:
Test case 1:
3
3
4
7

OUTPUT:
3

Test case 2:
2
100
1000

OUTPUT:
80850
83083500

test case 3:
1
3

OUTPUT:
1
*/

#include <bits/stdc++.h>

using namespace std;

int modulo = 1e9 + 7;

int comb(int n, int k){
    int m = max(k, n - k);
    long long res = 1;
    for (int i = n, j = 1; i > m; i--, j++){
        res = (res * i);
        res = res /= j;
    }
    return res % modulo;
}

int main(){
    int N;
    long long num;
    cin >> N;
    while (N--){
        cin >> num;
        long long evens = num / 2;
        long long odds = num - evens;
        long long res = 0;

        if (evens >= 3){
            res += comb(evens, 3) % modulo;
        }
        if (odds >= 2 && evens >= 1){
            res += (comb(odds, 2) * evens) % modulo;
        }

        cout << res % modulo << endl;
    }
    return 0;
}