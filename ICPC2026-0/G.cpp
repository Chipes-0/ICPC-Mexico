// https://codeforces.com/gym/104990/problem/G

#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M;
    int num;
    cin >> N >> M;
    vector<vector<int>> points;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> num;
            if (num == 1){
                points.push_back({i, j});
            }
        }
    }

    if (points.size() > 0){
        sort(points.begin(), points.end(), [](vector<int> a, vector<int> b){
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });

        vector<int> pos(points.size());
        for (int i = 0; i < points.size(); i++){
            pos[i] = points[i][1];
        }

        vector<int> lds(points.size(), 1);
        for (int i = 1; i < points.size(); i++){
            for (int j = 0; j < i; j++){
                if (pos[i] < pos[j]){
                    lds[i] = max(lds[i], lds[j] + 1);
                }
            }
        }

        cout << *max_element(lds.begin(), lds.end()) << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}