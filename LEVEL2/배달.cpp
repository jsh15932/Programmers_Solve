#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int INF = 987654321;
vector<pair<int, int>> vc[51];
priority_queue<pair<int, int>> pq;
int dp[51];

void dijkstra(int start) {
    dp[start] = 0;
    pq.push(make_pair(start, 0));
    
    while(!pq.empty()) {
        int cur = pq.top().first;
        int cost = -pq.top().second;
        pq.pop();
        
        for(int i = 0; i < vc[cur].size(); i++) {
            int next = vc[cur][i].first;
            int next_cost = cost + vc[cur][i].second;
            
            if(dp[next] > next_cost) {
                dp[next] = next_cost;
                pq.push(make_pair(next, -next_cost));
            }
        }
    }
}


int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    
    for(int i = 1; i <= N; i++) {
        dp[i] = INF;
    }
    
    for(int i = 0; i < road.size(); i++) {
        int a = road[i][0];
        int b = road[i][1];
        int c = road[i][2];
        
        vc[a].push_back(make_pair(b, c));
        vc[b].push_back(make_pair(a, c));
    }
    
    dijkstra(1);

    for(int i = 1; i <= N; i++) {
        if(dp[i] <= K) {
            answer++;
        }
    }
    
    return answer;
}