#include<string>
#include<vector>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int ans = 1;

void dfs(int start_x, int start_y, int x, int y, int cnt, vector<string> places) {
	if(cnt != 0 && start_x == x && start_y == y) {
		return;
	}
	
	if(cnt == 3) {
		return;
	}
	
	if(cnt != 0 && places[x][y] == 'P') {
		ans = 0;
	}
	
	for(int i = 0; i < 4; i++) {
		if(x + dx[i] >= 0 && y + dy[i] >= 0 && x + dx[i] < 5 && y + dy[i] < 5) {
			if(places[x + dx[i]][y + dy[i]] != 'X') {
				dfs(start_x, start_y, x + dx[i], y + dy[i], cnt + 1, places);
			}
		}
	}
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(int i = 0; i < 5; i++) {
    	for(int j = 0; j < 5; j++) {
    		for(int k = 0; k < 5; k++) {
    			if(places[i][j][k] == 'P') {
    				dfs(j, k, j, k, 0, places[i]);
				}
			}
		}
		
		answer.push_back(ans);
		ans = 1;
	}
    
    return answer;
}