#include<bits/stdc++.h>
using namespace std;

int keyN;
int lockN;
int n;

void rotate(vector<vector<int>> &key) {
    vector<vector<int>> v(keyN, vector<int>(keyN));

    for(int i = keyN - 1; i >= 0; i--) {
        for(int j = 0; j < keyN; j++) {
            v[j][i] = key[keyN - i - 1][j];
        }
    }

    key = v;
}

bool in(int x, int y, vector<vector<int>> key, vector<vector<int>> board) {
    for(int i = x; i < x + keyN; i++) {
        for(int j = y; j < y + keyN; j++) {
            board[i][j] += key[i - x][j - y];
        }
    }

    for(int i = keyN - 1; i <= n - keyN; i++) {
        for(int j = keyN - 1; j <= n - keyN; j++) {
            if(board[i][j] == 1) {
                continue;;
            }

            return false;
        }
    }

    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;

    keyN = key.size();
    lockN = lock.size();
    n = lockN + (keyN - 1) * 2;
    vector<vector<int>> vc(n, vector<int>(n, 0));

    for(int i = keyN - 1; i <= n - keyN; i++) {
        for(int j = keyN - 1; j <= n - keyN; j++) {
            vc[i][j] = lock[i - keyN + 1][j - keyN + 1];
        }
    }

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j <= n - keyN; j++) {
            for(int k = 0; k <= n - keyN; k++) {
                if(in(j, k, key, vc)) {
                    answer = true;

                    return answer;
                }
            }
        }

        rotate(key);
    }

    return answer;
} 