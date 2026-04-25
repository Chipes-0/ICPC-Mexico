// https://codeforces.com/gym/104990/problem/A

#include <bits/stdc++.h>

using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    int deptos = 1;
    int dinero = 0;
    int meses = 0;
    int nuevos = 0;
    while (deptos < C){
        dinero += deptos * B;
        nuevos = dinero / A;
        deptos += nuevos;
        dinero -= nuevos * A;
        meses++;
    }
    cout << meses << endl;
    return 0;
};