#include<bits/stdc++.h>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

struct C {
    int x;
    int y;
    int cost;
    int dir;
};

int solution(vector<vector<int>> board) {
    int answer = 2e9;
    vector<vector<int>> vc;
    vc.resize(board.size(), vector<int>(board.size(), 2e9));
    queue<C> que;
    que.push({ 0, 0, 0, -1 });
    vc[0][0] = 0;

    while(!que.empty()) {
        int x = que.front().x;
        int y = que.front().y;
        int cost = que.front().cost;
        int dir = que.front().dir;
        que.pop();

        if(x == board.size() - 1 && y == board.size() - 1) {
            answer = min(answer, vc[x][y]);
            continue;
        }

        for(int i = 0; i < 4; i++) {
            int nextX = x + dx[i];
            int nextY = y + dy[i];

            if(nextX >= 0 && nextY >= 0 && nextX < board.size() && nextY < board.size()) {
                int nextCost = 0;
                
                if(board[nextX][nextY] == 1) {
                    continue;
                }
                
                if(dir == -1 || dir == i) {
                    nextCost = cost + 100;
                }
                else {
                    nextCost = cost + 600;
                }

                if(vc[nextX][nextY] >= nextCost) {
                    vc[nextX][nextY] = nextCost;
                    que.push({ nextX, nextY, nextCost, i });
                }
            }
        }
    }

    return answer;
}