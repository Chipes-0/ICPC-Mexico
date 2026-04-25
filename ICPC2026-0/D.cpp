// https://codeforces.com/gym/104990/problem/D

#include <bits/stdc++.h>

using namespace std;

int main(){
    int H, M;
    int N;
    int X, Y;
    cin >> H >> M;
    cin >> N;
    int out = 0;
    int total = H * 60 + M;
    while (N--){
        if (total == 0) break;
        cin >> X >> Y;
        if (total - X >= 0){
            out += X * Y;
            total -= X;
        } else {
            out += total * Y;
            total = 0;
        }
    }
    cout << out << endl;
    return 0;
}

/*
     1  2  3
  1| 1  1  1
  2| 1  0  1
  3| 1  1  0
*/