// https://codeforces.com/gym/104990/problem/C

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define Matrix vector<vector<ll>>
ll MOD = 1e9 + 7;

// Multiplicación de matrices
Matrix multiply(Matrix &A, Matrix &B) {
    int n = A.size();
    Matrix C(n, vector<ll>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return C;
}

// Matriz identidad
Matrix identity_matrix(int n) {
    Matrix I(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++) I[i][i] = 1;
    return I;
}

// Exponenciación binaria
Matrix matrix_power(Matrix base, ll exp) {
    int n = base.size();
    Matrix result = identity_matrix(n);

    while (exp > 0) {
        if (exp & 1)
            result = multiply(result, base);

        base = multiply(base, base);
        exp >>= 1;
    }

    return result;
}


int main(){
    int N, M;
    cin >> N >> M;
    // Crear la matriz de coprimalidad base
    Matrix mat(M, vector<ll>(M, 0));
    for (int i = 0; i < M; i++){
        for (int j = 0; j < M; j++){
            if (__gcd(i + 1, j + 1) == 1){
                mat[i][j] = 1;
            }
        }
    }
    // Elevar la matriz a la potencia N-1
    Matrix result = matrix_power(mat, N - 1);
    // multiplicar la matriz resultante por un vector de unos para obtener el número de secuencias
    ll total = 0;
    for (int i = 0; i < M; i++){
        for (int j = 0; j < M; j++){
            total = (total + result[i][j]) % MOD;
        }
    }
    cout << total << endl;
    return 0;
}


