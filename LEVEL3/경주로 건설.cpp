#include<string>
#include<vector>
using namespace std;

int answer = 987654321;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
bool visited[26][26];

void dfs(vector<vector<int>> board, int n, int x, int y, int cost, int head) {
    if(x == n - 1 && y == n - 1) {
        if(cost < answer) {
            answer = cost;
            
            return;
        }
    }
    
    for(int i = 0; i < 4; i++) {
        if(x + dx[i] >= 0 && y + dy[i] >= 0 && x + dx[i] < n && y + dy[i] < n) {
            if(board[x + dx[i]][y + dy[i]] == 0 && !visited[x + dx[i]][y + dy[i]]) {
                visited[x + dx[i]][y + dy[i]] = true;
                
                if(i == head || (x == 0 && y == 0)) {
                    dfs(board, n, x + dx[i], y + dy[i], cost + 100, i);
                }
                
                else {
                    dfs(board, n, x + dx[i], y + dy[i], cost + 600, i);
                }
                
                visited[x + dx[i]][y + dy[i]] = false;
            }
        }
    }
} 

int solution(vector<vector<int>> board) {
    int n = board.size();
    visited[0][0] = true;
    dfs(board, n, 0, 0, 0, 0);
    
    return answer;
}