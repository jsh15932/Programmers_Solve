#include<bits/stdc++.h>
using namespace std;

int MOD = 20170805;

int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;

    vector<vector<vector<long long int>>> vc(m + 1, vector<vector<long long int>>(n + 1, vector<long long int>(2)));

    for(int i = 0; i < m; i++) {
        if(city_map[i][0] == 1) {
            break;
        }
        vc[i][0][1] = 1;
    }

    for(int i = 0; i < n; i++) {
        if(city_map[0][i] == 1) {
            break;
        }
        vc[0][i][0] = 1;
    }

    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            if(city_map[i - 1][j] == 0) {
                vc[i][j][1] += (vc[i - 1][j][0] + vc[i - 1][j][1]) % MOD;
            }

            if(city_map[i - 1][j] == 2) {
                vc[i][j][1] += (vc[i - 1][j][1] % MOD);
            }

            if(city_map[i][j - 1] == 0) {
                vc[i][j][0] += (vc[i][j - 1][0] + vc[i][j - 1][1]) % MOD;
            }

            if(city_map[i][j - 1] == 2) {
                vc[i][j][0] += (vc[i][j - 1][0] % MOD);
            }
        }
    }

    answer = (vc[m - 1][n - 1][0] + vc[m - 1][n - 1][1]) % MOD;

    return answer;
}