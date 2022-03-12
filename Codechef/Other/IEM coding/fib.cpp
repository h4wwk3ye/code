#include <bits/stdc++.h>

using namespace std;

const int MAX = 5;
const int MODULO = 1e9+7;

struct matrix{
    int rowSize = MAX - 1;
    int columnSize = MAX - 1;
    int data[MAX][MAX];
    matrix () {
        for (int i = 1; i <= rowSize; i ++) {
            for (int j = 1; j <= columnSize; j ++) {
                data[i][j] = 0;
            }
        }
    }
    matrix operator * (const matrix other) const{
        matrix result = matrix();
        for (int i = 1; i <= rowSize; i ++) {
            for (int j = 1; j <= other.columnSize; j ++) {
                for (int k = 1; k <= columnSize; k ++) {
                    result.data[i][j] = (result.data[i][j] + 1LL * data[i][k] * other.data[k][j] % MODULO) % MODULO;
                }
            }
        }
        result.rowSize = rowSize;
        result.columnSize = other.columnSize;
        return result;
    }
    matrix power(int e) {
        if (e == 1) {
            return *this;
        }
        if (e & 1) {
            return (*this) * power(e - 1);
        }
        matrix half = power(e >> 1);
        return half * half;
    }
};

int T, N, K;
int b[MAX], c[MAX];

int main() {
    cin >> T;
    for (int cases = 0; cases < T; cases ++) {
        K=5;
        for (int i = 1; i <= 4; i ++) {
            b[i] = i;
        }
        for (int i = 1; i <= K; i ++) {
            cin >> c[i];
        }
        cin >> N;
        if (N <= 4) {
            cout << b[N] << "\n";
            continue;
        }
        
        matrix t, I;
        t.rowSize = K;
        t.columnSize = K;
        for (int i = 2; i <= K; i ++) {
            t.data[i - 1][i] = 1;
        }
        for (int i = 1; i <= K; i ++) {
            t.data[K][i] = c[K - i + 1];
        }
        I.rowSize = K;
        I.columnSize = 1;
        for (int i = 1; i <= 4; i ++) {
            I.data[i][1] = b[i];
        }
        I.data[5][1] = c[5];
        matrix result = t.power(N - K) * I;
        // cout << result.data[K][1] << endl;
    }
    
    return 0;
}