#include<string>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    int visited[11][11][4] = {0};
    int x = 5, y = 5;
    
    for(int i = 0; i < dirs.size(); i++) {
        if(dirs[i] == 'U') {
            if(y + 1 > 10) {
                continue;
            }
            
            if(visited[x][y][0] == 0 && visited[x][y + 1][1] == 0) {
                visited[x][y][0] = 1;
                visited[x][y + 1][1] = 1;
                answer++;
            }
            
            y++;
        }
        
        else if(dirs[i] == 'D') {
            if(y - 1 < 0) {
                continue;
            }
            
            if(visited[x][y][1] == 0 && visited[x][y - 1][0] == 0) {
                visited[x][y][1] = 1;
                visited[x][y - 1][0] = 1;
                answer++;
            }
            
            y--;
        }
        
        else if(dirs[i] == 'L') {
            if(x - 1 < 0) {
                continue;
            }
            
            if(visited[x][y][2] == 0 && visited[x - 1][y][3] == 0) {
                visited[x][y][2] = 1;
                visited[x - 1][y][3] = 1;
                answer++;
            }
            
            x--;
        }
        
        else if(dirs[i] == 'R') {
            if(x + 1 > 10) {
                continue;
            }
            
            if(visited[x][y][3] == 0 && visited[x + 1][y][2] == 0) {
                visited[x][y][3] = 1;
                visited[x + 1][y][2] = 1;
                answer++;
            }
            
            x++;
        }
    }
    
    return answer;
}