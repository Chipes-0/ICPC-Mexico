// https://codeforces.com/gym/106495/problem/I

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> valores(n);
    for(int i = 0; i < n; i++){
        cin >> valores[i];
    }

    string relieve;
    cin >> relieve;

    // comprimir el relieve
    string rel = "";
    vector<int> len;

    len.push_back(1);
    for(int i = 0; i < n - 1; i++){
        if(relieve[i] == '='){
            len.back()++;
        } else {
            rel += relieve[i];
            len.push_back(1);
        }
    }
    int compressN = len.size();
    vector<int> L(compressN, 1), R(compressN, 1);

    // calcular el relieve optimo
    for(int i = 0; i < compressN; i++){
        if (rel[i] == '<'){
            L[i + 1] = L[i] + 1;
        }
    }
    for(int i = compressN - 1; i >= 0; i--){
        if (rel[i] == '>'){
            R[i] = R[i + 1] + 1;
        }
    }
    vector<long long> res(compressN);
    for (int i = 0; i < compressN; i++){
        res[i] = max(L[i], R[i]);
    }

    // descomprimir el relieve
    vector <int> decompressed;
    for (int i = 0; i < compressN; i++) {
        for (int j = 0; j < len[i]; j++) {
            decompressed.push_back(res[i]);
        }
    }

    // calcular la respuesta
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += valores[i] * decompressed[i];
    }
    cout << ans << endl;
    // imprimir el relieve descomprimido
    for (int i = 0; i < n; i++) {
        cout << decompressed[i] << " ";
    }
    cout << endl;

    return 0;
}